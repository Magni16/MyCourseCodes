/************************************************************

    Following is the Binary Tree node structure

    template <typename T>
    class BinaryTreeNode
    {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/


void insertDuplicateNode(BinaryTreeNode<int> *root) {
    
   if(root == NULL){
        return;
    }
    
    if(root){
        BinaryTreeNode<int> *newnode = new BinaryTreeNode<int>(root->data);
        newnode->left = root->left;
        root->left = newnode;
        
        insertDuplicateNode(newnode->left);
        insertDuplicateNode(root->right);
	}
}