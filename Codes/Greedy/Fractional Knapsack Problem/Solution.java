/*

    Approach
        -> Intuitively, sorting on the basis of value / weight ratio 
            -> If we sort by value, weight factor will get messed up
            -> Sorting by weight is just wrong
        
        -> So, just sort the items based on the heighest value per unit weight
        -> Now, add the item to knapsack based on capacity




        This took my a while because I was not casting to double properly

*/




/*
class Item {
    int value, weight;
    Item(int x, int y){
        this.value = x;
        this.weight = y;
    }
}
*/

class Solution
{
    /*
        Sort on the basis of ratio in descending order
    */
    
    class sortKnap implements Comparator<Item> {
        
        public int compare(Item a, Item b) {
            
            double x = (double)a.value / (double)a.weight;
            double y = (double)b.value / (double)b.weight;
            
            if(x < y)   return 1;
            if(x > y)   return -1;
            
            return 0;
        }
    }
    
    double fractionalKnapsack(int W, Item arr[], int n) 
    {
        Arrays.sort(arr, new sortKnap());
        
        double ans = 0.0;
        
        int cap = W;
        
        for(int i = 0; i<n; i++) {
            
            if(arr[i].weight > cap) {
                
                // Get the fractional weight and add it
                double val = ((double)arr[i].value / (double)arr[i].weight) * (double)cap;
                ans+=val;
                
                cap = 0;
                break;
                
            }
            else {
                cap = cap - arr[i].weight;
                ans+=arr[i].value;
            }
            
        }
        
        return ans;
    }
}