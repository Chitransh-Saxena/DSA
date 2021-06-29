#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
        // NOTE: For original matrix, below 2 variables would be reversed, but for a transpose, number of rows becomes number of columns and vice versa
        int cols = matrix.size();
        int rows = matrix[0].size();
        
        // Init a 2-D vector, for all rows(which have a vector), init them with 0
        vector<vector<int>> tranny (rows, vector<int>(cols, 0));
        
        // If the above part is too hard to understand, just do a double for loop and init with 0
        
        for(int i = 0; i<cols; i++)
        {
            for(int j = 0; j<rows; j++)
            {
                tranny[j][i] = matrix[i][j];
            }
        }
        
        return tranny;
    }