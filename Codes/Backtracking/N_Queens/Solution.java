class Solution {
    
    
    /*
        Approach
        -> Start step by step and generate solutions by keeping queen in all possible ways
            -> If they clash, that solution is wrong
        -> If I think what could be the solution starting from an empty board, I will keep the queen at 0,0 first
            -> And I will start placing other queens consecutively
        
        -> Precisely this is what we are gonna do, but with an additional step of backtracking in case our answer is wrong
        -> Once we find a way to add a queen to a certain row of one particular column, we will call the recursive function
            -> In case that solution fails, we remove that queen, and backtrack from there
            -> If that solution works, we make another recursive call with this new configuration
    */
    
    private boolean canAdd(char[][] board, int n, int i, int j) {
        
        /* When can we add an element to this current cell (i,j)?
            
            -> If there is nothing on the right and left ([i][0-n])
            -> If there is nothing on the diagonals (0,0 -> n-1,n-1 && i==j) && (n-1,0 -> 0,n-1 && (i+j == (n-1)))
            
        */
        
        for(int x = 0; x<j; x++) {
            if(board[i][x] == 'Q') {
                return false;
            }
        }
        
        // Top Left Diagonal
        int x = i, y = j;
        while(x >= 0 && y>=0) {
            
            if(board[x][y] == 'Q') {
                return false;
            }
            
            x-=1;
            y-=1;
        }
        
        // Bottom Left Diagonal
        x = i; y = j;
        while(x<n && y>=0) {
            
            if(board[x][y] == 'Q') {
                return false;
            }
            
            x+=1;
            y-=1;
        }
        
        return true;
        
    }
    
    private List<String> makeList(char[][] board, int n) {
        
        List<String> list = new ArrayList<>();
        
        for(int i = 0; i<n; i++) {
            String item = "";
            for(int j = 0; j<n; j++) {
                
                item+=board[i][j];
            }
            list.add(item);
        }
        
        return list;
    }
    
    
    public void helper(List<List<String>> ans, char[][] board, int n, int col) {
        
        if(col == n) {
            
            ans.add(makeList(board, n));
            return;
        }
        else {
            
            for(int i = 0; i<n; i++) {
                if(canAdd(board, n, i, col)) {
                    
                    // If we can add this element to the board, we will add it and call recursion with the new formation
                    // We will backtrack after calling the recursion to move forward with next possibility
                    
                    board[i][col] = 'Q';
                    helper(ans, board, n, col+1);
                    board[i][col] = '.';
                }
            }
        }
    }
    
    
    
    
    public List<List<String>> solveNQueens(int n) {
    
        List<List<String>> ans = new ArrayList<List<String>>();
        
        // Intially the board is blank, we will add queens to it, once properly made, we will add this to answer List.
        // All such possible boards will be added to answer String
        char[][] board = new char[n][n];
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                board[i][j] = '.';
            }
        }
        
        
        helper(ans, board, n, 0);
        return ans;
    }
}