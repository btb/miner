#ifndef _SPARKLE_DOT_H
#define _SPARKLE_DOT_H

/*
 * SPARKLE.H                    5.20A  June 8, 1995
 *
 *  The Greenleaf Comm Library
 *
 *  Copyright (C) 1991-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 * Level 1 functions that come with the Sparkle INT14 driver.
 *
 * MODIFICATIONS
 *
 *  September 17, 1991  3.20  :  First release.
 */

int GF_CONV SparkleGetNameOfAttachedLine( char *name );
int GF_CONV SparkleConnectToNamedLine( char *name );
int GF_CONV SparkleGetNextAvailableName( char *name );
int GF_CONV SparkleGetFirstAvailableName( char *name );

#endif /* _SPARKLE_DOT_H */

