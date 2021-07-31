class Solution{
    
    public void helper(ArrayList<Integer> arr, int N, int pos, int sum, ArrayList<Integer> subSum) {
        
        if(pos == N) {
            subSum.add(sum);
            return;
        }
        
        helper(arr, N, pos+1, sum + arr.get(pos), subSum);
        helper(arr, N, pos+1, sum, subSum);
        
    }
    
    ArrayList<Integer> subsetSums(ArrayList<Integer> arr, int N){
        
        ArrayList<Integer> subSum = new ArrayList<>();
        helper(arr, N, 0, 0, subSum);
        
        Collections.sort(subSum);
        return subSum;
    }
}