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

#include <bits/stdc++.h> 

int getHeight(TreeNode<int>* root) {
   
    int h =1;
    
    if(root->children.size()==0)
        return h;	
    
    int arr[root->children.size()];
    for(int i=0;i<root->children.size();i++)
    {
        arr[i]=getHeight(root->children[i]);
        
    }
    sort(arr,arr+root->children.size());
	h+=arr[root->children.size()-1];
    
    return h;
}