#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <string.h>
#include <stdbool.h>

bool DEBUG = true;

void print_usage();
void remove_multiple(int start, int end, int N, int t, bool *nums);

int main(int argc, char *argv[]){

    if(argc != 3) {
        printf("\nIncorrect number of program arguments\n\n");
        print_usage();
        exit(1);
    }

    int N = atoi(argv[1]);
    int t = atoi(argv[2]);

    // if(DEBUG){ printf("N = %d\nt = %d\n", N, t);}

    double t_start = 0.0, t_taken = 0.0;
    bool* nums;
    nums = (bool*)malloc((N+1) * sizeof(bool));
    for(int idx = 0; idx < N+1; idx++){
        nums[idx] = true;
    }

    if (nums == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }

    int start = 2;
    int end = ((N+1)/2);
    
    t_start = omp_get_wtime();
    #pragma omp parallel num_threads(t)
    {
        remove_multiple(start, end, N, t, nums);
    }
    t_taken = omp_get_wtime() - t_start;
    printf("Time take for the main part: %f\n", t_taken);

    int counter = 1;
    for(int k = start; k < N+1; k++){
        if(nums[k]){
            printf("%d %d\n", counter, k);
            counter++;
        }
    }
}

void remove_multiple(int start, int end, int N, int t, bool *nums){
    int tid = omp_get_thread_num();
    
    for (int i = start+tid; i<=end; i=i+t){
        if(nums[i]){
            for (int j = 2*i; j < N+1; j=j+i){
                nums[j] = false;
            }
        }
    }

}

void print_usage(){
    printf("Usage:\n");
    printf("\t./genprime N t\n");
    printf("\twhere,\n");
    printf("\tN is a positive number bigger than 2\n");
    printf("\tt is the number of threads and is a positive integer that does not exceed 100\n");
}