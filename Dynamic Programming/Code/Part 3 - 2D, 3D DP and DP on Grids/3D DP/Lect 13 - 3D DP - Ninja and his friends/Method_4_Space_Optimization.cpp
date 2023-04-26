// Topic : 3D DP
// Problem : Ninja and his friends

// Method 4 : Using Space Optimization (Bottom-Up DP --> Base Cases to Recursive Cases)

// Time Complexity : O(n*m*m*9)
// Reason : As we are using five nested For Loops. (n, m, m, 3, 3 iterations)


// Auxiliary Space Complexity : O(1)
// Reason : Auxiliary space take be recursion tree (i.e height of recursion tree)

// Non-Auxiliary Space Complexity : O(m*m)
// Reason : Using vector of vector data structure of m*m size

// Total Space Complexity : O(m*m)
// Reason : Sum of Auxiliary Space Complexity O(1) and Non-Auxiliary Space Complexity O(m*m) (i.e O(1) = O(1)+O(m*m))

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> matrix = {
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5}
    };
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> front(m, vector<int> (m, -1));

    for (int i = n-1; i >= 0; i--)
    {
        vector<vector<int>> current(m, vector<int> (m, -1));
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                if(i == n-1) {
                    if(j1 == j2) current[j1][j2] = matrix[i][j1];
                    else current[j1][j2] = matrix[i][j1] + matrix[i][j2];
                }
                else {
                    int maxi = INT_MIN;
                    for (int dj1 = -1; dj1 <= 1; dj1++)
                    {
                        for (int dj2 = -1; dj2 <= 1; dj2++)
                        {
                            if(!((j1+dj1 < 0 or j1+dj1 >= m) or (j2+dj2 < 0 or j2+dj2 >= m))) {
                                int value = 0;
                                if((j1+dj1) == (j2+dj2)) value = matrix[i][j1] + front[j1+dj1][j2+dj2];
                                else value = matrix[i][j1] + matrix[i][j2] + front[j1+dj1][j2+dj2];
                                maxi = max(maxi, value);
                            }
                        }
                    }
                    current[j1][j2] = maxi;
                }
            }
        }
        front = current;
    }

    cout<<"Answer : "<<front[0][m-1];
    return 0;
}