/* 
   This file contains the code to generate a file with N characters. 
   Any character can be one of four choices: a, b, c, or d. 
    
   compile with:  gcc -Wall -stad=c99 -o genfile random-char.c
   execute with:  ./genfile N filename.
   Where N is the numbre of characters and filenames is your choice of the file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *argv[])
{
    int count = 0;
    FILE * fp;
	char x;
    
    if(argc != 3 ){
	printf("usage: ./genfile N filenmae\n");
	printf("N: the number of characters in the file\n");
	printf("name: the name of the file to be generated\n");
 	exit(1);
    }

    if( (fp = fopen(argv[2],"w+t")) == NULL )
    {
	printf("Cannot create the file %s\n", argv[2]);
	exit(1);
    }

    count = atoi(argv[1]);

    srand((unsigned int)time(NULL));

    for (int i=0;i<count;i++){
		x = 97 + ((float)rand()/(float)(RAND_MAX)) * 4;
		fprintf(fp, "%c", x);
	}
    
    printf("Generated %d random characters and stored in file %s\n", count, argv[2]);

    fclose(fp);
    return 0;
}
