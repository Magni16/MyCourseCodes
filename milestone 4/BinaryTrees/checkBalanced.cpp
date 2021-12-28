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
#include <cstdlib>


int heighthelper(BinaryTreeNode<int> *root){
    if(root == NULL){
        return 0;
    }
    
    return 1+max(heighthelper(root->left),heighthelper(root->right));
}


bool isBalanced(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root == NULL){
        return 1;
    }
    int hleft = heighthelper(root->left);
    int hright= heighthelper(root->right);
    if ( ( abs(hleft- hright) ==0 || abs(hleft-hright) == 1 ) && isBalanced(root->left) && isBalanced(root->right))
        return 1;

   return 0;
}