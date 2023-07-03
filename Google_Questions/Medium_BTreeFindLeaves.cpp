/*
// https://leetcode.com/problems/find-leaves-of-binary-tree/description/
366. Find Leaves of Binary Tree
Given the root of a binary tree, collect a tree's nodes as if you were doing this:

    Collect all the leaf nodes.
    Remove all the leaf nodes.
    Repeat until the tree is empty.

*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 /*
Maintain nodes height wise (1 to h where h is the height of the root node)
ht 1 -> {nodes} // leaf nodes
ht 2 -> {nodes}
and so on

ht h -> {root}
 */
class Solution {
public:
    int findLeaves(TreeNode* root, vector<vector<int>> &out)
    {
        if(!root) return 0;

        int left_height = findLeaves(root->left, out);
        int right_height = findLeaves(root->right, out);

        int current_height = 1 + max(left_height, right_height);

        if(out.size() < current_height) // first time visiting this height
        {
            out.push_back({});
        }

        out[current_height - 1].push_back(root->val);

        return current_height;
    }

    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> out;
        findLeaves(root, out);
        return out;
    }
};