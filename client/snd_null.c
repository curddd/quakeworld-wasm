#if 0
#include "sound.h";
void SNDDMA_Submit(void){};

//void S_Init (void){};
//void S_Startup (void){};;
//void S_Shutdown (void){};;
void S_StartSound (int entnum, int entchannel, sfx_t *sfx, vec3_t origin, float fvol,  float attenuation){};;
void S_StaticSound (sfx_t *sfx, vec3_t origin, float vol, float attenuation){};;
void S_StopSound (int entnum, int entchannel){};;
void S_StopAllSounds(qboolean clear){};;
//void S_ClearBuffer (void){};;
//void S_Update (vec3_t origin, vec3_t v_forward, vec3_t v_right, vec3_t v_up){};;
//void S_ExtraUpdate (void){};;
void S_LocalSound (char *s){};

sfx_t *S_PrecacheSound (char *sample){};
#endif
void SNDDMA_Submit(void){};
int SNDDMA_GetDMAPos(void){}