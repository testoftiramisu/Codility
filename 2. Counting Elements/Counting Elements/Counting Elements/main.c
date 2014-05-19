//
//  main.c
//  Counting Elements
//
//  Created by Denys Khlivnyy on 5/19/14.
//  Copyright (c) 2014 Denys Khlivnyy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


// PermCheck
// Check whether array A is a permutation.
// 100 out of 100 points on Codility
int solution(int A[], int N) {
    
    int *arr = calloc(N, sizeof(int));
    int i;
    
    for (i = 0; i < N; i++) {
        if (A[i] > N) {
            return 0;
        }
        else if(arr[A[i] - 1] == 1) {
            return 0;
        }
        else {
            arr[A[i] - 1] = 1;
        }
    }
    
    free(arr);
    
    return 1;
}


int main(int argc, const char * argv[])
{
    
    
    
    int A[] = {4,1, 3, 2};
    int B[] = {4, 1, 3};
    int C[] = {2147483646};
    
    printf("Permutation: %i\n", solution(A, 4));
    printf("Permutation: %i\n", solution(B, 3));
    printf("Permutation: %i\n", solution(C, 1));
    
    
}

