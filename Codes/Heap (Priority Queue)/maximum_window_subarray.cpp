/*
    Question  - https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1#
    In a given array of size n, we are given a integer 'k'.
    So, from that array, we have to find the maximum element in the window of k elements.
    
    Approaches :
    1. 
        -> I used heap data structure appraoch, but somehow i could not optimize it so at the end it gave TLE
        -> Basically just enter the 3 numbers into a max heap and get the top
        -> But the logic of popping off one element to enter another from a new window was not correct
    
    2. youtube approach - Dequeue ( https://www.youtube.com/watch?v=XDJKHtXJHBY )
        -> In this approach, we use a deque
        -> And in this deque, we maintain what elements are we inserting
        -> We insert only largest and second largest element in the deque, because if we move forward, and the largest element has to pop off, we still have a potential candidate for largest which is just 1 comparison away
        -> So, we handle 2 main cases here
            -> If the current maximum element in the deque belongs to this new window, if not we pop it off and 
            -> The current array element has to be either greatest or second greatest element
        -> Since we are inserting indices in the dequeue, it is easier to maintain which element has to go in the window and which has to go out

*/

class Solution{
    public:
        
    vector <int> max_of_subarrays(int *a, int n, int k){
        
        vector<int> ans;
        deque<int> dq; 
        
        int i = 0;
        for(; i<k; i++) {
            
            // If my last element in the deque is smaller or equal to current element, I am removing this element 
            // Doing this because deque only has to store updated 2 large elements
            while(!dq.empty() && a[dq.back()] <= a[i]) {
                
                dq.pop_back();
            }
            dq.push_back(i);                // NOTE: WE ARE INSERTING INDEX, NOT THE ELEMENT    
        }
        
        // At this point, previous window's ggreatest element is at 1st position of the deque
        for(; i < n; i++) {
            
            ans.push_back(a[dq.front()]);               // Greatest from the previous window has to go in the answer vector now


            // Check if the first element of the deque is present in the current window, if not pop it off
            while(!dq.empty() && dq.front() <= i-k) {
                dq.pop_front();
            }
            
            // Again we are checking if the current array element is greater than last element of the queue
            // If yes, we remove the last element of the queue
            // We do this until we are sure that either queue is empty, or the element it holds is greater than current element (We already made sure it is in window)
            while(!dq.empty() && a[dq.back()] <= a[i]) {
                
                dq.pop_back();
            }
            dq.push_back(i);
            
        }
        ans.push_back(a[dq.front()]);
        
        return ans;
    };