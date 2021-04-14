/*
    Given k arrays in the form of a vector
    Merge them such that they are all sorted

    Approach - 

    -> Since all of the rows of this matrix we have are sorted
    -> We pick the first element of each row and put them in a priority queue
    -> Then we remove the top element (smallest) and add it into answer vector
    -> Then we add next element of that same row in priority queue and repeat the same process
    -> Because we need to keep track of which element belongs to which column and which row, we use a custom data structure
*/


struct qDS{
    int val;
    int row;
    int col;
    
    qDS(int v, int r, int c) {
        val = v;
        row = r;
        col = c;
    }
};


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        //code here
        
        // Add first element of each row in a priority queue
        // Add the smallest element into the resulting array
        // Remove that element from the priority queue (extract_min) and add next element of that row
        
        // We need custom ds to keep track of row and columns
        
        vector<int> ans;
        // value at arr[i][j], and i
        
        auto comparator = [](qDS d1, qDS d2) -> bool{
          
          return d1.val > d2.val;  
        };
        priority_queue<qDS, vector<qDS>, function<bool(qDS d1, qDS d2)>> pq(comparator);
        
        
        for(int i = 0; i < k; i++) {
           
            qDS p(arr[i][0], i, 0);
            pq.push(p);
        }
        
        while(pq.size() > 0) {
            
            qDS p = pq.top();
            pq.pop();
            ans.push_back(p.val);
            
            p.col++;
            if(p.col < k) {
                qDS q(arr[p.row][p.col], p.row, p.col);
                pq.push(q);
            }
            
            // Now how do we figure out to which row did this element belong to?
        }
        
        return ans;
    }
};
