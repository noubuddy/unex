#include "core/log.h"

#include <stdarg.h>
#include <stdio.h>

const char* unex_log_verbose_level_to_string(cesc_verbose_level verbose_level) {
    switch (verbose_level) {
        case UNEX_VERBOSE_NONE:
            return "NONE";
        case UNEX_VERBOSE_ERROR:
            return "ERROR";
        case UNEX_VERBOSE_WARNING:
            return "WARNING";
        case UNEX_VERBOSE_INFO:
            return "INFO";
        case UNEX_VERBOSE_DEBUG:
            return "DEBUG";
        case UNEX_VERBOSE_TRACE:
            return "TRACE";
        default:
            return "UNKNOWN";
    }
}

void unex_debug_print(cesc_verbose_level verbose_level, const char* format, ...) {
    va_list args;
    va_start(args, format);
    printf("%s: ", unex_log_verbose_level_to_string(verbose_level));
    vprintf(format, args);
    printf("\n");
    va_end(args);
}

void unex_debug_assert(bool condition, const char* message) {
    if (!condition) {
        unex_debug_print(UNEX_VERBOSE_ERROR, message);
#ifdef UNEX_DEBUG
        __debugbreak();
#endif
    }
}
