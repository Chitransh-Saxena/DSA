/*
    Simply just add a number and handle the carry
*/


vector<int> plusOne(vector<int>& digits) {
        
        if(digits.size() == 1)
        {
            if(digits[0] + 1 > 9) {
                
                int num = digits[0] + 1;
                int n2 = num%10;
                num/=10;
                int n1 = num;
                return {n1,n2};
            }
            else {
                return {digits[0]+1};
            }
        }
        
        vector<int> ans;
        
        int x = digits[digits.size()-1];
        x+=1;
        int num, carry;
        if(x>9) {
            
            num = x%10;
            x/=10;
            carry = x;
        }
        else {
            num = x;
            carry = 0;
        }
        
        digits[digits.size()-1] = num;
        
        
        
        for(int i = digits.size()-2; i > 0; i--) {
            
            int n = digits[i];
            n = n + carry;

            if(n > 9) {
                
                num = n % 10;
                n /= 10;
                carry = n;
                digits[i] = num;
            }
            else {
                num = n;
                digits[i] = num;
                carry = 0;
                break;
            }
                   
        }
        
        if(carry != 0) {
            
            digits[0] += carry;
            
            if(digits[0] > 9) {
                
                int n2 = digits[0] % 10;
                digits[0] /= 10;
                int n1 = digits[0];
                
                digits[0] = n2;
                digits.insert(digits.begin(), n1);
            }
        }
        return digits;
        
    }