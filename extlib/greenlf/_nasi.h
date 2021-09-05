#if !defined( __NASI_H )
#define __NASI_H

/*
 * _NASI.H       5.20A  June 8, 1995
 *
 * The Greenleaf Comm Library
 *
 * Copyright (C) 1985-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 *  This include file contains the definitions for the private
 *  functions used by the library when using the NASI driver.
 *
 * MODIFICATIONS
 *
 * June 8, 1995  5.20A : Initial release
 *
 */
#if !defined( GF_X16 ) && !defined( GF_X32 ) && !defined( GF_WIN32 )

typedef struct {
    char server_name[ 9 ];
    char general_port_name[ 9 ];
    char specific_port_name[ 15 ];
    char service_name[ 15 ];
    char session_name[ 17 ];
    short int vc;
    short int line_status;
    char pconfig[ 15 ];
} NASI_PORT;

#ifdef __cplusplus
extern "C" {
#endif

/*
 * These are the internal Level 1 nasi routines. They usually have
 * different implementations under DOS and Windows, although there
 * are a couple cases where they are close enough to be co-resident
 * with a bunch of #ifdefs
 */

int GF_CONV _DumpPortStatusNasi( PORT *port, PORT_DUMPER printer );
int GF_CONV _NasiSetServiceName( short int vc, char GF_DLL_FAR *name );
int GF_CONV _NasiAllocateVc( short int GF_DLL_FAR *pvc );
int GF_CONV _NasiDisconnectVc( unsigned short int vc );
int GF_CONV _AttachNasi( NASI_PORT GF_DLL_FAR *np );
void GF_CONV _NasiParsePortName( NASI_PORT GF_DLL_FAR *nasi_port, char GF_DLL_FAR *name );

/*
 * If you are running under DOS, I access all of the NASI services
 * with simple calls to int86x().  Things aren't so nice under windows.
 * I have to load up a batch of function pointers.  These function
 * pointers have horrible prototypes, which makes casting away all
 * my errors really hard.  But here is one way to get the job done:
 * create a customized typedef for each of the function types.
 */

#ifdef GF_WINDOWS
typedef WORD (FAR PASCAL _loadds * SET_SESSION_NAME)(char far *);
typedef WORD (FAR PASCAL _loadds * ALLOCATE_VC)(short int far *pvc);
typedef WORD (FAR PASCAL _loadds * QUERY_NAME_SERVICE)(short int vc,
                                                       short int Length,
                                                       char far *pBuffer,
                                                       char QueryType);
typedef WORD (FAR PASCAL _loadds * DISCONNECT)(short int vc);
typedef WORD (FAR PASCAL _loadds * INITIALIZE)(short int vc,
                                               char far *pConfig,
                                               char far *pPort );
typedef WORD (FAR PASCAL _loadds * SET_SERVICE_NAME)(unsigned short vc,
                                                     char far *pServiceName);
typedef WORD (FAR PASCAL _loadds *FLUSH_TX_BUFFER)(unsigned short int vc);
typedef WORD (FAR PASCAL _loadds *GET_TX_STATUS)(unsigned short int vc,
                                                 char far *pXStatus,
                                                 char far *pBoardStat);
typedef WORD (FAR PASCAL _loadds *GET_RX_STATUS)(unsigned short int vc,
                                                 char far *pXStatus);
typedef WORD (FAR PASCAL _loadds *GET_EXTERNAL_STATUS)(unsigned short int vc,
                                                       char far *pStatus);
typedef WORD (FAR PASCAL _loadds *READ_BLOCK)(unsigned short int vc,
                                              short unsigned int far *pLength,
                                              char far *pBuffer);
typedef WORD (FAR PASCAL _loadds *WRITE_BLOCK)(unsigned short int vc,
                                               unsigned short int far *pLength,
                                               char far *pBuffer);
typedef WORD (FAR PASCAL _loadds *CONTROL_REQUEST)(unsigned short int vc,
                                                   char RequestType,
                                                   char far *pBuffer);
typedef WORD (FAR PASCAL _loadds *GET_SERVER_NAME)(unsigned short int vc,
                                                   char far *pServerName);
typedef WORD (FAR PASCAL _loadds *GET_GENERAL_NAME)(unsigned short int vc,
                                                    char far *pGeneralName);
typedef WORD (FAR PASCAL _loadds *GET_SERVICE_NAME)(unsigned short int vc,
                                                    char far *pServiceName);
typedef WORD (FAR PASCAL _loadds *GET_SPECIFIC_NAME)(unsigned short int vc,
                                                     char far *pServiceName);
typedef WORD (FAR PASCAL _loadds *GET_SESSION_NAME)(char far *pSessionName);
typedef WORD (FAR PASCAL _loadds *GET_STATUS)(unsigned short int vc,
                                              unsigned short int far *pStatus );

/*
 * And here are those function pointer defintions.
 * At this time, all of these guys are set to 0 on startup.
 * It would probably be better to point them to routines
 * that return error codes.
 */

extern SET_SESSION_NAME _nasi_set_session_name;
extern ALLOCATE_VC _nasi_allocate_vc;
extern QUERY_NAME_SERVICE _nasi_query_name_service;
extern DISCONNECT _nasi_disconnect_vc;
extern INITIALIZE _nasi_initialize;
extern SET_SERVICE_NAME _nasi_set_service_name;
extern FLUSH_TX_BUFFER _nasi_flush_tx_buffer;
extern GET_TX_STATUS _nasi_get_tx_status;
extern GET_RX_STATUS _nasi_get_rx_status;
extern GET_EXTERNAL_STATUS _nasi_get_external_status;
extern READ_BLOCK _nasi_read;
extern WRITE_BLOCK _nasi_write;
extern CONTROL_REQUEST _nasi_control_request;
extern GET_SERVER_NAME _nasi_get_server_name;
extern GET_GENERAL_NAME _nasi_get_general_name;
extern GET_SERVICE_NAME _nasi_get_service_name;
extern GET_SPECIFIC_NAME _nasi_get_specific_name;
extern GET_SESSION_NAME _nasi_get_session_name;
extern GET_STATUS _nasi_get_status;

#endif

#ifdef __cplusplus
};
#endif

#endif /* #if !defined( GF_X16 ) && !defined( GF_X32 ) && !defined( GF_WIN32 ) */

#endif /* #if !defined( __NASI_H )  */

