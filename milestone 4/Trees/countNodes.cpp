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

int getLargeNodeCount(TreeNode<int>* root, int x) {
	// set conditions for root
	int myans = 0;	
	if (root->data > x)
		{
			myans = 1;
		}
	// call on  children
	for (int i = 0; i < root->children.size(); i++)
	{
		myans += getLargeNodeCount(root->children[i] , x);
	}
	return myans;
}