/**
 * \file example_logging.c
 *
 * \brief Example usage of logging functions from c_traceback library
 */

#include <stdio.h>
#include <string.h>

#include "c_traceback.h"

#define MESSAGE_BUFFER_SIZE 256

void log_error(int i);
void log_error_level2(int i);
void log_warning(int i);
void log_warning_level2(int i);
void log_message(int i);
void log_message_level2(int i);

int main(void)
{
    ctb_clear_context();
    ctb_install_signal_handler();

    log_error(1);
    log_warning(3);
    log_message(5);

    return 0;
}

void log_error(int i)
{
    LOG_ERROR_FMT(
        CTB_MATH_ERROR,
        "(Test %d) This should be formatted error level 1 with math error",
        i
    );
    log_error_level2(i + 1);
}

void log_error_level2(int i)
{
    char message[MESSAGE_BUFFER_SIZE];
    snprintf(
        message,
        MESSAGE_BUFFER_SIZE,
        "(Test %d) This should be error level 2 with buffer error",
        i
    );
    LOG_ERROR(CTB_BUFFER_ERROR, message);
}

void log_warning(int i)
{
    LOG_WARNING_FMT(
        CTB_DEPRECATION_WARNING,
        "(Test %d) This should be formatted warning level 1 with deprecation "
        "warning",
        i
    );
    log_warning_level2(i + 1);
}

void log_warning_level2(int i)
{
    char message[MESSAGE_BUFFER_SIZE];
    snprintf(
        message,
        MESSAGE_BUFFER_SIZE,
        "(Test %d) This should be warning level 2 with user warning",
        i
    );
    LOG_WARNING(CTB_USER_WARNING, message);
}

void log_message(int i)
{
    LOG_MESSAGE_FMT("(Test %d) This should be formatted message level 1", i);
    log_message_level2(i + 1);
}

void log_message_level2(int i)
{
    char message[MESSAGE_BUFFER_SIZE];
    snprintf(
        message, MESSAGE_BUFFER_SIZE, "(Test %d) This should be message level 2", i
    );
    LOG_MESSAGE(message);
}
