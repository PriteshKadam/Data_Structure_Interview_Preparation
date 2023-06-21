// https://leetcode.com/problems/binary-tree-preorder-traversal/

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
class Solution {
public:
    void RecursivePreorderTraversal(TreeNode* root, vector<int> &out)
    {
        if(!root)
        {
            return;
        }

        out.push_back(root->val);
        RecursivePreorderTraversal(root->left, out);
        RecursivePreorderTraversal(root->right, out);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> output;
        RecursivePreorderTraversal(root, output);
        return output;   
    }
};