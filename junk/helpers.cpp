#include "header/helpers.hpp"
#include <cstdarg>
#include <cstdio>

void log (const char* format, ...) {
    va_list args;
    va_start (args, format);
    vfprintf(stdout, format, args);
    printf("\n");
    va_end(args);
}