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

int getSum(BinaryTreeNode<int>* root) {
    // Write your code here
    if(root== NULL){
        return 0;
    }
    
    int sum = root->data;
    int lsum = getSum(root->left);
    int rsum = getSum(root->right);
    
    return rsum+lsum+sum;
}