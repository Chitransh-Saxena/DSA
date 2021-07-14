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

std::string removeDup(std::string s)
{
    if(s.size() == 0)
        return "";
    
    // In each recursive call, a substring will be passed, and we only want to compare the first character of that substring
    char c = s[0];

    // Now we compare this character with the next character, but we have to do in such a way that we if the characters are matching, we remvove this element
    // We create a substring removing this stirng
    std::string ans = removeDup(s.substr(1));

    // Characters are same
    if(c == ans[0])
    {   
        // return the string with removed character 
        return ans;
    }

    // Else add that character back to the front
    else
    {
        return (c + ans);
    }


}

int main()
{
    std::string s = "aaaabbbbbccccddddeeeeffff";
    std::cout << removeDuplicates(s) << std::endl;
}