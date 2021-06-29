#include <iostream>
#include <vector>

using namespace std;

/*
    Using a simple pen paper approach of the sample test cases, we know that the first row goes to first column, second row goes to second column ...
    With this knowledge we have that intuition of tranpose of a matrix.

    So, this solution is basically based on using tranpose of a matrix, and then reverting each row of the matrix.
*/

void rotate(vector<vector<int>>& matrix) {
        
        // Transpose of the matrix
        for(int i = 0; i<matrix.size(); i++)
        {
            for(int j = 0; j<i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for(int i = 0; i<matrix.size(); i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }