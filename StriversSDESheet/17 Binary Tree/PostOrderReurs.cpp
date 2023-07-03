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

    void RecursivePostorderTraversal(TreeNode* root, vector<int> &out)
    {
        if(!root)
        {
            return;
        }

        RecursivePostorderTraversal(root->left, out);
        RecursivePostorderTraversal(root->right, out);
        out.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> output;
        RecursivePostorderTraversal(root, output);
        return output;       
    }
};