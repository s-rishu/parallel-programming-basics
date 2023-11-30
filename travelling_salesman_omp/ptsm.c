#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <omp.h>

// void permutate(int height){
//     if(height == 1){
//         #pragma omp critical
//         if(opt_weight_local < opt_weight){
//             opt_weight = opt_weight_local;
//             opt_path = opt_path_local;
//         }
//         return;
//     }
//     int temp;

//     for(int i = 0, i < height; i++){
//         //swap ith element and buffer height - 1th element
//         temp = opt_path_local[i]
//         opt_path_local[i] = opt_path_local[height -1]
//         opt_path_local[height -1] = temp

//         permutate(height-1)

//         //swap back ith element and buffer height - 1th element
//         temp = opt_path_local[i]
//         opt_path_local[i] = opt_path_local[height -1]
//         opt_path_local[height -1] = temp
//     }
// }

int main(int argc, char** argv){
    
    //get input arguments
    int x = atoi(argv[1]);
    int t = atoi(argv[2]);
    int input_file_path = atoi(argv[3]);

    //initialize 2d matrix for weights
    int weights[12][12];

    //read input
    FILE *input;  
    size_t count;
    char *line = malloc(100);
    int i = 0;
    int j = 0;
    input = fopen(input_file_path, "r"); 
    // TODO: parallelize if possible
    for(i = 0; i<x; i++) {
        getline(&line, &count, input)
        for (; count > 0; count--, j++)
            sscanf(line, "%d", &input[i][j]);
            //debug
            printf("%d ", input[i][j])
        i++;
    }


    // //find optimal path and weight sum
    // int opt_weight = INT_MAX;
    // int opt_path[12];
    // for(i = 0; i<x; i++) {
    //     int opt_path_local[12];
    //     int opt_weight_local = 0;
    //     opt_path_local[x-1] = i;
    //     permutate(x-1);
    // }

    return 0;
}
