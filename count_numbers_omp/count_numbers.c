#include <stdio.h>
#include<stdlib.h>
#include <omp.h>


int main(int argc, char** argv){
    //get arguments
    // int arg_count = sizeof(argv)/sizeof(char *);
    // if(arg_count != 5){
    //     printf("Invalid Input.");
    //     return -1;
    // }
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int x = atoi(argv[3]);
    int t = atoi(argv[4]);

    double start, end;
    start = omp_get_wtime();

    int count = 0;
    #pragma omp parallel for num_threads(t) reduction(+: count)
        for (int num = a; num <= b; num++){
            if ((num % x) == 0){
                count++;
            }
        }

    end = omp_get_wtime();

    printf("time: %f sec\n", end - start);
    printf("There are %d numbers divisible by %d in the [%d, %d] range.\n", count, x, a, b);

    return 0;
}
