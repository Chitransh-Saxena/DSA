
/* Print all permutations of a string

String s = "ABC"

The task is to print all permutations of this string in lexographic order.

Approach taken:

* We take a character of the string, swap that character by all the characters of the string one by one.
* So, ideally, all the characters of the string would be swapped by all the characters of the string

* So, for Example, we have the string ABC. In first iteration, we choose to swap A by A, so the formed string would be ABC. Now, there are 2 more characters left. We keep A as it is, and swap A by B.
So, now the string formed is BAC. Repeating this process again, swapping A by C, we get CAB.

* Now in we have 3 strings. ABC, BAC and CAB.

* In these strings, we permutate recursively. So, if pick ABC, since we have already swapped A with A, we fix that and move on to next characters. We have 2 characters left, so we do 2 things.
* We swap, B by B. This gets us ABC. Then we swap B by C, this gets us ACB.

* So, repeating this process for BAC and CAB. We get all the required permutations

* Number of unique permutations would be n!.



Code:

void print_permutations(string s, int left, int right) {
	
	// Base case would be defined as to when we have reached the right most end of the string for swapping characters.
	if( left == right) {
		cout << s << " ";
	}
	else {
		for(int i = left; i<=right; i++) {
			
			swap(s[l], s[i]);		//Swap string's left index with the moving index, so this will eventually swap all the indices on the right with current index.
			print_permutations(s, l+1, r);		// Recursive call to the function, here we have moved the left index to one position to right. This will allow us to traverse through the string to right.
			swap(s[l], s[i]); 		// With this, we create back the original string. So that the standard algorithm for swap and permutate could be followed without changing the string. Otherwise, we would miss some permutations.
		}
	}
}

*/