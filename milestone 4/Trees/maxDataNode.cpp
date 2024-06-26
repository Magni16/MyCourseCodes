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

TreeNode<int>* maxDataNode(TreeNode<int>* root) {

	TreeNode<int> *max=new TreeNode<int>(root->data);
    
    for(int i=0;i<root->children.size();i++)
    {
        TreeNode<int> *child=maxDataNode(root->children[i]);
        if(child->data > max->data)
              max=child;
    }
    
    return max;
}