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

// bool searchInBST(BinaryTreeNode<int> *root , int k) {
// 	// Write your code here
//     if(root == NULL){
//         return NULL;
//     }
    
//     if(root->data == k){
//         return 1;
//     }
//     else if(root->data >k ){
//         return searchInBST(root->right,k);
//     }
//     else if(root->data >k ){
//         return searchInBST(root->left,k);
//     }
//     return 0;
// }

bool searchInBST(BinaryTreeNode<int> *node , int _key) {
if (node)
    {
        if (node->data == _key)
        {
            return true;
        }
        else if(_key<node->data)
            return searchInBST(node->left, _key);
        else 
            return searchInBST(node->right, _key);
    }
    else return false;
}
