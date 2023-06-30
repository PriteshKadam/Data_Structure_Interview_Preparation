// Left View Of a Binary Tree
// https://www.codingninjas.com/studio/problems/920519?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    queue<TreeNode<int> *> levelOrderQ;
    vector<int> leftView;
    levelOrderQ.push(root);

    while(!levelOrderQ.empty())
    {
        leftView.push_back(levelOrderQ.front()->data);
        int currentNodeCnt = levelOrderQ.size();

        while(currentNodeCnt > 0)
        {
            TreeNode<int> *currentNode = levelOrderQ.front();
            levelOrderQ.pop();
            currentNodeCnt--;
            
            if(currentNode->left) {
                levelOrderQ.push(currentNode->left);
            }

            if(currentNode->right) {
                levelOrderQ.push(currentNode->right);
            }
        }

    }
    return leftView;
}