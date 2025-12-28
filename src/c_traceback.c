/**
 * \file error.c
 * \brief Main definitions for c_traceback library
 *
 * \author Ching-Yin Ng
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "c_traceback.h"
#include "c_traceback_errors.h"
#include "internal/common.h"
#include "internal/utils.h"

static CTB_Context traceback_context;

static CTB_Context *get_context(void)
{
    return &traceback_context;
}

void ctb_push_call_stack_frame(
    const char *file, const char *func, const int line, const char *source_code
)
{
    CTB_Context *context = get_context();
    const int call_depth = context->call_depth;
    if (call_depth < MAX_CALL_STACK_DEPTH)
    {
        CTB_Frame_ *frame = &context->call_stack_frames[call_depth];
        frame->filename = file;
        frame->function_name = func;
        frame->line_number = line;
        frame->source_code = source_code;
        context->call_depth++;
    }
}

void ctb_pop_call_stack_frame(void)
{
    CTB_Context *context = get_context();
    if (context->call_depth > 0)
    {
        context->call_depth--;
    }
}

// void ctb_print_call_stack(void)
// {
//     const CTB_Context *context = get_context();
//     const int call_depth = context->call_depth;
//     for (int i = 0; i < call_depth; i++)
//     {
//         const CTB_Frame_ *frame = &context->call_stack_frames[i];
//         fprintf(
//             stdout,
//             "  File %s\"%s\"%s, line %s%d%s in %s%s%s:\n    %s%s%s\n",
//             CTB_TRACEBACK_FILE_COLOR,
//             frame->filename,
//             CTB_RESET_COLOR,
//             CTB_TRACEBACK_LINE_COLOR,
//             frame->line_number,
//             CTB_RESET_COLOR,
//             CTB_TRACEBACK_FUNC_COLOR,
//             frame->function_name,
//             CTB_RESET_COLOR,
//             CTB_MESSAGE_COLOR,
//             frame->source_code,
//             CTB_RESET_COLOR
//         );
//     }
//     fflush(stdout);
// }
