#include <iostream>

// TODO - Do it again


std::string removeDuplicates(std::string s)
{
    if(s.size() == 0)
        return "";

    char c = s[0];
    std::string ans = removeDuplicates(s.substr(1));

    // If we see a duplicate, we remove that element from string
    if(c == ans[0])
    {
        return ans;
    }

    // Order in which it is appended it matters
    // If append 'c', then basically we are taking a character and putting it at the end
    // That will be wrong, because now the logic will consider this as unique, and place it at the back, and we will end up duplicates again
    return (c + ans);


}

int main()
{
    std::string s = "aaaabbbbbccccddddeeeeffff";
    std::cout << removeDuplicates(s) << std::endl;
}