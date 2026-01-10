#include <stdio.h>

#include "c_traceback.h"

#define FILE_PATH "../test.txt"

void open_file(const char *file_name);

int main(void)
{
    ctb_clear_context();
    ctb_install_signal_handler();

    TRY_GOTO(open_file(FILE_PATH), error);
    /* Do something */

    return 0;

error:
    ctb_dump_traceback();
    return 1;
}

void open_file(const char *file_name)
{
    FILE *file = fopen(file_name, "r");
    if (!file)
    {
        THROW_FMT(CTB_FILE_NOT_FOUND_ERROR, "Failed to open file: \"%s\"", file_name);
        return;
    }
    /* Do something */
    fclose(file);
}