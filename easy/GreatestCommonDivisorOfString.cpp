#include <iostream>
#include <ostream>
#include <string>

/*
For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"

Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"

Example 3:

Input: str1 = "LEET", str2 = "CODE"
Output: ""
*/

using namespace std;

bool checkIfBuiltOf(string t, string s)
{
    for (size_t i = 0; i < s.size(); i+=t.size())
    {
        if (s.substr(i, t.size()) != t) return false;
    }
    return true;
}

string gcdOfStrings(string str1, string str2)
{
    string equal_buffer("");
    string result("");
    for (size_t i = 0; i < (str1.size() < str2.size() ? str1.size() : str2.size()) ; i++) //! iterate over the smaller
    {
        if
        (
            str1.at(i) == str2.at(i)            
        ) {
            equal_buffer += str1.size() < str2.size() ? str1.at(i) : str2.at(i); //! add if equal 
            if (checkIfBuiltOf(equal_buffer, str1) && checkIfBuiltOf(equal_buffer, str2))
            {
                result = equal_buffer;
            }
        }
        else
        {
            break;
        }
    }

    return result;
}
int main()
{

    return 0;
}
/*
Way better solution:
string gcdOfStrings(string str1, string str2) {
    return (str1 + str2 == str2 + str1)? 
    str1.substr(0, gcd(size(str1),size(str2))): "";
}

*/