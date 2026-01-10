/**
 * \file: example_tut04.c
 */

#include <stdio.h>
#include <stdlib.h>

#include "c_traceback.h"

void alloc_memory(double **arr, const size_t n);
void initialize_vec(double *arr, const size_t n);
void divide_vec(double *arr, const size_t n, const double denominator);

int main(void)
{
    ctb_clear_context();
    ctb_install_signal_handler();

    const size_t n = 1000; // Vector size
    const double denominator = 0.0;

    /* Allocate memory */
    double *arr;
    TRY_GOTO(alloc_memory(&arr, n), error_clean_up);

    /* Initialize values */
    TRY_GOTO(initialize_vec(arr, n), error_clean_up);

    /* Division */
    TRY_GOTO(divide_vec(arr, n, denominator), error_clean_up);

    /* Clean up */
    free(arr);
    return 0;

error_clean_up:
    /* Error clean up */
    free(arr);
    ctb_dump_traceback();
    return 1;
}

void alloc_memory(double **arr, const size_t n)
{
    *arr = malloc(n * sizeof(double));
    if (!(*arr))
    {
        // Failed to allocate memory
        THROW(CTB_MEMORY_ERROR, "Failed to allocate memory for vector!");
    }
}

void initialize_vec(double *arr, const size_t n)
{
    if (!arr)
    {
        // Null Pointer
        THROW(CTB_NULL_POINTER_ERROR, "Received null pointer.");
    }

    TRACE_BLOCK(for (int i = 0; i < n; i++) { arr[i] = i; });
}

void divide_vec(double *arr, const size_t n, const double denominator)
{
    if (denominator == 0.0)
    {
        // Division by zero
        LOG_WARNING_FMT(
            CTB_WARNING, "Denominator should not be zero! Received: %lf.", denominator
        );
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] /= denominator;
    }
}
