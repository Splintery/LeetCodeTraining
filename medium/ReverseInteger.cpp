#include <iostream>
#include <ostream>
#include <cmath>
#include <limits.h>

/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321

Example 2:

Input: x = -123
Output: -321

Example 3:

Input: x = 120
Output: 21

 

Constraints:

    -231 <= x <= 231 - 1

*/
using namespace std;

int reverse(int x)
{
    unsigned int ux = x < 0 ? -x : x;
    cout << "UX: " << ux << endl;
    string s = to_string(ux);
    int sign = x < 0 ? -1 : 1;
    int reversed = 0;
    for (int i = s.size()-1; i >= 0; i--)
    {
        // cout << "i: " << i << "is value: " << s.at(i) << endl;
        if (((int)s.at(i) - '0') * pow(10, i) < INT_MAX && ((int)s.at(i) - '0') * pow(10, i) > INT_MIN) 
        {
            reversed+= ((int)s.at(i) - '0') * pow(10, i);
        }
        else
        {
            return 0;
        }
        
        // cout << "int at index: " << ((int)s.at(i) - '0') * pow(10, i) << endl;
    }
    return reversed * sign;
}

int main()
{
    int x = -123;
    int y = reverse(x);
    cout << "reversed: " << x << ": " << y << endl;
}