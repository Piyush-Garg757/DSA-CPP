/*Partition List
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.

Example 1:
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]

Example 2:
Input: head = [2,1], x = 2
Output: [1,2]*/

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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode dummy1(-1), dummy2(-1);
        ListNode *l1 = &dummy1;
        ListNode *l2 = &dummy2;
        while (head)
        {
            if (head->val < x)
            {
                l1->next = head;
                l1 = head;
            }
            else
            {
                l2->next = head;
                l2 = head;
            }
            head = head->next;
        }
        l2->next = nullptr;
        l1->next = dummy2.next;
        return dummy1.next;
    }
};
// TC - O(n)  SC - O(1)

// Koi nayi list nahi ban rahi hai purani ke hi nodes ka use kar rahe hain