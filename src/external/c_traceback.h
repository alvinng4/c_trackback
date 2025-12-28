/**
 * \file c_traceback.h
 * \brief Library header for c_traceback library
 *
 * \author Ching-Yin Ng
 */

#ifndef C_TRACEBACK_H
#define C_TRACEBACK_H

#include "c_traceback_colors.h"
#include "c_traceback_error_codes.h"

typedef struct CTB_Context CTB_Context;

// Maximum number of traceback frames
#define MAX_TRACEBACK_FRAMES 64

/**
 * \brief Wrapper for logging an error to stderr without stacktrace.
 *
 * \param[in] error_code Error code associated with the error.
 * \param[in] msg Error message.
 */
#define CTB_LOG_ERROR_INLINE(error_code, msg)                                          \
    do                                                                                 \
    {                                                                                  \
        ctb_log_error_inline(__FILE__, __LINE__, __func__, error_code, msg);           \
    } while (0)

/**
 * \brief Wrapper for logging a warning to stderr without stacktrace.
 *
 * \param[in] error_code Error code associated with the warning.
 * \param[in] msg Warning message.
 */
#define CTB_LOG_WARNING_INLINE(error_code, msg)                                        \
    do                                                                                 \
    {                                                                                  \
        ctb_log_warning_inline(__FILE__, __LINE__, __func__, error_code, msg);         \
    } while (0)

/**
 * \brief Wrapper for logging a message to stdout without stacktrace.
 *
 * \param[in] msg Warning message.
 */
#define CTB_LOG_MESSAGE_INLINE(msg)                                                    \
    do                                                                                 \
    {                                                                                  \
        ctb_log_message_inline(__FILE__, __LINE__, __func__, msg);                     \
    } while (0)

CTB_Context *ctb_make_context(void);
void ctb_free_context(CTB_Context *restrict context);

/**
 * \brief Log error message to stderr without stacktrace.
 *
 * \param[in] file File where the error occurs.
 * \param[in] line Line number where the error occurs.
 * \param[in] func Function where the error occurs.
 * \param[in] error_code Error code associated with the error.
 * \param[in] msg Error message.
 */
void ctb_log_error_inline(
    const char *restrict file,
    const int line,
    const char *restrict func,
    const int error_code,
    const char *restrict msg
);

/**
 * \brief Log warning message to stderr without stacktrace.
 *
 * \param[in] file File where the warning occurs.
 * \param[in] line Line number where the warning occurs.
 * \param[in] func Function where the warning occurs.
 * \param[in] error_code Error code associated with the warning.
 * \param[in] msg Warning message.
 */
void ctb_log_warning_inline(
    const char *restrict file,
    const int line,
    const char *restrict func,
    const int error_code,
    const char *restrict msg
);

/**
 * \brief Log message to stdout without stacktrace.
 *
 * \param[in] file File where the message is sent.
 * \param[in] line Line number where the message is sent.
 * \param[in] func Function where the message is sent.
 * \param[in] msg Message.
 */
void ctb_log_message_inline(
    const char *restrict file,
    const int line,
    const char *restrict func,
    const char *restrict msg
);

#endif /* C_TRACEBACK_H */
