// Following is the Binary Tree node structure
/**************
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
***************/
// this function will return true if they have same parent
bool isSibling(BinaryTreeNode<int> *root, int data_one, 
                             int data_two) 
{ 
    if (!root) 
        return false; 
  
    // Compare the two given nodes with 
    // the childrens of current node 
    if (root->left && root->right) { 
        int left = root->left->data; 
        int right = root->right->data; 
  
        if (left == data_one && right == data_two) 
            return true; 
        else if (left == data_two && right == data_one) 
            return true; 
    } 
  
    // Check for left subtree 
    if (root->left) 
        isSibling(root->left, data_one, 
                                data_two); 
  
    // Check for right subtree 
    if (root->right) 
        isSibling(root->right, data_one, 
                                data_two); 
} 
  
// Recursive function to find level of Node in a binary tree 
int level(BinaryTreeNode<int> *root, int node, int lev) 
{ 
    // base cases 
    if (root == NULL){
        return 0;
    }
    if (root->data == node){
        return lev;
    }
  
    // Return level if Node is present in left subtree 
    int left = level(root->left, node, lev+1); 
    if (left != 0){
        return left; 
    }
    // Else search in right subtree 
    int right =  level(root->right, node, lev+1);
	if (right != 0){
        return right; 
    }
} 
  
  
bool isCousin(BinaryTreeNode<int> *root, int a,int b) 
{ 
    if ((level(root,a,1) == level(root,b,1)) && !(isSibling(root,a,b))) 
        return true; 
    else return false; 
}  
