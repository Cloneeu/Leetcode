/*
    Given the root of a binary tree, invert the tree, and return its root.

    Example 1:
    Input: root = [4,2,7,1,3,6,9]
    Output: [4,7,2,9,6,3,1]

    Example 2:
    Input: root = [2,1,3]
    Output: [2,3,1]

    Example 3:
    Input: root = []
    Output: []

    Constraints:
    The number of nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100
*/

#include <bits/stdc++.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    // Hacer un DFS
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return nullptr;
        
        // Invertir el nodo de la izquierda con el de la derecha y viceversa
        TreeNode *aux = root->left;
        root->left = root->right;
        root->right = aux;
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};