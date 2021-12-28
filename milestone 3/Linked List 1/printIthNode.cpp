/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

void printIthNode(Node *head, int i)
{
    int count = 1;
    Node *temp = head;
    if (temp == NULL){
        return ;
    }
    int k = 0;
    while(temp and k<=i){
        if(k == i ){
            cout<< temp->data;
        }
        temp = temp -> next;
        k++;
    }
}