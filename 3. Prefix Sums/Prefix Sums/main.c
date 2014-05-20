//
//  main.c
//  3 Prefix Sums
//
//  Created by Denys Khlivnyy on 5/20/14.
//  Copyright (c) 2014 Denys Khlivnyy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

// Struct for returning of array
// C - pointer to the array
// L - array lenght
struct Results {
    int *C;
    int L;
};

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
int solution(int A[], int N){
    
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
    printf("\nCars: %i ", solution(B, 5));
    
}

