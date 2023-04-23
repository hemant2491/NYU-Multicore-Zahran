#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <string.h>
#include <stdbool.h>

bool DEBUG = true;

void print_usage();


int main(int argc, char *argv[]){

    if(argc != 3) {
        printf("\nIncorrect number of program arguments\n\n");
        print_usage();
        exit(1);
    }

    int N;
    int t;

    N = atoi(argv[1]);
    t = atoi(argv[2]);

    if(DEBUG){ printf("N = %d\nt = %d\n", N, t);}

    int start = 2;
    int end = ((N+1)/2);
    // bool nums[N+1];
    // memset( nums, true, (N+1) * sizeof(bool) );
    bool* nums;
    nums = (bool*)malloc((N+1) * sizeof(bool));
    for(int idx = 0; idx < N+1; idx++){
        nums[idx] = true;
    }

    if (nums == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }

    for (int i = start; i<=end; i++){
        for (int j = 2*i; j < N+1; j=j+i){
            nums[j] = false;
        }
    }

    
    int counter = 1;
    for(int k = start; k < N+1; k++){
        if(nums[k]){
            printf("%d %d\n", counter, k);
            counter++;
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