#include <stdio.h>

#include "c_traceback.h"

int main(void)
{
    ctb_clear_context();
    ctb_install_signal_handler();

    printf("Press Ctrl+C to trigger a keyboard interrupt...\n");
    while (1)
    {
        /* Do nothing */
    }

    return 0;
}