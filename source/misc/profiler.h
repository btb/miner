#ifndef _PROFILER_H
#define _PROFILER_H

#ifdef __WATCOMC__
#include <wsample.h>            //should come after inferno.h to get mark setting
#else
#define _MARK_(s) ((void)0)
#endif

#endif
