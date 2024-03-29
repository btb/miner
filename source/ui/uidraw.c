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
 * $Source: f:/miner/source/ui/rcs/uidraw.c $
 * $Revision: 1.5 $
 * $Author: john $
 * $Date: 1994/11/18 23:07:34 $
 *
 * Graphics primatives for the ui gadgets and windows.
 *
 * $Log: uidraw.c $
 * Revision 1.5  1994/11/18  23:07:34  john
 * Changed a bunch of shorts to ints.
 * 
 * Revision 1.4  1994/09/13  11:20:22  john
 * Made ui_string_centered not clip.
 * 
 * Revision 1.3  1993/10/26  13:46:33  john
 * *** empty log message ***
 * 
 * Revision 1.2  1993/10/05  17:31:00  john
 * *** empty log message ***
 * 
 * Revision 1.1  1993/09/20  10:35:41  john
 * Initial revision
 * 
 *
 */

#pragma off (unreferenced)
static char rcsid[] = "$Id: uidraw.c 1.5 1994/11/18 23:07:34 john Exp $";
#pragma on (unreferenced)
#include "fix.h"
#include "types.h"
#include "gr.h"
#include "ui.h"

void Hline(short x1, short x2, short y )
{
	gr_uscanline( x1, x2, y );
}

void Vline(short y1, short y2, short x )
{
	for ( ; y1 <= y2; y1++ )
		gr_upixel( x, y1 );
}

void ui_string_centered( short x, short y, char * s )
{
	int height, width, avg;

	gr_get_string_size(s, &width, &height, &avg );

	//baseline = height-grd_curcanv->cv_font->ft_baseline;

	gr_ustring(x-((width-1)/2), y-((height-1)/2), s );

}


void ui_draw_shad( short x1, short y1, short x2, short y2, short c1, short c2 )
{
	gr_setcolor( c1 );

	Hline( x1+0, x2-1, y1+0 );
	Vline( y1+1, y2+0, x1+0 );

	gr_setcolor( c2 );
	Hline( x1+1, x2, y2-0 );
	Vline( y1+0, y2-1, x2-0 );
}

void ui_draw_frame( short x1, short y1, short x2, short y2 )
{

	ui_draw_shad( x1+0, y1+0, x2-0, y2-0, CBRIGHT, CGREY );
	ui_draw_shad( x1+1, y1+1, x2-1, y2-1, CBRIGHT, CGREY );

	ui_draw_shad( x1+2, y1+2, x2-2, y2-2, CWHITE, CWHITE );
	ui_draw_shad( x1+3, y1+3, x2-3, y2-3, CWHITE, CWHITE );
	ui_draw_shad( x1+4, y1+4, x2-4, y2-4, CWHITE, CWHITE );
	ui_draw_shad( x1+5, y1+5, x2-5, y2-5, CWHITE, CWHITE );

	ui_draw_shad( x1+6, y1+6, x2-6, y2-6, CGREY, CBRIGHT );
	ui_draw_shad( x1+7, y1+7, x2-7, y2-7, CGREY, CBRIGHT );

}





void ui_draw_box_out( short x1, short y1, short x2, short y2 )
{

	gr_setcolor( CWHITE );
	gr_urect( x1+2, y1+2, x2-2, y2-2 );

	ui_draw_shad( x1+0, y1+0, x2-0, y2-0, CBRIGHT, CGREY );
	ui_draw_shad( x1+1, y1+1, x2-1, y2-1, CBRIGHT, CGREY );

}

void ui_draw_box_in( short x1, short y1, short x2, short y2 )
{

	gr_setcolor( CWHITE );
	gr_urect( x1+2, y1+2, x2-2, y2-2 );

	ui_draw_shad( x1+0, y1+0, x2-0, y2-0, CGREY, CBRIGHT );
	ui_draw_shad( x1+1, y1+1, x2-1, y2-1, CGREY, CBRIGHT );
}


void ui_draw_line_in( short x1, short y1, short x2, short y2 )
{
	gr_setcolor( CGREY );
	Hline( x1, x2, y1 );
	Hline( x1, x2-1, y2-1 );
	Vline( y1+1, y2-2, x1 );
	Vline( y1+1, y2-2, x2-1 );

	gr_setcolor( CBRIGHT );
	Hline( x1+1, x2-1, y1+1 );
	Hline( x1, x2, y2 );
	Vline( y1+2, y2-2, x1+1 );
	Vline( y1+1, y2-1, x2 );

}





