/***********************************************************
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

int height(BinaryTreeNode<int>* root) {
    // Write our code here
    if (root == NULL)
        return 0;
    
    int x = 1;
    int y = 1;
    x += height(root->left);
    y += height(root->right);
    int ans =max(x,y);
    return ans;
}