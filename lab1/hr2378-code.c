#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <string.h>
#include <stdbool.h>

bool DEBUG = false;

void print_usage();
void count_chars(int num,char *filename, int *solution);
void print_solution(int *solution, int num);

int main(int argc, char *argv[]){

    // #pragma omp parallel
    // {
    //     int my_rank = omp_get_thread_num();
    //     int thread_count = omp_get_num_threads();
    //     printf("(%d/%d)World\n", my_rank+1, thread_count);
    // }

    if(argc != 4) {
        printf("\nIncorrect program arguments\n\n");
        print_usage();
        exit(1);
    }

    int N;
    int num;
    char* filename;
    // filename = "./tests/test_10.txt";
    // num = 10;

    N = atoi(argv[1]);
    num = atoi(argv[2]);
    filename = argv[3];

    int solution[] = { 0, 0, 0, 0};
    count_chars(num, filename, solution);
    print_solution(solution, num);
}

void count_chars(int num, char *filename, int *solution){
    FILE* file_ptr;
    char ch;

    file_ptr = fopen(filename, "r");

    if (NULL == file_ptr){
        printf("Input file %s couldn't be opened\n", filename);
        exit(1);
    }

    if(DEBUG){ printf("Reading file %s for %d characters\n", filename, num);}

    for(int i = 0; i < num; i++){
        ch = fgetc(file_ptr);
        if(ch == EOF){
            break;
        }
        if(DEBUG){ printf("%c\n", ch);}
        if(ch == 'a'){
            solution[0]++;
        } else if(ch == 'b'){
            solution[1]++;
        } else if(ch == 'c'){
            solution[2]++;
        } else if(ch == 'd'){
            solution[3]++;
        } else {
            printf("Unexpected character %c\n", ch);
            exit(1);
        }
    }

    fclose(file_ptr);
    
    return;
}

void print_solution(int *solution, int num){
    char ch;
    int max_freq = 0;
    int max_freq_index = -1;
    int tmp_freq = 0;

    for (int i=0; i<4; i++){
        tmp_freq = solution[i];
        if(tmp_freq > max_freq){
            max_freq = tmp_freq;
            max_freq_index = i;
        }
    }
    
    if(max_freq_index == -1){
        printf("Found no characters in the file\n");
        return;
    } else if (max_freq_index == 0){
        ch = 'a';
    } else if (max_freq_index == 1){
        ch = 'b';
    } else if (max_freq_index == 2){
        ch = 'c';
    } else if (max_freq_index == 3){
        ch = 'd';
    }

    if(DEBUG){
        printf("a : %d\n", solution[0]);
        printf("b : %d\n", solution[1]);
        printf("c : %d\n", solution[2]);
        printf("d : %d\n", solution[3]);
    }
    
    printf("%c occurred the most %d times of a total of %d characters.\n", ch, max_freq, num);

    return;
}

void print_usage(){
    printf("Usage:\n");
    printf("\t./maxnum $N $num $filename\n");
    printf("\twhere,\n");
    printf("\tN: number of threads, can be\n\t\t0 (purely sequential)\n\t\t1 (OpenMP version with one thread)\n\t\t4 (OpenMP with four threads)\n");
    printf("\tnum: number of characters in the file\n");
    printf("\tfilename: this is the name of the file that contains the characters\n");
}