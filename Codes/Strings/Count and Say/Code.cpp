// Count And Say

/* The question is very tricky in itself.
	If we have a number 123, we should say it as "One 1, One 2, One 3", or if we have a number 113225, we say it as "Two 1, One 3, Two 2, One 5"
	So, the resulting strings for above 2 cases would be "111213" and "21132215"
	This being said, now coming to the main question
	
	Base case is given as "1"
	If we iterate it once (second time) - we say it as "One 1", resulting in "11"
	iterating above string (3rd iteration of original string) - we say it as "Two 1", resulting in "21"
	iterating once more(4th time) - we say it as "One 2, One 1", resulting in "1211'
	... this can go on.
	
	Question is, given a number, we have to tell the resulting string from the base case of "1".
	Example - n = 4, this would result in 1211 (Above explaination)
	
*/

/* Approach:

	The approach is pretty basic, doing what I wrote above in terms of code.
	Loop for the number of iterations given in question - 
	In each iteration, count the number of consecutive digits coming, prepend that to digit itself, (11 becomes "two 1s" or "21")
	Now this becomes new string, so we iterate this string in the next iteration.

*/

class Solution {
public:
    
    string countAndSay(int n) {
        string s = "1";     // Base string
        while(--n>0) {
            
            string ns;      //New string for each case
            int i =0 ;      //to iterate through the new string
            
            while(i<s.size()) {
                int count = 1;      //Count of a number in string
                while(i + 1 < s.size() && s[i] == s[i+1]){  // Loop to count digits and append them to new string accordingly
                    ++i;        // at last iteration the 'i' pointer will be at last digit of the contigous digits
                    ++count;
             
                }
                
                ns +=to_string(count) + s[i];
                ++i;
            }
            s = ns;
        }
        
        return s;
    }
};