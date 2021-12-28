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

BinaryTreeNode<int>* helper(int *postorder , int *inorder ,int in_start ,int in_end,int post_start,int post_end){
    
    if(in_start > in_end){
        return NULL;
    }

    
    int rootindex= -1;

    int rootData  = postorder[post_end]; 
    
    int leftin_start = in_start;
    
    for(int i=0; i<=in_end ; i++){
        if(inorder[i] == rootData){
            rootindex = i;
            break;
        }
    }
    
    int leftin_end =rootindex -1; // jaha par root agayi uske pehle vala index
	int leftpost_start = post_start;
    int leftpost_end = leftin_end - leftin_start + leftpost_start;//this line
    
    
    // for right subtree
    int rightin_start = rootindex+1;
    int rightin_end = in_end;
    int rightpost_start = leftpost_end +1;
    int rightpost_end=  post_end-1;
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    
    // calling on left and right subtrees
    root->left = helper(postorder , inorder , leftin_start , leftin_end, leftpost_start , leftpost_end);
    root->right = helper(postorder , inorder , rightin_start , rightin_end, rightpost_start , rightpost_end);
    
    return root;
}



BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    helper(postorder , inorder , 0, inLength -1,0 , postLength -1);
}