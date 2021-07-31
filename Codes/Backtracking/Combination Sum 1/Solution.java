/*
    Via basic pen-paper approach, we understand, that at each step we have an option of either picking or not picking a number
    So, at each step, we have 2 choices

        -> Pick this current number and add it to your subset
            -> And subtract this number from target
        
        -> Don't pick this current number, move on to next position and take your current target with you

    
    
    NOTE: In code, we see that the move (function call) to move to next index is done outiside the condititional logic. Why?
        -> If we don't do that, we are bound by some constraint to move to next position.
        -> If we are not able to move, then we will never be able to add any subset to the resulting set

*/


class Solution {
    
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    
    public void helper(int[] candidates, int target, int pos, List<Integer> subset) {
        
        if(pos == candidates.length) {
            
            if(target == 0) {
                
                ans.add(new ArrayList<Integer>(subset));
            }
            
            return;
        }
        
        if(target > 0) {
            
            
            subset.add(candidates[pos]);
            helper(candidates, target - candidates[pos], pos, subset);
            
            subset.remove(subset.size() -1);
        }
        
        // If we keep this part inside the if condition, this might never increment the value of pos, and thus never meet the candidates.lenth condition
        // Now, because of this, subset might never get added to ans
        // Thus, an empty set would be returned to us
        helper(candidates, target, pos + 1, subset);
        
    }
    
    
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        
        
        List<Integer> subset = new ArrayList<Integer>();
        helper(candidates, target, 0, subset);
        return ans;
    }
}
