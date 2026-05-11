#pragma once
#ifndef UNEX_LOG_H
#define UNEX_LOG_H

typedef enum {
    UNEX_VERBOSE_NONE,
    UNEX_VERBOSE_ERROR,
    UNEX_VERBOSE_WARNING,
    UNEX_VERBOSE_INFO,
    UNEX_VERBOSE_DEBUG,
    UNEX_VERBOSE_TRACE,
} cesc_verbose_level;

void unex_debug_print(cesc_verbose_level verbose_level, const char* format, ...);
void unex_debug_assert(bool condition, const char* message);

#define LOG_DEBUG(message) cecs_debug_print(message, CECS_VERBOSE_DEBUG)
#define ASSERT(condition, message) cecs_assert(condition, message)

#endif