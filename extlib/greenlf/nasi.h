#if !defined( NASI_DOT_H )
#define NASI_DOT_H

/*
 * NASI.H       5.20A  June 8, 1995
 *
 * The Greenleaf Comm Library
 *
 * Copyright (C) 1985-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 *  This include file contains the definitions for the Level 1
 *  functions you might want to use when writing an application
 *  that uses Novell's NASI services.  Note that using Greenleaf's
 *  version of NASI support doesn't require that you purchase the
 *  NASI SDK.  However, NASI won't do you any good unless you have
 *  a Novell network and a server running NCS.
 *
 * MODIFICATIONS
 *
 * June 8, 1995  5.20A : Initial release
 *
 */

/*
 * Not running vanilla DOS or Windows?  Forget NASI then!
 */

#if !defined( GF_X16 ) && !defined( GF_X32 ) && !defined( GF_WIN32 )

/*
 * This is the data structure used to handle the get first/get next
 * queries.  The buf[] element is what gets passed to NASI.  Upon
 * return, the nice names are sorted out of buf and stored in the other
 * character arrays.
 */

typedef struct {
    short int vc;
    char buf[ 34 ];
    char Server[ 9 ];
    char GeneralPort[ 9 ];
    char SpecificPort[ 15 ];
    int NcsPortNumber;
    int PortStatus;
} NASI_QUERY;

#ifdef __cplusplus
extern "C" {
#endif

int GF_CONV NasiLoaded( void );
int GF_CONV NasiQueryFirstPort( NASI_QUERY GF_DLL_FAR *q );
int GF_CONV NasiQueryNextPort( NASI_QUERY GF_DLL_FAR *q );
void GF_CONV NasiCloseQuery( NASI_QUERY GF_DLL_FAR *q );
int GF_CONV NasiSetSession( char GF_DLL_FAR *name,
                            char GF_DLL_FAR *password,
                            char GF_DLL_FAR *session_name,
                            int global );
int GF_CONV NasiGetSession( char GF_DLL_FAR *session );

#ifdef __cplusplus
};
#endif

#endif  /* #if !defined( GF_X16 ) && !defined( GF_X32 ) && !defined( GF_WIN32 ) */

#endif /* #if !defined( NASI_DOT_H )  */

