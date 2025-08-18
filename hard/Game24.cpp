#include <iostream>
#include <ostream>
#include <cmath>
#include <vector>
#include <list>
/*
You are given an integer array cards of length 4. You have four cards, each containing a number in the range [1, 9].
You should arrange the numbers on these cards in a mathematical expression 
using the operators ['+', '-', '*', '/'] and the parentheses '(' and ')' to get the value 24.

You are restricted with the following rules:

    The division operator '/' represents real division, not integer division.
        For example, 4 / (1 - 2 / 3) = 4 / (1 / 3) = 12.
    Every operation done is between two numbers. In particular, we cannot use '-' as a unary operator.
        For example, if cards = [1, 1, 1, 1], the expression "-1 - 1 - 1 - 1" is not allowed.
    You cannot concatenate numbers together
        For example, if cards = [1, 2, 1, 2], the expression "12 + 12" is not valid.

Return true if you can get such expression that evaluates to 24, and false otherwise.

 

Example 1:

Input: cards = [4,1,8,7]
Output: true
Explanation: (8-4) * (7-1) = 24

Example 2:

Input: cards = [1,2,1,2]
Output: false

 

Constraints:

    cards.length == 4
    1 <= cards[i] <= 9

*/
using namespace std;
vector<char> operations = {'+', '-', '*', '/'};

int applyOperation(char op, int l, int r)
{
    switch (op)
    {
    case '+': return l + r;
    case '-': return l - r;
    case '*': return l * r;
    case '/': return l / r;
    default: return 0;
    }
}

void getAllConfigurationsForFirst(vector<int> set, vector<int> rest, vector<vector<int>> &configurations)
{
    if (rest.empty()) 
    {
        configurations.push_back(set);
    }
    else
    {
        vector<int>::iterator itr = rest.begin();
        vector<int>::iterator next;
        while (itr != rest.end())
        {
            cout << *itr  << "//" << rest.size() << endl;
            set.push_back(*itr);
            itr = rest.erase(itr);
            getAllConfigurationsForFirst(set, rest, configurations);
        }
    }
}
vector<vector<int>> generateOrders(vector<int> &cards)
{
    vector<vector<int>> all_orders;
    for (vector<int>::iterator it = cards.begin(); it != cards.end(); it++)
    {
        vector<int> cpy_cards;
        std::copy( cards.begin(), cards.end(), std::back_inserter(cpy_cards));
        cpy_cards.erase(it);
        int first = *it;
        
        // all_orders.push_back(one_order);
    }
    return all_orders;
}
vector<string> generateExpressions(vector<vector<int>> &all_pairs, vector<char> &ops)
{
    vector<string> expressions;
    for (vector<int> v : all_pairs)
    {

    }
}

bool judgePoint24(vector<int>& cards) {
    return false;
}

int main()
{
    vector<int> pairs = {4, 1, 8, 7};
    vector<vector<int>> configuration = {};
    getAllConfigurationsForFirst({}, pairs, configuration);
    for (vector<int> v : configuration)
    {
        for (int i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}