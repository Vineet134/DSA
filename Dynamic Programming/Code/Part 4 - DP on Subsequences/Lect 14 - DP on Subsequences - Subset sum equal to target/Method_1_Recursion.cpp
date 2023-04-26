// Topic : DP on Subsequences
// Problem : Subset sum equal to k

// Method 1 : Using Recursion (Top-Down Approach --> Recursive Cases to Base Cases)

// Time Complexity : O(2^n)
// Reason : As we are calling 2 recursive calls for n times


// Auxiliary Space Complexity : O(n)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree == no. of rows)

// Non-Auxiliary Space Complexity : O(1)
// Reason : No use of any data structure (like array, vector, matrix, etc)

// Total Space Complexity : O(n)
// Reason : Sum of Auxiliary Space Complexity O(n) and Non-Auxiliary Space Complexity O(1) (i.e O(n) = O(n) + O(1))

#include <bits/stdc++.h>
using namespace std;

bool f(int ind, int target, vector<int>& arr) {
    // Base Case
    if(target == 0) return 1;
    if(ind == 0) {
        if(arr[0] == target) return 1;
        else return 0;
    }

    // Recursive Case
    bool notPick = f(ind-1, target, arr);
    bool pick = 0;
    if(target >= arr[ind]) {
        pick = f(ind-1, target-arr[ind], arr);
    }
    return notPick or pick;
}

int main()
{
    vector<int> arr{2, 3, 1, 1};
    int n = arr.size(), k = 4;
    
    cout<<"Answer : "<<(f(n-1, k, arr) ? "true" : "false");
    return 0;
}