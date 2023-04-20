

#include "quakedef.h"
#include <emscripten.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>

#define stricmp=strcasecmp


/*
================
filelength
================
*/
int filelength (FILE *f)
{
	int		pos;
	int		end;

	pos = ftell (f);
	fseek (f, 0, SEEK_END);
	end = ftell (f);
	fseek (f, pos, SEEK_SET);

	return end;
}


int	Sys_FileTime (char *path)
{
	FILE	*f;
	
	f = fopen(path, "rb");
	if (f)
	{
		fclose(f);
		return 1;
	}
	
	return -1;
}

void Sys_mkdir (char *path)
{
	mkdir((const char*) path,  0777);
}


/*
===============================================================================

SYSTEM IO

===============================================================================
*/

void Sys_MakeCodeWriteable (unsigned long startaddr, unsigned long length)
{
}


void Sys_DebugLog(char *file, char *fmt, ...)
{
}

void Sys_Error (char *error, ...)
{
	va_list		argptr;

	printf ("I_Error: ");	
	va_start (argptr,error);
	vprintf (error,argptr);
	va_end (argptr);
	printf ("\n");

	exit (1);
}

void Sys_Printf (char *fmt, ...)
{
	va_list		argptr;
	
	va_start (argptr,fmt);
	vprintf (fmt,argptr);
	va_end (argptr);
}

void Sys_Quit (void)
{
	exit (0);
}

double Sys_FloatTime (void)
{
	static double t;
	
	t += 0.1;
	
	return t;
}

/*
================
Sys_DoubleTime
================
*/
double Sys_DoubleTime (void)
{
	struct timeval tp;
	struct timezone tzp;
	static int		secbase;

	gettimeofday(&tp, &tzp);
	
	if (!secbase)
	{
		secbase = tp.tv_sec;
		return tp.tv_usec/1000000.0;
	}
	
	return (tp.tv_sec - secbase) + tp.tv_usec/1000000.0;
}

char *Sys_ConsoleInput (void)
{
	return NULL;
}

void Sys_Sleep (void)
{
}



/*
void Sys_SendKeyEvents (void)
{
	if(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_KEYDOWN:
				Key_Event(event.key.keysym.sym,true);
				printf("pressed scan %d:%s sym %d:%s\n",
				event.key.keysym.scancode,
				SDL_GetScancodeName(event.key.keysym.scancode),
				event.key.keysym.sym,
				SDL_GetKeyName(event.key.keysym.sym));
			break;
			case SDL_KEYUP:
				Key_Event(event.key.keysym.sym,false);
			break;
			case SDL_MOUSEBUTTONDOWN:
				Key_Event(event.button.button, true);
			break;
			case SDL_MOUSEBUTTONUP:
				Key_Event(event.button.button, false);
			break;
		}
	}

}
*/

void Sys_HighFPPrecision (void)
{
}

void Sys_LowFPPrecision (void)
{
}

//=============================================================================




void
pseudo_main(){
	Host_Frame (0.01);
}



void main (int argc, char **argv)
{


	quakeparms_t	parms;

	parms.memsize = 5861376;
	parms.membase = malloc (parms.memsize);
	parms.basedir = ".";

	COM_InitArgv (argc, argv);

	parms.argc = com_argc;
	parms.argv = com_argv;

	printf ("Host_Init\n");
	Host_Init (&parms);

    emscripten_set_main_loop(pseudo_main, 1000, 1);
	
    // Clean up 
    SDL_Quit();
}



