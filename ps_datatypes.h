//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// Data Types                                                  //
//-------------------------------------------------------------//

#ifndef __PS_DATATYPES_H__
#define __PS_DATATYPES_H__

#include <uchar.h>
#include <wchar.h>

#define SUCCESS 0

// Data Types -------------------------------------------------------------------
typedef enum boolean { FALSE, TRUE }     bool;
typedef unsigned char                   uchar;
typedef wchar_t                         wchar;
typedef char16_t                       char16;
typedef char32_t                       char32;
typedef short int                       int16;
typedef unsigned short int             uint16;
typedef int                             int32;
typedef unsigned int                   uint32;
typedef long int                        int64;
typedef unsigned long int              uint64;
typedef float                         float32;
typedef double                        float64;
typedef long double                  float128;
//-------------------------------------------------------------------------------

#endif /* ps_datatypes.h */
