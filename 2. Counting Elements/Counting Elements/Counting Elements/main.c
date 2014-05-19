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
int PermCheck(int A[], int N) {
    
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

// FrogRiverOne
// Find the earliest time when a frog can jump to the other side of a river.
// 100 out of 100 points on Codility
int FrogRiverOne(int X, int A[], int N) {
    
    int i, jmp = 0;
    int arr[X];
    
    for (i = 0; i < X; i++)
    {
        arr[i] = -1;
    }
    
    for (i = 0; i < N; i++){
        
        if (arr[A[i] - 1] == -1) {
            arr[A[i] - 1] = i;
            jmp +=1;
            
            if (jmp == X) {
                return i;
            }
        }
    }
    
    return -1;
    
}



int main(int argc, const char * argv[])
{
    
    
    
    int D[] = {4,1, 3, 2};
    int B[] = {4, 1, 3};
    int C[] = {2147483646};
    
    printf("Permutation: %i\n", PermCheck(D, 4));
    printf("Permutation: %i\n", PermCheck(B, 3));
    printf("Permutation: %i\n", PermCheck(C, 1));
    
    int A[8] = {1, 3, 1, 4, 2, 3, 5, 4};
    
    printf("Frog jump time: %i\n", FrogRiverOne(5, A, 8));
    
    
    
    
}

