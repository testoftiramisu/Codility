//
//  main.c
//  3 Prefix Sums
//
//  Created by Denys Khlivnyy on 5/20/14.
//  Copyright (c) 2014 Denys Khlivnyy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for returning of array
// C - pointer to the array
// L - array lenght
struct Results {
    int *C;
    int L;
};

// Prefix sum example
struct Results prefix_sums(int A[], int N) {
    
    struct Results result;
    int *p = calloc(N + 1,sizeof(int));
    
    int k = 1, tmp;
    
    for(k = 1; k <= N + 1; k++)
    {
        p[k] = p[k - 1] + A[k - 1];
        tmp = p[k];
    }
    
    result.C = p;
    result.L = N;
    return result;
}

// PassingCars
// Count the number of passing cars on the road
// 100 out of 100 points on Codility
int PassingCars(int A[], int N){
    
    int i = 0, east = 0, cars = 0;
    
    for (i = 0; i < N; i++)
    {
        if (A[i] == 0) {
            east += 1;
        }
        else {
            cars += east;
            if (cars > 1000000000) {
                return -1;
            }
        }
    }
    return cars;
}

// Genomic Range Query
// Find the minimal nucleotide from a range of sequence DNA.
// 100 out of 100 points on Codility
struct Results GenomicRangeQuery(char *S, int P[], int Q[], int M) {
    struct Results result;
    
    int i = 0, j = 0, tmp;
    long len = strlen(S);
    
    int arr[len][4];
    memset(arr, 0, len*4*sizeof(int));
    
    int *res = calloc(M, sizeof(int));
    
    // We keeping a "Prefix sum" of the number of occurences
    // of each letter from the set [A,C,G,T] for every character in a string.
    for(i = 0; i < len; i++) {
        if(S[i] == 'A') arr[i][0] = 1;
        if(S[i] == 'C') arr[i][1] = 1;
        if(S[i] == 'G') arr[i][2] = 1;
        if(S[i] == 'T') arr[i][3] = 1;
    }
    
    // Prefixes computing
    for(i = 1; i < len; i++){
        for(j = 0; j < 4; j++){
            arr[i][j] += arr[i-1][j];
        }
    }
    
    for(i = 0; i < M; i++){
        for(j = 0; j < 4; j ++){
            tmp = 0;
            if(P[i] - 1 >= 0){
                tmp = arr[P[i] - 1][j];
            }
            if(arr[Q[i]][j] - tmp > 0){
                res[i] = j + 1;
                break;
            }
        }
    }
    
    result.C = res;
    result.L = M;
    return result;
}

int main(int argc, const char * argv[])
{
    
    // prefix_sums test:
    int A[] = {1, 2, 3, 4, 5, 6, 7};
    struct Results s = prefix_sums(A, 7);
    
    printf("Array = {1, 2,... 7} \n");
    printf("Prefix sums: ");
    for (int i = 0; i <= s.L; i++)
    {
        printf("%i, ", (s.C[i]));
    }
    
    // Passing cars test
    int B[] = {0, 1, 0, 1, 1};
    printf("\nCars: %i ", PassingCars(B, 5));
    
    // Genomic Range Query test
    int P[] = {2, 5, 0};
    int Q[] = {4, 5, 6};
    char *S = "CAGCCTA";  // ACGT
    
    printf("\nGenomic Range Query:\n ");
    s = GenomicRangeQuery(S, P, Q, 3);
    for (int i = 0; i < s.L; i++)
    {
        printf("%i, ", (s.C[i]));
    }
               
    
}

