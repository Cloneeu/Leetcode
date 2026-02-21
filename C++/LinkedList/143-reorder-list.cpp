/*
    You are given the head of a singly linked-list. The list can be represented as:
    L0 → L1 → ... → Ln - 1 → Ln

    Reorder the list to be on the following form:
    L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → ...

    You may not modify the values in the list's nodes. Only nodes themselves may be changed.

    Example 1:
    Input: head = [1,2,3,4]
    Output: [1,4,2,3]

    Example 2:
    Input: head = [1,2,3,4,5]
    Output: [1,5,2,4,3]

    Constraints:
    The number of nodes in the list is in the range [1, 5 * 104].
    1 <= Node.val <= 1000
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
    void reorderList(ListNode *head)
    {
        // Encontrar la mitad de la lista enlazada
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Invertir la segunda mitad de la lista enlazada
        ListNode *second = slow->next;
        slow->next = nullptr;
        ListNode *node = nullptr;
        while (second)
        {
            ListNode *aux = second->next;
            second->next = node;
            node = second;
            second = aux;
        }

        // Unir la primera mitad con la segunda mitad
        ListNode *first = head;
        second = node;
        while(second)
        {
            ListNode *aux1 = first->next;
            ListNode *aux2 = second->next;
            first->next = second;
            second->next = aux1;
            first = aux1;
            second = aux2;
        }
    }
};