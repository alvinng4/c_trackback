/**
 * \file: example_tut02.c
 */
 
#include <stdio.h>
#include <stdlib.h>
 
#include "c_traceback.h"
 
void alloc_memory(double **arr, const size_t n);
void initialize_vec(double *arr, const size_t n);
 
int main(void)
{
    ctb_install_signal_handler();

    const size_t n = 1000;     // Vector size
    const double denominator = 123.0;
 
    /* Allocate memory */
    double *arr;
    TRY_GOTO(alloc_memory(&arr, n), error_clean_up);
 
    /* Initialize values */
    TRY_GOTO(initialize_vec(arr, 1000 * n), error_clean_up);
 
    /* Division */
 
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

    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
}
