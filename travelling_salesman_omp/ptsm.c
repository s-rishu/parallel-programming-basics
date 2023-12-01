#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <omp.h>

int opt_weight = INT_MAX;
int opt_path[12];
int weights[12][12];

void permutate(int height, int opt_weight_local, int opt_path_local[]){
     if(height == 0){ //end of a single permutation
        #pragma omp critical
        if(opt_weight_local < opt_weight){
            opt_weight = opt_weight_local;
            for(int k = 0; k < 12; k++){
                opt_path[k] = opt_path_local[k];
            }
        }
        return;
    }
    int temp;

    for(int i = 0; i < height; i++){
        //swap ith element and buffer height - 1th element
        temp = opt_path_local[i];
        opt_path_local[i] = opt_path_local[height -1];
        opt_path_local[height -1] = temp;
       
        permutate(height-1, opt_weight_local +  weights[opt_path_local[height]][opt_path_local[height-1]], opt_path_local);

        //swap back ith element and buffer height - 1th element
        temp = opt_path_local[i];
        opt_path_local[i] = opt_path_local[height -1];
        opt_path_local[height -1] = temp;
    }
}

int main(int argc, char** argv){

    //get input arguments
    int x = atoi(argv[1]);
    int t = atoi(argv[2]);
    char* input_file_path = argv[3];

    //read input
    FILE *input;
    size_t count;
    char *line = malloc(200);
    char* token;
    char* start;
    int i;
    int j;
    input = fopen(input_file_path, "r");
    for(i = 0; i<x; i++) {
        getline(&line, &count, input);
        start = line;
        for (j = 0; j < x; j++) {
                weights[i][j] = strtol(start, &token, 10);
                start = token;
        }
    }

    //find optimal path and weight sum

    #pragma omp parallel for num_threads(t)
    for(int i = 0; i < x; i++) {
        int opt_path_local[12];
        //initialize opt_path_local
        for(int k = 0; k <x; k++){
                opt_path_local[x-k-1]  = k;
        }
        permutate(x-1, 0, opt_path_local);
    }

    // print result
    printf("Best path: ");
    for(int k = 0; k < x; k++){
         printf("%d ", opt_path[x-k-1]);
    }
    printf("\nDistance: %d\n", opt_weight);

    return 0;
}
