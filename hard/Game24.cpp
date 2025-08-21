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
int evaluateExpression(vector<int> cards, vector<char> ops)
{
    for (size_t i = 0; i < cards.size() - 1; i++)
    {
        cards.at(i+1) = applyOperation(ops.at(i), cards.at(i), cards.at(i+1));
    }
    return cards.at(cards.size()-1);
}

void getAllConfigurationsForCards(vector<int> set, vector<int> rest, vector<vector<int>> &configurations)
{
    cout << "called with rest of size: " << rest.size() << endl;
    if (rest.empty()) 
    {
        configurations.push_back(set);
    }
    else
    {
        for (size_t i = 0; i < rest.size(); i++)
        {
            vector<int> set_cpy = set;
            vector<int> rest_cpy = rest;

            set_cpy.push_back(rest.at(i));

            cout << "deleting this itr: " << *(rest_cpy.begin() + i) << " with index: " << i << endl;
            rest_cpy.erase(rest_cpy.begin() + i);
            getAllConfigurationsForCards(set_cpy, rest_cpy, configurations);
        }        
    }
}

vector<string> generateExpressions(vector<vector<int>> &all_pairs, vector<vector<char>> &ops)
{
    vector<string> expressions;
    string s;
    for (vector<int> order : all_pairs)
    {
        for (vector<char> all_op : ops)
        {
            s = "";
            for (int i = 0; i < 3; i++)
            {
                s += to_string(order.at(i)) + to_string(all_op.at(i)); 
            }
            s += to_string(order.at(3));
            expressions.push_back(s);
        }
    }
}

vector<vector<vector<char>>> getOperationsForConfig(int nb_config, vector<char> ops)
{
    for (int i = 0; i < nb_config; i++)
    {

    }
}

bool judgePoint24(vector<int>& cards) {
    return false;
}

int main()
{
    vector<int> cards = {1, 2, 3, 4};
    vector<char> ops = {'+', '-'};
    // cout << evaluateExpression(cards, ops) << endl;
    // vector<vector<int>> configuration = {};
    // getAllConfigurationsForCards({}, cards, configuration);
    // int i = 0;
    // for (vector<int> v : configuration)
    // {
    //     cout << "config: " << i << endl;
    //     for (int i : v)
    //     {
    //         cout << i << " ";
    //     }
    //     i++;
    //     cout << endl;
    // }
}