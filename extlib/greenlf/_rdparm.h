#ifndef __RDPARM_H
#define __RDPARM_H

/*
 * _RDPARM.H                5.20A  June 8, 1995
 *
 *  The Greenleaf Comm Library
 *
 *  Copyright (C) 1991-1995 Greenleaf Software Inc.  All Rights Reserved.
 *
 * NOTES
 *
 * This header file contains constants, structures, and definitions
 * used by the Greenleaf Parameter Block library.  This is a set of
 * code that supports the use of INI files.  These are private functions
 * used for our demo programs only.
 *
 * MODIFICATIONS
 *
 *  December 1, 1994   5.10A :  Initial release.
 */

/*
 * The PARAMETER_KEY structure contains the key and the value of
 * the key.  Each section has a linked list of these guys.
 */

typedef struct parameter_key {
  char *name;
  char *value;
  struct parameter_key *next_key;
} PARAMETER_KEY;

/*
 * The PARAMETER_SECTION structure contains the name of a section.  Each
 * parameter block has a linked list of these guys.  In turn, these guys
 * have a pointer to a linked list of keys and values.
 */

typedef struct parameter_section {
    char *name;
    PARAMETER_KEY *first_key;
    struct parameter_section *next_section;
} PARAMETER_SECTION;

/*
 * This is the stucture for the whole parameter block.  All it does is
 * hold the file name, and the pointer to the linked list of sections.
 */

typedef struct ini_file {
    PARAMETER_SECTION *first_section;
    char *file_name;
} GF_PARAMETER_BLOCK;

#ifdef __cplusplus
extern "C" {
#endif

GF_PARAMETER_BLOCK * GF_CONV PBConstruct( char *file_name );
int GF_CONV PBAddKey( GF_PARAMETER_BLOCK *ppb,
                      char *section_name,
                      char *key_name,
                      char *value );
int GF_CONV PBReadIniFile( GF_PARAMETER_BLOCK *ppb );
void GF_CONV PBWriteIniFile( GF_PARAMETER_BLOCK *ppb );
void GF_CONV PBDestroy( GF_PARAMETER_BLOCK *ppb );
char * GF_CONV PBFindValue( GF_PARAMETER_BLOCK *ppb,
                            char *section_name,
                            char *key_name );
#ifdef __cplusplus
}
#endif

#endif /* #ifndef __RDPARM_H */

