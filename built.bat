

set QWCL_C=client\cl_demo.c ^
client\cl_ents.c ^
client\cl_input.c ^
client\cl_main.c ^
client\cl_parse.c ^
client\cl_pred.c ^
client\cl_tent.c ^
client\cl_cam.c ^
client\cmd.c ^
client\common.c ^
client\console.c ^
client\crc.c ^
client\cvar.c ^
client\d_edge.c ^
client\d_fill.c ^
client\d_init.c ^
client\d_modech.c ^
client\d_part.c ^
client\d_polyse.c ^
client\d_scan.c ^
client\d_sky.c ^
client\d_sprite.c ^
client\d_surf.c ^
client\d_vars.c ^
client\d_zpoint.c ^
client\draw.c ^
client\keys.c ^
client\mathlib.c ^
client\md4.c ^
client\menu.c ^
client\model.c ^
client\net_chan.c ^
client\net_udp.c ^
client\nonintel.c ^
client\pmove.c ^
client\pmovetst.c ^
client\r_aclip.c ^
client\r_alias.c ^
client\r_bsp.c ^
client\r_draw.c ^
client\r_edge.c ^
client\r_efrag.c ^
client\r_light.c ^
client\r_main.c ^
client\r_misc.c ^
client\r_part.c ^
client\r_sky.c ^
client\r_sprite.c ^
client\r_surf.c ^
client\r_vars.c ^
client\sbar.c ^
client\screen.c ^
client\skin.c ^
client\snd_dma.c ^
client\snd_mem.c ^
client\snd_mix.c ^
client\view.c ^
client\wad.c ^
client\zone.c ^
client\cd_null.c ^
client\sys_emscripten.c ^
client\vid_sdl.c ^
client\in_null.c ^
client\snd_sdl.c

echo %QWCL_C%

del /F /Q .\build

if not exist build mkdir build

perl con_rel.pl %QWCL_C% > build\qwcl.c

C:\Users\taub\emsdk\upstream\emscripten\emcc -g -Dstricmp=strcasecmp -sUSE_SDL=2 -sINITIAL_MEMORY=45875200 -sSTACK_SIZE=16777216 build\qwcl.c -o build\qwcl.html --preload-file id1\ --preload-file qw\
