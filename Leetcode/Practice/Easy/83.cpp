/*Remove Duplicates from Sorted List
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

Example 1:
Input: head = [1,1,2]
Output: [1,2]

Example 2:
Input: head = [1,1,2,3,3]
Output: [1,2,3]*/

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *temp = head;
        ListNode *prev = head;
        if (temp->next)
            temp = temp->next;
        while (temp)
        {
            if (temp->val == prev->val)
            {
                prev->next = temp->next;
                temp = temp->next;
            }
            else
            {
                prev = prev->next;
                temp = temp->next;
            }
        }
        return head;
    }
};
// TC - O(n)  SC - O(1)