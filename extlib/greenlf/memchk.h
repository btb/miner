#if !defined( _MEMCHK_H )
#define _MEMCHK_H

/*
 * MEMCHK.H       5.20A  June 8, 1995
 *
 * The Greenleaf Comm Library
 *
 * Copyright (C) 1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 *  Want to build a copy of Greenleaf's library with memcheck built in?
 *  Copy this file on top of gfcustom.h.
 *
 */

#include "compiler.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>

#if defined( GF_MICROSOFT_C )
  #include <malloc.h>
#elif defined( GF_TURBO_CPP ) || defined( GF_BORLAND_CPP )
  #include <alloc.h>
  #include <dir.h>
#endif

#include <memcheck.h>

#endif /* #if !defined( _MEMCHK_H ) */

