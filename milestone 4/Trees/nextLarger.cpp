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

TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    // Write your code here
    
    if(root == NULL){
        return NULL;
    }
    
    TreeNode<int>* max = NULL;
    if(root->data > x){
        max = root;
    }
    for(int  i =0; i<root->children.size() ; i++){
        TreeNode<int>* child = getNextLargerElement(root->children[i],x);
        
        if(child==NULL)
        {continue;}
        else{
            if(max == NULL){
                max = child;
            }
            
            
        else if(max->data > child->data && child->data>x ){
            max = child;
        } 
            

        }
     }
	return max;
    
    
    
}