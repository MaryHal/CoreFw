#include "Log.h"

#include <cstdio>
#include <stdarg.h>

void logf(const char *format, ...)
{
    char sz[1024];
    va_list marker;

    va_start(marker, format);
    vsprintf(sz, format, marker);
    va_end(marker);

    std::string str = sz;

    log(str);
}

void log(const std::string& str)
{
    fprintf(stdout, "%s\n", str.c_str() );
}


