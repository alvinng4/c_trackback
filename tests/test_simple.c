#include <stdio.h>
#include <stdlib.h>

#include "c_traceback.h"

#define N 10

static void do_calculation(double *vec);
static void division_vec(double *vec, double denominator);

int main(void)
{
    ctb_clear_context();
    ctb_install_signal_handler();

    LOG_WARNING(
        CTB_DEPRECATION_WARNING,
        "This function is deprecated and will be replaced in the next version"
    );
    LOG_MESSAGE("Hello, world!");

    double *vec = malloc(N * sizeof(double));
    if (!vec)
    {
        THROW(CTB_MEMORY_ERROR, "Failed to allocate memory");
        goto error;
    }

    TRY_GOTO(do_calculation(vec), error);
    printf("This shouldn't be printed if there is error");

    free(vec);
    return 0;

error:
    free(vec);
    ctb_dump_traceback(); // Log traceback and reset error stack
    return 0;
}

static void do_calculation(double *vec)
{
    // Initialize array
    for (int i = 0; i < N; i++)
    {
        vec[i] = 0;
    }
    int success = TRY(division_vec(vec, 0)); // Throw error
    if (!success)
    {
        return;
    }

    // Further calculations...
    for (int i = 0; i < N; i++)
    {
        vec[i] += 10;
    }
}

static void division_vec(double *vec, double denominator)
{
    if (denominator == 0)
    {
        THROW_FMT(
            CTB_VALUE_ERROR, "Denominator must be nonzero! Received: %lf", denominator
        );
        return;
    }

    for (int i = 0; i < N; i++)
    {
        vec[i] /= denominator;
    }
}
