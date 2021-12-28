BinaryTreeNode<int>* helper(int * inorder, int *preorder , int in_start,int in_end,int pre_start,int pre_end){
	
    if(in_start>in_end)
    {
        return NULL;
    }
    int rootData = preorder[pre_start];
    
    
    int leftpre_start = pre_start+1; // leftpre_s
    int leftin_start = in_start;  // left_instart
    
    int root_index = -1;    
    for(int i=in_start ; i<=in_end ; i++){
        if(inorder[i] == rootData){
            root_index = i;
            break;
        }
    }
    
    int leftin_end = root_index -1;  //leftin_end
    
    int leftpre_end = leftin_end-leftin_start+leftpre_start; //leftpre_end
    
    // for right
    
    int rightpre_start= leftpre_end+1;
	int rightin_start= root_index+1;
    int rightin_end= in_end;
    int rightpre_end= pre_end;

    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    root->left = helper(inorder, preorder, leftin_start, leftin_end, leftpre_start, leftpre_end);
	root->right = helper(inorder, preorder, rightin_start, rightin_end, rightpre_start, rightpre_end);

    return root;
}
	

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here

    return helper(inorder, preorder , 0,  inLength-1 , 0 ,preLength -1 );
	
    
}