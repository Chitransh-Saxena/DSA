#include <iostream>
#include <set>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
        
        set<pair<int, int>> s;
        
        for(int i = 0; i<matrix.size(); i++)
        {
            for(int j = 0; j<matrix[i].size(); j++)
            {
                if(matrix[i][j] == 0)
                {
                    s.insert(make_pair(i, j));
                }
            }
        }
        
        
        for(int i = 0; i<matrix.size(); i++)
        {
            for(int j = 0; j<matrix[i].size(); j++)
            {
                pair<int, int> p;
                p.first = i;
                p.second = j;
                if(s.find(p) != s.end())
                {
                    std::fill(matrix[p.first].begin(), matrix[p.first].end(), 0);
                    for(int k = 0; k<matrix.size(); k++)
                    {
                        matrix[k][p.second] = 0;
                    }
                }
            }
        }
    }