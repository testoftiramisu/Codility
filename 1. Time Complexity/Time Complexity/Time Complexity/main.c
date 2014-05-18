//
//  main.c
//  Time Complexity
//
//  Created by Denys Khlivnyy on 5/18/14.
//  Copyright (c) 2014 Denys Khlivnyy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

// TapeEquilibrium
// Minimize the value |(A[0] + ... + A[P-1]) - (A[P] + ... + A[N-1])|.
// 100 out of 100 points
int TapeEquilibrium(int A[], int N) {
    
    long long sum = 0;
    int i = 0, j = 0;
    int min = 1000;
    
    if (N == 2) {
        return abs(A[0] - A[1]);
    }
    
    for(i = 0; i < N; i++)
    {
        sum += A[i];
    }
    
    long long left = 0;
    long long right = sum;
    int tmp = abs(left - right);
    
    for(j = 1; j < N; j++)
    {
        right -= A[j - 1];
        left += A[j - 1];
        
        tmp = abs(left - right);
        
        if (min > tmp)
        {
            min = tmp;
        }
    }
    
    return min;
}

// FrogJmp
// Count minimal number of jumps from position X to Y.
// 100 out of 100 points
int FrogJmp(int X, int Y, int D) {
    
    int result = 0;
    int dist = Y - X;
    result = dist / D;
    
    if (dist % D != 0) {
        result++;
    }
    
    return result;
}


int main(int argc, const char * argv[])
{
    
    // TapeEquilibrium testing
    int A[5];
    A[0] = 3;
    A[1] = 1;
    A[2] = 2;
    A[3] = 4;
    A[4] = 3;
    printf("1. TapeEquilibrium: %i\n", TapeEquilibrium(A, 5));
    
    int B[2];
    B[0] = -1000;
    B[1] = 1000;
    printf("   TapeEquilibrium: %i\n", TapeEquilibrium(B, 2));
    
    // Frog Jump testing:
    int X = 10, Y = 85, D = 30;
    printf("2. Frog jumps: %i\n", FrogJmp(X, Y, D));
    X = 1, Y = 1, D = 1;
    printf("   Frog jumps: %i\n", FrogJmp(X, Y, D));
    
}






