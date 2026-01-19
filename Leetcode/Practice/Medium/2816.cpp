/*Double a Number Represented as a Linked List
You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.
Return the head of the linked list after doubling it.

Example 1:
Input: head = [1,8,9]
Output: [3,7,8]
Explanation: The figure above corresponds to the given linked list which represents the number 189. Hence, the returned linked list represents the number 189 * 2 = 378.

Example 2:
Input: head = [9,9,9]
Output: [1,9,9,8]
Explanation: The figure above corresponds to the given linked list which represents the number 999. Hence, the returned linked list reprersents the number 999 * 2 = 1998.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *doubleIt(ListNode *head)
    {
        ListNode *temp = head;
        while (temp)
        {
            if (temp == head)
            {
                if (temp->val >= 5)
                {
                    ListNode *newnode = new ListNode(1);
                    head = newnode;
                    head->next = temp;
                }
            }
            temp->val *= 2;
            if (temp->val / 2 >= 5)
                temp->val -= 10;
            if (temp->next)
            {
                if (temp->next->val >= 5)
                    temp->val += 1;
            }
            temp = temp->next;
        }
        return head;
    }
};
// TC - O(n)  SC - O(1)