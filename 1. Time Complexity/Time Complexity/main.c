//
//  main.c
//  Time Complexity
//
//  Created by Denys Khlivnyy on 5/18/14.
//  Copyright (c) 2014 Denys Khlivnyy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// TapeEquilibrium
// Minimize the value |(A[0] + ... + A[P-1]) - (A[P] + ... + A[N-1])|.
// 100 out of 100 points on Codility
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
// 100 out of 100 points on Codility
int FrogJmp(int X, int Y, int D) {
    
    int result = 0;
    int dest = Y - X;
    result = dest / D;
    
    if (dest % D != 0) {
        result++;
    }
    return result;
}

// PermMissingElem
// A zero-indexed array A consisting of N different integers is given.
// The array contains integers in the range [1..(N + 1)],
// One element is missing. Your goal is to find that missing element.
// 100 out of 100 points on Codility
int PermMissingElem(int A[], int N) {
    
    double sum = (pow(N, 2) + 3 * N + 2) / 2;
    int i;
    
    for (i = 0; i < N; i++) {
        sum -= A[i];
    }
    return (int)sum;
}


int main(int argc, const char * argv[])
{
    
    // TapeEquilibrium testing
    int A[5] = {3, 1, 2, 4, 3};
    printf("1. TapeEquilibrium: %i\n", TapeEquilibrium(A, 5));
    
    int B[2] = {-1000, 1000};
    printf("   TapeEquilibrium: %i\n", TapeEquilibrium(B, 2));
    
    // Frog Jump testing:
    int X = 10, Y = 85, D = 30;
    printf("2. Frog jumps: %i\n", FrogJmp(X, Y, D));
    X = 1, Y = 1, D = 1;
    printf("   Frog jumps: %i\n", FrogJmp(X, Y, D));
    
    // PermMissingElem testing:
    int C[100000];
    C[0] = 2;
    C[1] = 3;
    C[2] = 1;
    C[3] = 5;
    
    //
    for (int i = 4; i < 100000; i++) {
        C[i] = i + 2;
    }
    
    printf("3. PermMissingElem: %i\n", PermMissingElem(C, 100000));
    
    int arr[1] = {1};
    printf("   PermMissingElem: %i\n", PermMissingElem(arr, 1));
    
    int arr2[4] = {2, 3, 4, 5};
    printf("   PermMissingElem: %i\n", PermMissingElem(arr2, 4));
    
    
}






