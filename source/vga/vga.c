/*
THE COMPUTER CODE CONTAINED HEREIN IS THE SOLE PROPERTY OF PARALLAX
SOFTWARE CORPORATION ("PARALLAX").  PARALLAX, IN DISTRIBUTING THE CODE TO
END-USERS, AND SUBJECT TO ALL OF THE TERMS AND CONDITIONS HEREIN, GRANTS A
ROYALTY-FREE, PERPETUAL LICENSE TO SUCH END-USERS FOR USE BY SUCH END-USERS
IN USING, DISPLAYING,  AND CREATING DERIVATIVE WORKS THEREOF, SO LONG AS
SUCH USE, DISPLAY OR CREATION IS FOR NON-COMMERCIAL, ROYALTY OR REVENUE
FREE PURPOSES.  IN NO EVENT SHALL THE END-USER USE THE COMPUTER CODE
CONTAINED HEREIN FOR REVENUE-BEARING PURPOSES.  THE END-USER UNDERSTANDS
AND AGREES TO THE TERMS HEREIN AND ACCEPTS THE SAME BY USE OF THIS FILE.
COPYRIGHT 1993-1998 PARALLAX SOFTWARE CORPORATION.  ALL RIGHTS RESERVED.
*/
/*
 *
 * Graphical routines for setting video modes, etc.
 *
 */

#include <dos.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>

#include "types.h"
#include "mem.h"
#include "error.h"
#include "mono.h"
#include "gr.h"
#include "palette.h"
#include "grdef.h"

char vga_pal_default[768];

int vga_installed = 0;

ubyte * pVideoMode =  (volatile ubyte *)0x449;
ushort * pNumColumns = (volatile ushort *)0x44a;
ubyte * pNumRows = (volatile ubyte *)0x484;
ushort * pCharHeight = (volatile ushort *)0x485;
ushort * pCursorPos = (volatile ushort *)0x450;
ushort * pCursorType = (volatile ushort *)0x460;
ushort * pTextMemory = (volatile ushort *)0xb8000;

typedef struct screen_save {
	ubyte 	video_mode;
	ubyte 	is_graphics;
	ushort	char_height;
	ubyte		width;
	ubyte		height;
	ubyte		cursor_x, cursor_y;
	ubyte		cursor_sline, cursor_eline;
	ushort * video_memory;
} screen_save;

screen_save vga_saved_screen;

int vga_show_screen_info = 0;

//	VGA Functions --------------------------------------------------------------

void vga_set_cellheight( ubyte height )
{
	ubyte temp;

   outp( 0x3d4, 9 );
	temp = inp( 0x3d5 );
   temp &= 0xE0;
	temp |= height;
	outp( 0x3d5, temp );
}

void vga_set_linear()
{
	outpw( 0x3c4, 0xE04 );		  // enable chain4 mode
	outpw( 0x3d4, 0x4014 );		  // turn on dword mode
	outpw( 0x3d4, 0xa317 );		  // turn off byte mode
}

void vga_16_to_256()
{
	outpw( 0x3ce, 0x4005 );	 	// set Shift reg to 1

	inp( 0x3da );					// dummy input

	outp( 0x3c0, 0x30 );
	outp( 0x3c0, 0x61 );		   // turns on PCS & PCC

	inp( 0x3da );					// dummy input

	outp( 0x3c0, 0x33 );
	outp( 0x3c0, 0 );
}

void vga_turn_screen_off()
{
	ubyte temp;
	temp = inp( 0x3da );
	outp( 0x3c0, 0 );
}

void vga_turn_screen_on()
{
	ubyte temp;
	temp = inp( 0x3da );
	outp( 0x3c0, 0x20 );
}

void vga_set_misc_mode( uint mode )
{
	union REGS regs;

	memset( &regs, 0, sizeof(regs) );
	regs.w.ax = mode;
	int386( 0x10, &regs, &regs );

}

void vga_set_3dbios_mode( uint mode )
{
	union REGS regs;
	memset( &regs, 0, sizeof(regs) );
	regs.w.ax = 0x4fd0;
	regs.w.bx = 0x3d00 | (mode & 0xff);
	int386( 0x10, &regs, &regs );
}


void vga_set_text_25()
{
	union REGS regs;

	regs.w.ax = 3;
	int386( 0x10, &regs, &regs );

}

void vga_set_text_43()
{
	union REGS regs;

	regs.w.ax = 0x1201;
	regs.w.bx = 0x30;
	int386( 0x10, &regs, &regs );

	regs.w.ax = 3;
	int386( 0x10, &regs, &regs );

	regs.w.ax = 0x1112;
	regs.w.bx = 0x0;
	int386( 0x10, &regs, &regs );
}

void vga_set_text_50()
{
	union REGS regs;

	regs.w.ax = 0x1202;
	regs.w.bx = 0x30;
	int386( 0x10, &regs, &regs );

	regs.w.ax = 3;
	int386( 0x10, &regs, &regs );

	regs.w.ax = 0x1112;
	regs.w.bx = 0x0;
	int386( 0x10, &regs, &regs );
}

ubyte is_graphics_mode()
{
	byte tmp;
	tmp = inp( 0x3DA );		// Reset flip-flip
	outp( 0x3C0, 0x30 );		// Select attr register 10
	tmp = inp( 0x3C1 );	// Get graphics/text bit
	return tmp & 1;
}

int vga_save_mode()
{
	int i;

	vga_saved_screen.is_graphics = is_graphics_mode();
	vga_saved_screen.video_mode = *pVideoMode;

	if (!vga_saved_screen.is_graphics)	{
		vga_saved_screen.width = *pNumColumns;
		vga_saved_screen.height = *pNumRows+1;
		vga_saved_screen.char_height = *pCharHeight;
		vga_getcursor(&vga_saved_screen.cursor_x, &vga_saved_screen.cursor_y, &vga_saved_screen.cursor_sline, &vga_saved_screen.cursor_eline );
		MALLOC(vga_saved_screen.video_memory,ushort, vga_saved_screen.width*vga_saved_screen.height );
		for (i=0; i < vga_saved_screen.width*vga_saved_screen.height; i++ )
			vga_saved_screen.video_memory[i] = pTextMemory[i];
	}

	if (vga_show_screen_info )	{
		printf( "Current video mode 0x%x:\n",  vga_saved_screen.video_mode );
		if (vga_saved_screen.is_graphics)
			printf( "Graphics mode\n" );
		else	{
			printf( "Text mode\n" );
			printf( "( %d columns by %d rows)\n", vga_saved_screen.width, vga_saved_screen.height );
			printf( "Char height is %d pixel rows\n", vga_saved_screen.char_height );
			printf( "Cursor of type 0x%x,0x%x is at (%d, %d)\n", vga_saved_screen.cursor_sline, vga_saved_screen.cursor_eline,vga_saved_screen.cursor_x, vga_saved_screen.cursor_y );
		}
	}

	return 0;
}

int isvga()
{
	union REGS regs;

	memset( &regs, 0, sizeof(regs) );
	regs.w.ax = 0x1a00;
	int386( 0x10, &regs, &regs );

	if ( regs.h.al == 0x1a )
		 return 1;

	return 0;
}

void vga_setcursor(ubyte x, ubyte y, ubyte sline, ubyte eline)
{
	union REGS regs;

	memset( &regs, 0, sizeof(regs) );
	regs.w.ax = 0x0200;
	regs.w.bx = 0;
	regs.h.dh = y;
	regs.h.dl = x;
	int386( 0x10, &regs, &regs );

	memset( &regs, 0, sizeof(regs) );
	regs.w.ax = 0x0100;
	regs.h.ch = sline & 0xf;
	regs.h.cl = eline & 0xf;
	int386( 0x10, &regs, &regs );
}

void vga_getcursor(ubyte *x, ubyte *y, ubyte * sline, ubyte * eline)
{
	union REGS regs;

	memset( &regs, 0, sizeof(regs) );
	regs.w.ax = 0x0300;
	regs.w.bx = 0;
	int386( 0x10, &regs, &regs );
	*y = regs.h.dh;
	*x = regs.h.dl;
	*sline = regs.h.ch;
	*eline = regs.h.cl;
}

void vga_restore_mode()
{
	int i;

	//vga_set_text_25();

	gr_palette_fade_out( gr_palette, 32, 0 );
	gr_palette_set_gamma(0);

	if ( vga_saved_screen.video_mode == 3 )	{
		switch( vga_saved_screen.height )	  {
		case 43:	vga_set_text_43(); break;
		case 50:	vga_set_text_50(); break;
		default:	vga_set_text_25(); break;
		}
	} else {
		vga_set_misc_mode(vga_saved_screen.video_mode);
	}

	if (vga_saved_screen.is_graphics==0)	{
		gr_sync_display();
		gr_sync_display();
		gr_palette_read( vga_pal_default );
		gr_palette_clear();

		for (i=0; i < vga_saved_screen.width*vga_saved_screen.height; i++ )
			pTextMemory[i]=vga_saved_screen.video_memory[i];
		vga_setcursor( vga_saved_screen.cursor_x, vga_saved_screen.cursor_y, vga_saved_screen.cursor_sline, vga_saved_screen.cursor_eline );
		gr_palette_faded_out = 1;
		gr_palette_fade_in( vga_pal_default, 32, 0 );
	}

}

void vga_close(void)
{
	if (vga_installed==1)
	{
		vga_installed = 0;
		vga_restore_mode();
		if( vga_saved_screen.video_memory ) {
			free(vga_saved_screen.video_memory);
			vga_saved_screen.video_memory = NULL;
		}
	}
}


int vga_vesa_setmode( int mode )
{
	int retcode;

	retcode=gr_vesa_checkmode( mode );
	if ( retcode ) return retcode;

	return vga_vesa_setmode( mode );
}


int vga_set_mode(int mode)
{
	int retcode;
	unsigned int w,h,t,data, r;

	//JOHNgr_disable_default_palette_loading();

	switch(mode)
	{
	case SM_ORIGINAL:
		return 0;
	case 0:
		if (!isvga()) return 1;
		vga_set_misc_mode(0x13);
		w = 320; r = 320; h = 200; t=BM_LINEAR; data = 0xA0000;
		break;
	case SM_640x400V:
		retcode = vga_vesa_setmode( 0x100 );
		if (retcode !=0 ) return retcode;
		w = 640; r = 640; h = 400; t=BM_SVGA; data = 0;
		break;
	case SM_640x480V:
		retcode = vga_vesa_setmode( 0x101 );
		if (retcode !=0 ) return retcode;
		w = 640; r = 640; h = 480; t=BM_SVGA; data = 0;
		break;
	case SM_800x600V:
		retcode = vga_vesa_setmode( 0x103 );
		if (retcode !=0 ) return retcode;
		w = 800; r = 800; h = 600; t=BM_SVGA; data = 0;
		break;
	case SM_1024x768V:
		retcode = vga_vesa_setmode( 0x105 );
		if (retcode !=0 ) return retcode;
		w = 1024; r = 1024; h = 768; t=BM_SVGA; data = 0;
		break;
	case SM_640x480V15:
		retcode = vga_vesa_setmode( 0x110 );
		if (retcode !=0 ) return retcode;
		w = 640; r = 640*2; h=480; t=BM_SVGA15; data = 0;
		break;
	case SM_800x600V15:
		retcode = vga_vesa_setmode( 0x113 );
		if (retcode !=0 ) return retcode;
		w = 800; r = 800*2; h=600; t=BM_SVGA15; data = 0;
		break;
	case 19:
		if (!isvga()) return 1;
		vga_set_misc_mode(0x13);
//		{
//			ubyte x;
//			x = inp( 0x3c5 );
//			x |= 8;
//			outp( 0x3c5, x );
//		}
		vga_set_cellheight( 3 );

		w = 320; r = 320; h = 100; t=BM_LINEAR; data = 0xA0000;
		break;
	case 20:
		retcode = vga_vesa_setmode( 0x102 );
		//gr_enable_default_palette_loading();
		if (retcode !=0 ) return retcode;
		vga_16_to_256();
		vga_set_linear();
		//vga_set_cellheight( 1 );
		gr_vesa_setlogical( 400 );
		w = 400; r = 400; h = 600; t=BM_SVGA; data = 0;
		break;
	case 21:
		if (!isvga()) return 1;
		vga_set_misc_mode(0xd);
		vga_16_to_256();
		vga_set_linear();
		vga_set_cellheight( 3 );
		w = 160; r = 160; h = 100; t=BM_LINEAR; data = 0xA0000;
		break;
	case 22:			// 3dmax 320x400
		if (!isvga()) return 1;
		vga_set_3dbios_mode(0x31);
		//w = 320; r = 320/4; h = 400; t=BM_MODEX; data = 0;
		w = 320; r = 320; h = 400; t=BM_SVGA; data = 0;
		break;
	default:
		if (!isvga()) return 1;
		w = gr_modex_setmode( mode );
		//gr_enable_default_palette_loading();
		h = w & 0xffff; w = w >> 16; r = w / 4;t = BM_MODEX; data = 0;
		break;
	}
	gr_palette_clear();

	return gr_init_screen(t, w, h, 0, 0, r, (unsigned char *)data);
}

short vga_init()
{
	// Only do this function once!
	if (vga_installed==1)
		return 1;

	if (gr_init_A0000())
		return 10;

	// Save the current text screen mode
	if (vga_save_mode()==1)
		return 1;

	if (!dpmi_allocate_selector( &gr_fade_table, 256*GR_FADE_LEVELS, &gr_fade_table_selector ))
		Error( "Error allocating fade table selector!" );

	if (!dpmi_allocate_selector( &gr_palette, 256*3, &gr_palette_selector ))
		Error( "Error allocating palette selector!" );

//	if (!dpmi_allocate_selector( &gr_inverse_table, 32*32*32, &gr_inverse_table_selector ))
//		Error( "Error allocating inverse table selector!" );

	// Set flags indicating that this is installed.
	vga_installed = 1;
	atexit(vga_close);

	return 0;
}


int vga_mode13_checkmode()
{
	if (isvga())
		return 0;
	else
		return 1;
}

//  0=Mode set OK
//  1=No VGA adapter installed
//  2=Program doesn't support this VESA granularity
//  3=Monitor doesn't support that VESA mode.:
//  4=Video card doesn't support that VESA mode.
//  5=No VESA driver found.
//  6=Bad Status after VESA call/
//  7=Not enough DOS memory to call VESA functions.
//  8=Error using DPMI.
//  9=Error setting logical line width.
// 10=Error allocating selector for A0000h
// 11=Not a valid mode support by gr.lib

int vga_check_mode(int mode)
{
	switch(mode)
	{
	case 19:
	case SM_320x200C:
	case SM_320x200U:
	case SM_320x240U:
	case SM_360x200U:
	case SM_360x240U:
	case SM_376x282U:
	case SM_320x400U:
	case SM_320x480U:
	case SM_360x400U:
	case SM_360x480U:
	case SM_360x360U:
	case SM_376x308U:
	case SM_376x564U:		return vga_mode13_checkmode();
	case SM_640x400V:		return gr_vesa_checkmode( 0x100 );
	case SM_640x480V: 	return gr_vesa_checkmode( 0x101 );
	case SM_800x600V: 	return gr_vesa_checkmode( 0x103 );
	case SM_1024x768V:	return vga_vesa_setmode( 0x105 );
	case SM_640x480V15:	return vga_vesa_setmode( 0x110 );
	case SM_800x600V15:	return vga_vesa_setmode( 0x113 );
	}
	return 11;
}
