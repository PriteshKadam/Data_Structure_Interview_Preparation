// Root to Node Path in Binary Tree https://www.codingninjas.com/studio/problems/path-in-a-tree_3843990?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
// 

#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/

void GetPath(TreeNode<int> *root, int x, bool &found, vector<int> &path)
{
	if(!root) return;

	path.push_back(root->data);

	if(root->data == x)
	{
		found = true;
		return;
	}

	GetPath(root->left, x, found, path);
	if(found) return;

	GetPath(root->right, x, found, path);
	if (!found) {
		path.pop_back();
	}

	return;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	bool found = false;
	vector<int> path;

	GetPath(root, x, found, path);

	return path;
}
