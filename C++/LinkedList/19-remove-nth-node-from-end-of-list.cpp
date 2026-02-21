/*
    Given the head of a linked list, remove the nth node from
    the end of the list and return its head.

    Example 1:
    Input: head = [1,2,3,4,5], n = 2
    Output: [1,2,3,5]

    Example 2:
    Input: head = [1], n = 1
    Output: []

    Example 3:
    Input: head = [1,2], n = 1
    Output: [1]

    Constraints:
    The number of nodes in the list is sz.
    1 <= sz <= 30
    0 <= Node.val <= 100
    1 <= n <= sz
*/

#include <bits/stdc++.h>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode dummy;
        dummy.next = head;
        
        // Dos punteros
        ListNode *left = &dummy;
        ListNode *right = head;
        
        // Offset de N para right
        for (int i = 0; i < n; i++)
        {
            right = right->next;
        }

        // Al final right va a llegar al final y left va a quedar un nodo atras del que se debe quitar
        while (right)
        {
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next;

        return dummy.next;
    }
};