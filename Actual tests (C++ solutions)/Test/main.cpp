//
//  main.cpp
//  Test
//
//  Created by Denys Khlivnyy on 5/22/14.
//  Copyright (c) 2014 Denys Khlivnyy. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Solution1
int solution1(vector<int> &A) {
    
    vector <int> B = A;
    int i;
    
    sort(B.begin(), B.end());
    
    for(i = 0; i< A.size();i++){
        if(upper_bound(B.begin(), B.end(), A[i]) - lower_bound(B.begin(), B.end(), A[i]) == 1){
            return A[i];
        }
    }
    
    return -1;
}

// Solution2
// The goal is to find a missing element from an array
int solution2(vector<int> &A) {
	
    int n = (int)A.size(), i;
	vector<bool> B(n + 2);
    
	for (i = 0; i < n; i++) {
		if (A[i] <= 0 || A[i] > n + 1) continue;
		B[A[i]] = true;
	}
	for (int i = 1; i <= n + 1; i++) {
		if (!B[i]) return i;
	}
    
    return -1; // actually, we should never get there
}

// Solution3
int solution3(int N) {
    
    int ans = 0, i;
    
    for(i = 1; i * i <= N; i++) {
        
        if(N % i == 0){
            ++ans;
            if( N / i != i) ++ans;
        }
    }
    return ans;
}

int main(int argc, const char * argv[])
{
    std::cout << "To Do:  - Write some tests for a Solutions\n";
    std::cout << "To Do:  - Add a description for Tasks\n";
    
    std::cout << solution3(60);
    
    return 0;
}



