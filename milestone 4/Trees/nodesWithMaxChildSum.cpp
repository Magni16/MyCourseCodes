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

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    
    TreeNode<int>* ans =root;
    int sum = root->data;
    for(int i=0; i<root->children.size();i++){
     sum+=root->children[i]->data;   
    }
    
    for(int i =0;i<root->children.size();i++){
        TreeNode<int>* child = maxSumNode(root->children[i]);
        
        int smallSum = child->data;
        for(int i=0; i<child->children.size();i++){
     smallSum+=child->children[i]->data;   
    }
        
        if (smallSum > sum){
            ans =child;
            sum  = smallSum;
        }
    }
    return ans;
}