#include <stdio.h>

#include "c_traceback.h"

void nested_test_warning();
void nested_test_warning2();
void nested_test_message();

int main(void)
{
    // Test make context
    CTB_Context *ctb_context = ctb_make_context();
    if (!ctb_context)
    {
        printf("Error: unable to make ctb_context");
        goto error;
    }

    // Test raise warning
    nested_test_warning();

    // Test message
    nested_test_message();

    return 0;

error:
    return 1;
}

void nested_test_warning()
{
    CTB_PRINT_WARNING(
        CTB_DEPRECATION_WARNING,
        "This should be warning level 1 with deprecation warning"
    );
    nested_test_warning2();
}

void nested_test_warning2()
{
    CTB_PRINT_WARNING(
        CTB_MEMORY_ERROR, "This should be warning level 2 with memory error"
    );
}

void nested_test_message()
{
    CTB_PRINT_MESSAGE("This should be a message level 1");
}