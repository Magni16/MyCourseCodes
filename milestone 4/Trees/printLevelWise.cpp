#include <queue>

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



void printLevelWise(TreeNode<int>* root) {
    
    if(root->data==NULL)
      return;
    
   
    queue<TreeNode<int>*> pendingnodes;
    pendingnodes.push(root);
   
   while(pendingnodes.size()!=0)
   {  
       TreeNode<int>*front=pendingnodes.front();
        pendingnodes.pop();
       cout<<front->data<<":";
  	 for(int i=0;i<front->children.siz e();i++)
  	 {  
  	     pendingnodes.push(front->children[i]);
         if(i==front->children.size()-1)
              cout<<front->children[i]->data;
         
         else
  	         cout<<front->children[i]->data<<",";
 	  }
 	  
        cout<<endl; 
   } 
}