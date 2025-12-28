/**
 * \file common.h
 * \brief Common definitions for c_traceback library
 *
 * \author Ching-Yin Ng
 */

#ifndef COMMON_H
#define COMMON_H

#include "c_traceback.h"

typedef struct CTB_Frame_
{
    const char *restrict filename;
    const char *restrict function_name;
    int line_number;
    const char *restrict source_code;
} CTB_Frame_;

struct CTB_Context
{
    int call_depth;
    CTB_Frame_ call_stack_frames[MAX_CALL_STACK_DEPTH];
};

#endif /* COMMON_H */
