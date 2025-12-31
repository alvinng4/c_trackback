/**
 * \file trace.h
 * \brief Header file for call stack tracing macros and functions.
 *
 * \author Ching-Yin Ng
 */

#ifndef C_TRACEBACK_TRACE_H
#define C_TRACEBACK_TRACE_H

/**
 * \brief Wrapper macro for expression to automatically manage call stack frames.
 *
 * \param[in] expr The expression to be traced.
 *
 * \return Whether the expression executed without error.
 */
#define TRACE(expr)                                                                    \
    (ctb_push_call_stack_frame(__FILE__, __func__, __LINE__, #expr),                   \
     (expr),                                                                           \
     ctb_pop_call_stack_frame(),                                                       \
     !ctb_check_error_occurred())

/**
 * \brief Wrapper macro for expression to automatically manage call stack frames without
 * return value.
 *
 * \param[in] expr The expression to be traced.
 */
#define TRACE_VOID(expr)                                                               \
    do                                                                                 \
    {                                                                                  \
        ctb_push_call_stack_frame(__FILE__, __func__, __LINE__, #expr);                \
        (expr);                                                                        \
        ctb_pop_call_stack_frame();                                                    \
    } while (0)

/**
 * \brief Wrapper macro for a code block to automatically manage call stack frames.
 *
 * \param[in] ... The block of code to be traced.
 */
#define TRACE_BLOCK(...)                                                               \
    do                                                                                 \
    {                                                                                  \
        ctb_push_call_stack_frame(__FILE__, __func__, __LINE__, #__VA_ARGS__);         \
        __VA_ARGS__                                                                    \
        ctb_pop_call_stack_frame();                                                    \
    } while (0)

/**
 * \brief Push a new call stack frame.
 * \param[in] file File where the function is called.
 * \param[in] func Function name where the function is called.
 * \param[in] line Line number where the function is called.
 * \param[in] source_code Source code of the function call.
 */
void ctb_push_call_stack_frame(
    const char *file, const char *func, const int line, const char *source_code
);

/**
 * \brief Pop the top call stack frame.
 */
void ctb_pop_call_stack_frame(void);

#endif /* C_TRACEBACK_TRACE_H */