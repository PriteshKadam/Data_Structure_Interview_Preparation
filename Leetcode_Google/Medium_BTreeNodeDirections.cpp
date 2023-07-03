//https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/
/*You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.

Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:

    'L' means to go from a node to its left child node.
    'R' means to go from a node to its right child node.
    'U' means to go from a node to its parent node.

Return the step-by-step directions of the shortest path from node s to node t.You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.

Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:

    'L' means to go from a node to its left child node.
    'R' means to go from a node to its right child node.
    'U' means to go from a node to its parent node.

Return the step-by-step directions of the shortest path from node s to node t.
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
class Solution {
public:

    void getPath(TreeNode* root, int value , bool &bFound, string &path)
    {
        if(!root)
        {
            return;
        }

        if(value == root->val)
        {
           bFound = true;
           return; 
        }

        path.push_back('L');
        getPath(root->left, value , bFound, path);
        if(bFound) return;
        path.pop_back();

        path.push_back('R');
        getPath(root->right, value , bFound, path);
        if(bFound) return;      

        path.pop_back();

        return;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        string root_to_start, root_to_dest;
        bool bFound = false;
        string directions;

        // Get path from root -> startValue
        getPath(root, startValue , bFound, root_to_start);

        bFound = false;
        // Get path from root -> destValue
        getPath(root, destValue , bFound, root_to_dest);

        // Get least Common ancestor
        int index=0;
        for(index=0; index < root_to_start.length() && index < root_to_dest.length(); index++)
        {
            if(root_to_start[index] != root_to_dest[index])
            {
                break;
            }
        }
        //if(index != 0) index--;
        // For root-to-start path : replace Letters by U
        for(int i=index; i < root_to_start.length();i++)
        {
            directions.push_back('U');
        }
        
        // append root-to-start path to root-to-dest path
        for(int i=index; i < root_to_dest.length();i++)
        {
            directions.push_back(root_to_dest[i]);
        }

        return directions;
    }
};
