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
 * KRB stub routines to compile without sound
 * 
 */


#include "fix.h"
#include "vecmat.h"

#pragma off(unreferenced)

int digi_driver_board				= 0;
int digi_driver_port					= 0;
int digi_driver_irq					= 0;
int digi_driver_dma					= 0;
int digi_midi_type					= 0;			// Midi driver type
int digi_midi_port					= 0;			// Midi driver port
int digi_timer_rate					= 9943;			// rate for the timer to go off to handle the driver system (120 Hz)
int digi_lomem 						= 0;

void digi_close()
{
}

int digi_init()
{
	return 0;//KRB Comment out...
}

void digi_reset()	
{
}

void digi_set_max_channels(int n)
{
}

int digi_get_max_channels()
{
	return 0;//KRB Comment out...
}

int digi_is_sound_playing(int soundno)
{
	return 0;//KRB Comment out...
}

void digi_play_sample_once( int soundno, fix max_volume )	
{
}

void digi_play_sample( int soundno, fix max_volume )
{
}

void digi_play_sample_3d( int soundno, int angle, int volume, int no_dups )	
{
}

void digi_set_midi_volume( int mvolume )
{
}

void digi_set_digi_volume( int dvolume )
{
}

void digi_set_volume( int dvolume, int mvolume )	
{
}

void digi_play_midi_song( char * filename, char * melodic_bank, char * drum_bank, int loop )
{
}

void digi_init_sounds()
{
}

int digi_link_sound_to_object2( int org_soundnum, short objnum, int forever, fix max_volume, fix  max_distance )
{
	return 0;//KRB -Comment out
}

int digi_link_sound_to_object( int soundnum, short objnum, int forever, fix max_volume )
{
	return 0;//KRB comment out 98
}

int digi_link_sound_to_pos2( int org_soundnum, short segnum, short sidenum, vms_vector * pos, int forever, fix max_volume, fix max_distance )
{
	return 0;//KRB comment out '98
}

int digi_link_sound_to_pos( int soundnum, short segnum, short sidenum, vms_vector * pos, int forever, fix max_volume )
{
	return 0;//KRB comment out project...	
}

void digi_kill_sound_linked_to_segment( int segnum, int sidenum, int soundnum )
{
}

void digi_kill_sound_linked_to_object( int objnum )
{
}

void digi_sync_sounds()
{
}

void digi_pause_all()
{
}

void digi_resume_all()
{
}

void digi_stop_all()
{
}
