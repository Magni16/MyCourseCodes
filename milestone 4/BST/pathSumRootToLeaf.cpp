/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/
#include<string>
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k,vector<int> v)
{
    // here v is the path vector
    if(root==NULL)
        return;
    
    v.push_back(root->data);
    k = k - root->data;
    
    // if node is leaf then we print contents
    if(!root->left && !root->right)
    {
        if(k==0)
        {
            for(int i : v)  // for loop to iterate over vector contents
            {
                cout<< i<<" ";
            }
            cout<<endl;
        }
        v.pop_back();
        return;
    }
    rootToLeafPathsSumToK(root->left,k,v);    
    rootToLeafPathsSumToK(root->right,k,v);
    
}
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    // Write your code here
    vector<int> v;
    rootToLeafPathsSumToK(root,k,v);
    return;
}