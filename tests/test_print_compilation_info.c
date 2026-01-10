#include <stdio.h>

#include "c_traceback.h"

int main(void)
{
    ctb_clear_context();
    ctb_install_signal_handler();

    ctb_print_compilation_info();

    return 0;
}