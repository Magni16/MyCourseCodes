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

int length(Node *head)
{
    int count = 1;
    Node *temp = head;
    if (temp == NULL){
        return 0;
    }
    while(temp->next != NULL){
        count +=1;
        temp = temp -> next;
        
    }
    return count;
    
}