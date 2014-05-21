//
//  main.c
//  Linked list
//
//  Created by Denys Khlivnyy on 5/21/14.
//  Copyright (c) 2014 Denys Khlivnyy. All rights reserved.
//

#include <stdio.h>

struct IntList {
    int value;
    struct IntList *next;
};

// (Demo task) Linked list
// Compute the length of single-link list without a loop
// 100 of 100 on Codility
int solution(struct IntList * L) {
    int count = 0;
    
    while (L != 0 ) {
        count += 1;
        L = L->next;
    }
    
    return count;
    
}

int main(int argc, const char * argv[])
{
    // To-Do:
    // Add some test cases
}

