/*
    You are given an array of k linked-lists lists, each
    linked-list is sorted in ascending order.

    Merge all the linked-lists into one sorted linked-list
    and return it.

    Example 1:
    Input: lists = [[1,4,5],[1,3,4],[2,6]]
    Output: [1,1,2,3,4,4,5,6]
    Explanation: The linked-lists are:
    [
        1->4->5,
        1->3->4,
        2->6
    ]
    merging them into one sorted linked list:
    1->1->2->3->4->4->5->6

    Example 2:
    Input: lists = []
    Output: []

    Example 3:
    Input: lists = [[]]
    Output: []

    Constraints:
    * k == lists.length
    * 0 <= k <= 104
    * 0 <= lists[i].length <= 500
    * -104 <= lists[i][j] <= 104
    * lists[i] is sorted in ascending order.
    * The sum of lists[i].length will not exceed 104.
*/

#include <bits/stdc++.h>

using namespace std;

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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
        {
            return nullptr;
        }

        while (lists.size() > 1)
        {
            vector<ListNode *> mergedLists;

            for (int i = 0; i < lists.size(); i += 2)
            {
                ListNode *l1 = lists[i];
                ListNode *l2 = (i + 1) < lists.size() ? lists[i + 1] : nullptr;
                mergedLists.push_back(mergeList(l1, l2));
            }
            lists = mergedLists;
        }
        return lists[0];
    }

private:
    // Es lo mismo que el de juntar 2 listas :)
    ListNode *mergeList(ListNode *list1, ListNode *list2)
    {
        ListNode dummy;
        ListNode *ans = &dummy;

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                ans->next = list1;
                list1 = list1->next;
            }
            else
            {
                ans->next = list2;
                list2 = list2->next;
            }
            ans = ans->next;
        }

        if (list1)
        {
            ans->next = list1;
        }
        else 
        {
            ans->next = list2;
        }

        return dummy.next;
    }
};