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
#include<queue>
void printLevelWise(BinaryTreeNode<int> *root) {
	if (root == NULL)
    {
        return;
    }
    	
	queue<BinaryTreeNode<int> *> pendingNodes;

	pendingNodes.push(root);

	while (pendingNodes.size() != 0)
	{
		BinaryTreeNode<int> *front = pendingNodes.front();
        cout<< front->data<<":";
        
        if(front->left !=NULL){
            cout<<"L:"<<front->left->data<<",";
        }
        else{
            cout<<"L:"<<-1<<",";
        }
        if(front->right !=NULL){
            cout<<"R:"<<front->right->data;
        }
        else{
            cout<<"R:"<<-1;
        }
        
		pendingNodes.pop();
        if(front->left != NULL){
            pendingNodes.push(front->left);
            
        }
        if(front->right != NULL){
            pendingNodes.push(front->right);
            
        }

		
		cout<<endl;
	}
    
	return;
}