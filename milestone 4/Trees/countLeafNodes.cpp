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
int getLeafNodeCount(TreeNode<int>* root) {
    int count = 0;
    if (root->children.size() == 0){
        count=1;
        return count;

    }

    int arr[root->children.size()];
    for (int i = 0; i<root->children.size() ; i++){
        arr[i] = getLeafNodeCount(root->children[i]);
    }
    // print array
    // for (int i =0 ; i<root->children.size() ; i++ ){
    //     cout<<arr[i]<<" ";
    // }
    int sum = 0;
    for (int i =0 ; i<root->children.size() ; i++ ){
        sum+= arr[i];
    }
    return sum;
}