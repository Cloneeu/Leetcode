/*
    Given the head of a singly linked list, reverse the list,
    and return the reversed list.
*/

#include <bits/stdc++.h>

// Definition for singly-linked list

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
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
            return nullptr;
        ListNode *prev = nullptr;
        ListNode *curr = head;

        while (curr)
        {
            ListNode *aux = curr->next;
            curr->next = prev;
            prev = curr;
            curr = aux;
        }

        return prev;
    }
};
    
int main()
{
    // build test list: 1->2->3->4->5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;

    // print original
    std::cout << "original: ";
    for (ListNode *p = head; p; p = p->next)
        std::cout << p->val << (p->next ? "->" : "\n");

    // reverse and print result
    ListNode *rev = sol.reverseList(head);

    std::cout << "reversed: ";
    for (ListNode *p = rev; p; p = p->next)
        std::cout << p->val << (p->next ? "->" : "\n");

    return 0;
}