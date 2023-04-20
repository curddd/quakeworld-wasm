/*
Copyright (C) 1996-1997 Id Software, Inc.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

//
// these are the key numbers that should be passed to Key_Event
//
#include <SDL2/SDL.h>

#define	K_TAB			SDL_SCANCODE_KP_TAB
#define	K_ENTER			SDL_SCANCODE_RETURN
#define	K_ESCAPE		SDL_SCANCODE_ESCAPE
#define	K_SPACE			SDL_SCANCODE_SPACE

// normal keys should be passed as lowercased ascii

#define	K_BACKSPACE		SDL_SCANCODE_BACKSPACE
#define	K_UPARROW		SDL_SCANCODE_UP
#define	K_DOWNARROW		SDL_SCANCODE_DOWN
#define	K_LEFTARROW		SDL_SCANCODE_LEFT
#define	K_RIGHTARROW	SDL_SCANCODE_RIGHT

#define	K_ALT			SDL_SCANCODE_LALT
#define	K_CTRL			SDL_SCANCODE_LCTRL
#define	K_SHIFT			SDL_SCANCODE_LSHIFT
#define	K_F1			SDL_SCANCODE_F1
#define	K_F2			SDL_SCANCODE_F2
#define	K_F3			SDL_SCANCODE_F3
#define	K_F4			SDL_SCANCODE_F4
#define	K_F5			SDL_SCANCODE_F5
#define	K_F6			SDL_SCANCODE_F6
#define	K_F7			SDL_SCANCODE_F7
#define	K_F8			SDL_SCANCODE_F8
#define	K_F9			SDL_SCANCODE_F9
#define	K_F10			SDL_SCANCODE_F10
#define	K_F11			SDL_SCANCODE_F11
#define	K_F12			SDL_SCANCODE_F12
#define	K_INS			SDL_SCANCODE_INSERT
#define	K_DEL			SDL_SCANCODE_DELETE
#define	K_PGDN			SDL_SCANCODE_PAGEDOWN
#define	K_PGUP			SDL_SCANCODE_PAGEUP
#define	K_HOME			SDL_SCANCODE_HOME
#define	K_END			SDL_SCANCODE_END

#define K_PAUSE			SDL_SCANCODE_PAUSE

//
// mouse buttons generate virtual keys
//
#define	K_MOUSE1		SDL_BUTTON_LEFT
#define	K_MOUSE2		SDL_BUTTON_MIDDLE
#define	K_MOUSE3		SDL_BUTTON_RIGHT

//
// joystick buttons
//
#define	K_JOY1			203
#define	K_JOY2			204
#define	K_JOY3			205
#define	K_JOY4			206

//
// aux keys are for multi-buttoned joysticks to generate so they can use
// the normal binding process
//
#define	K_AUX1			207
#define	K_AUX2			208
#define	K_AUX3			209
#define	K_AUX4			210
#define	K_AUX5			211
#define	K_AUX6			212
#define	K_AUX7			213
#define	K_AUX8			214
#define	K_AUX9			215
#define	K_AUX10			216
#define	K_AUX11			217
#define	K_AUX12			218
#define	K_AUX13			219
#define	K_AUX14			220
#define	K_AUX15			221
#define	K_AUX16			222
#define	K_AUX17			223
#define	K_AUX18			224
#define	K_AUX19			225
#define	K_AUX20			226
#define	K_AUX21			227
#define	K_AUX22			228
#define	K_AUX23			229
#define	K_AUX24			230
#define	K_AUX25			231
#define	K_AUX26			232
#define	K_AUX27			233
#define	K_AUX28			234
#define	K_AUX29			235
#define	K_AUX30			236
#define	K_AUX31			237
#define	K_AUX32			238

// JACK: Intellimouse(c) Mouse Wheel Support

#define K_MWHEELUP		SDL_BUTTON_X1
#define K_MWHEELDOWN	SDL_BUTTON_X2



typedef enum {key_game, key_console, key_message, key_menu} keydest_t;

extern keydest_t	key_dest;
extern char *keybindings[256];
extern	int		key_repeats[256];
extern	int		key_count;			// incremented every key event
extern	int		key_lastpress;

extern char chat_buffer[];
extern	int chat_bufferlen;
extern	qboolean	chat_team;

void Key_Event (int key, qboolean down);
void Key_Init (void);
void Key_WriteBindings (FILE *f);
void Key_SetBinding (int keynum, char *binding);
void Key_ClearStates (void);

