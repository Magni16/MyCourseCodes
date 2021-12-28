/************************************************************
 
    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;
    
        TreeNode(T data) {
            this->data = data;
        }
    
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/

bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    // Write your code here
    
    int newvar = true;
    if(root1->data != root2->data){
        newvar = false;
        return false;
    }
    
    if(root1->children.size() != root2->children.size()){
        newvar = false;
        return false;
    }
	
	for (int i = 0; i < root1->children.size(); i++)
	{
		newvar &= areIdentical(root1->children[i], root2->children[i]);
	}
	return newvar;    
}