/*
    Assume we are given a binary number and we want to form integer out of it
    num = 101

    Now, one way is, that we learnt from college 
    -> Iterate from back side
    -> (2^0 + 1) + (2^1 + 0) + (2^2 + 1)
    -> Answer = 5

    But what if we can only iterate from the front ?

    -> keep first digit as it is, ans = 1;
    -> for second iteration (0) - ans += 1(i)*2 + 0, at this point answer = 1 + (1*2 + 0) = 3       -> i being the iterator for number indexing starting from 1
    -> For third iteration (1) - ans += 2(i)*2 + 1,    ans = 5
*/


int getIntegerFromBinary(string num) {

    int ans = num[0];

    for(int i = 1; i<num.size(); i++) {

        int digit = stoi(num[i]);
        ans = (ans*2 + digit);
    }

    return ans;

}