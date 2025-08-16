#include <iostream>
#include <ostream>

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
*/

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *sum = nullptr;
    int current_value = 0;
    int old_value = 0;
    int carry_over = 0;
    while (l1 != nullptr || l2 != nullptr || carry_over != 0)
    {
        current_value += carry_over;
        if (l1 != nullptr) current_value+=l1->val;
        if (l2 != nullptr) current_value+=l2->val;

        old_value = current_value;
        current_value = current_value % 10;

        if (sum == nullptr)
        {
            sum = new ListNode(current_value);
        }
        else
        {
            sum = new ListNode(current_value, sum);
        }
        current_value = 0;
        carry_over = old_value / 10;
        if (l1 != nullptr) l1 = l1->next;
        if (l2 != nullptr) l2 = l2->next;
    }
    ListNode *revert = nullptr;
    while (sum != nullptr)
    {
        if (!revert)
        {
            revert = new ListNode(sum->val);
        }
        else
        {
            revert = new ListNode(sum->val, revert);
        }
        sum = sum->next;
    }

    return revert;
}

int main()
{
    ListNode *x = new ListNode(9);
    x = new ListNode(9, x);
    x = new ListNode(9, x);
    x = new ListNode(9, x);

    ListNode *y = new ListNode(9);
    y = new ListNode(9, y);
    y = new ListNode(9, y);
    y = new ListNode(9, y);
    y = new ListNode(9, y);
    y = new ListNode(9, y);
    y = new ListNode(9, y);

    ListNode *current = addTwoNumbers(x, y); //! 10,009,998
    while (current != nullptr)
    {
        cout << current->val << endl;
        current = current->next;
    }
}