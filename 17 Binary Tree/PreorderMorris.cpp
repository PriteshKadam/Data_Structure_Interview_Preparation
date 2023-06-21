// https://leetcode.com/problems/binary-tree-preorder-traversal

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
    vector<int> MorrisPreOrderTraversal(TreeNode *root)
    {
        // Write your code here.
        vector<int> output;

        while(root)
        {
            if(root->left)
            {
                TreeNode* rightMost = root->left;
                while(rightMost->right != NULL && rightMost->right != root)
                {
                    rightMost = rightMost->right;
                }

                if( rightMost->right == root)
                {
                    root = root->right;
                    rightMost->right = NULL;
                }
                else
                {
                    rightMost->right = root;
                    output.push_back(root->val); 
                    root = root->left;
                }
            }else
            {
            output.push_back(root->val); 
            root = root->right; 
            }
        }
        return output;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        return MorrisPreOrderTraversal(root); 
    }
};