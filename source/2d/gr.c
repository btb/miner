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
 * $Source: f:/miner/source/2d/rcs/gr.c $
 * $Revision: 1.56 $
 * $Author: john $
 * $Date: 1995/05/08 11:22:47 $
 *
 * Graphical routines for setting video modes, etc.
 *
 * $Log: gr.c $
 * Revision 1.56  1995/05/08  11:22:47  john
 * Added 320x400 3dbios mode.
 * 
 * Revision 1.55  1995/02/02  16:44:05  john
 * Again with prev.
 * 
 * Revision 1.54  1995/02/02  16:42:18  john
 * Fixed palette with text fading out.
 * 
 * Revision 1.53  1995/02/02  14:26:20  john
 * Made palette fades work better with gamma thingy..
 * 
 * Revision 1.52  1995/02/02  14:08:59  john
 * Made palette gamma reset to 0 before exiting to Dos.
 * 
 * Revision 1.51  1995/01/30  18:06:35  john
 * Added text screen fade in/out, and restored video mode properly.
 * 
 * Revision 1.50  1995/01/24  17:58:16  john
 * Added code to return to 80x25 when graphics close.
 * 
 * Revision 1.49  1994/11/30  20:16:05  john
 * Fixed bug that the grd_curscreen flags were never initialized.
 * 
 * Revision 1.48  1994/11/24  13:24:43  john
 * Made sure that some rep movs had the cld set first.
 * Took some unused functions out.
 * 
 * Revision 1.47  1994/11/18  22:50:20  john
 * Changed shorts to ints in parameters.
 * 
 * Revision 1.46  1994/11/15  18:28:36  john
 * Made text screen fade in.
 * 
 * Revision 1.45  1994/11/15  17:55:11  john
 * Made text palette fade in when game over.
 * 
 * Revision 1.44  1994/11/07  12:07:30  john
 * Made save/restore cursor work a bit better.
 * 
 * Revision 1.43  1994/11/05  12:46:44  john
 * Changed palette stuff a bit.
 * 
 * Revision 1.42  1994/10/26  23:55:50  john
 * Took out roller; Took out inverse table.
 * 
 * Revision 1.41  1994/10/10  13:59:50  john
 * *** empty log message ***
 * 
 * Revision 1.40  1994/10/10  13:58:50  john
 * Added better VGA detection scheme.
 * 
 * Revision 1.39  1994/09/29  10:09:15  john
 * Hacked out VGA card detection for now.
 * 
 * Revision 1.38  1994/09/22  17:35:35  john
 * Fixed bug with palette not reloading in
 * gr_set_mode
 * 
 * Revision 1.37  1994/09/22  16:08:42  john
 * Fixed some palette stuff.
 * 
 * Revision 1.36  1994/09/19  11:44:23  john
 * Changed call to allocate selector to the dpmi module.
 * 
 * Revision 1.35  1994/09/12  19:28:11  john
 * Fixed bug with unclipped fonts clipping.
 * 
 * Revision 1.34  1994/09/12  18:20:18  john
 * Made text fade out
 * 
 * Revision 1.33  1994/09/12  14:40:15  john
 * Neatend.
 * 
 * Revision 1.32  1994/08/15  15:01:01  matt
 * Set ptr to NULL after freeing
 * 
 * Revision 1.31  1994/07/27  18:30:28  john
 * Took away the blending table.
 * 
 * Revision 1.30  1994/06/24  17:26:59  john
 * Made rowsizes bigger than actual screen work with SVGA.
 * 
 * Revision 1.29  1994/05/12  17:33:16  john
 * Added circle code.
 * 
 * Revision 1.28  1994/05/10  19:51:49  john
 * Added 320x100 mode.
 * 
 * Revision 1.27  1994/05/06  12:50:23  john
 * Added supertransparency; neatend things up; took out warnings.
 * 
 * Revision 1.26  1994/05/03  19:39:00  john
 * *** empty log message ***
 * 
 * Revision 1.25  1994/04/08  16:59:34  john
 * Add fading poly's; Made palette fade 32 instead of 16.
 * 
 * Revision 1.24  1994/03/14  16:56:16  john
 * Changed grs_bitmap structure to include bm_flags.
 * 
 * Revision 1.23  1994/02/18  15:32:27  john
 * *** empty log message ***
 * 
 * Revision 1.22  1994/01/25  11:40:44  john
 * Added gr_check_mode function.
 * 
 * Revision 1.21  1993/12/21  19:57:48  john
 * added selector stuff.
 * 
 * Revision 1.20  1993/12/21  11:40:32  john
 * *** empty log message ***
 * 
 * Revision 1.19  1993/12/09  15:02:13  john
 * Changed palette stuff majorly
 * 
 * Revision 1.18  1993/11/16  11:28:36  john
 * *** empty log message ***
 * 
 * Revision 1.17  1993/10/26  13:17:53  john
 * *** empty log message ***
 * 
 * Revision 1.16  1993/10/15  16:23:42  john
 * y
 * 
 * Revision 1.15  1993/09/29  16:15:21  john
 * optimized
 * 
 * Revision 1.14  1993/09/28  19:06:51  john
 * made gr_set_mode change the grd_cursreen->sc_mode variable.
 * 
 * Revision 1.13  1993/09/28  12:52:12  matt
 * Set aspect ratio of current screen in gr_init() and gr_set_mode().
 * 
 * Revision 1.12  1993/09/27  13:00:24  john
 * made gr_set_mode not call mode_reset on fail
 * 
 * Revision 1.11  1993/09/27  12:51:27  john
 * fixed gr_set_mode to return values
 * 
 * Revision 1.10  1993/09/26  18:59:12  john
 * fade in/out stuff
 * 
 * Revision 1.9  1993/09/21  14:00:41  john
 * added code to save 43/50 line modes.
 * 
 * Revision 1.8  1993/09/20  14:48:48  john
 * *** empty log message ***
 * 
 * Revision 1.7  1993/09/16  17:27:48  john
 * Added code to save/restore video mode.
 * 
 * Revision 1.6  1993/09/16  16:30:15  john
 * Made gr_close retore Mode 3 always.
 * 
 * Revision 1.5  1993/09/14  18:40:07  john
 * Made it so that gr_setmode doesn't change curcanv font and colors.
 * 
 * Revision 1.4  1993/09/14  16:27:01  matt
 * Changes gr_change_mode() to be gr_set_mode()
 * After gr_set_mode(), grd_curcanv is the canvas of the new screen
 * Made gr_set_mode() work with the new grd_curcanv, not the old one
 * 
 * Revision 1.3  1993/09/14  13:08:37  john
 * Added gr_changemode
 * 
 * Revision 1.2  1993/09/08  17:36:37  john
 * Looking for error for Yuan... Neatened the nested ifs in setmode.
 * 
 * Revision 1.1  1993/09/08  11:43:51  john
 * Initial revision
 * 
 *
 */

#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "mem.h"
#include "gr.h"

unsigned char * gr_video_memory = (unsigned char *)0xA0000;

int gr_installed = 0;

void gr_close(void)
{
	gr_close_screen();
	gr_installed = 0;
}

int gr_init(void)
{
	// int org_gamma;
	// int retcode;

	// Only do this function once!
	if (gr_installed==1)
		return 1;

	// // Save the current palette, and fade it out to black.
	// gr_palette_read( vga_pal_default );
	// gr_palette_faded_out = 0;
	// org_gamma = gr_palette_get_gamma();
	// gr_palette_set_gamma( 0 );
	// gr_palette_fade_out( vga_pal_default, 32, 0 );
	// gr_palette_clear();
	// gr_palette_set_gamma( org_gamma );
	// gr_sync_display();
	// gr_sync_display();

	// // Set the mode.
	// if (retcode=vga_set_mode(mode))
	// {
	// 	vga_restore_mode();
	// 	return retcode;
	// }

	// Set flags indicating that this is installed.
	gr_installed = 1;

	atexit(gr_close);

	return 0;
}

int gr_close_screen()
{
	if (grd_curscreen) {
		free(grd_curscreen);
		grd_curscreen = NULL;
	}

	return 0;
}

int gr_init_screen(int bitmap_type, int w, int h, int x, int y, int rowsize, ubyte *screen_addr)
{
	if (!gr_installed)
		return 1;

	if (grd_curscreen == NULL)
		MALLOC( grd_curscreen,grs_screen,1 );

	memset( grd_curscreen, 0, sizeof(grs_screen));

	grd_curscreen->sc_mode = bitmap_type;
	grd_curscreen->sc_w = w;
	grd_curscreen->sc_h = h;
	grd_curscreen->sc_aspect = fixdiv(grd_curscreen->sc_w*3,grd_curscreen->sc_h*4);

	grd_curscreen->sc_canvas.cv_bitmap.bm_x = x;
	grd_curscreen->sc_canvas.cv_bitmap.bm_y = y;
	grd_curscreen->sc_canvas.cv_bitmap.bm_w = w;
	grd_curscreen->sc_canvas.cv_bitmap.bm_h = h;
	grd_curscreen->sc_canvas.cv_bitmap.bm_rowsize = rowsize;
	grd_curscreen->sc_canvas.cv_bitmap.bm_type = bitmap_type;
	grd_curscreen->sc_canvas.cv_bitmap.bm_data = (bitmap_type==BM_LINEAR)?screen_addr:NULL;

	grd_curscreen->sc_canvas.cv_color = 0;
	grd_curscreen->sc_canvas.cv_drawmode = 0;
	grd_curscreen->sc_canvas.cv_font = NULL;
	grd_curscreen->sc_canvas.cv_font_fg_color = 0;
	grd_curscreen->sc_canvas.cv_font_bg_color = 0;

	gr_set_current_canvas( &grd_curscreen->sc_canvas );

	return 0;
}
