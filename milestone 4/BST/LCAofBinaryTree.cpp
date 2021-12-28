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

int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    // Write your code here
    if(root ==NULL){
        return -1;
    }
    
    // first check (if one is parent of another)
    if(a == root->data || b ==root->data){
        return root->data;
    }
    
    int x = getLCA(root->left ,a, b);
    int y = getLCA(root->right ,a, b);
    
    // if x and y both null ans is null
    if(x == -1 && y== -1){
        return -1;
    }
    
    // if one of x and y is not null...return the one which is not null
    else if(x==-1 && y != -1)
    {
        return y;
    }
    else if( x !=-1 && y == -1)
    {
        return x;
    }
    // otherwise last possibility is that both arent null...then our LCA will be root itself
    else{
        return root->data;
    }
}