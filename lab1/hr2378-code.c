#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(){
    printf("Hello..");

    #pragma omp parallel
    {
        int my_rank = omp_get_thread_num();
        int thread_count = omp_get_num_threads();
        printf("(%d/%d)World\n", my_rank+1, thread_count);
    }

    printf("!\n");
}