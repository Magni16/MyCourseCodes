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

Node *deleteNode(Node *head, int pos)
{
    Node* temp = head;
    int counter =0;
    Node *temp1 = head;
    if (temp == NULL){
        return 0;
    }
    while(temp1->next != NULL){
        counter +=1;
        temp1 = temp1 -> next;
        
    }
    if(pos>counter ){
        return head;
    }
    
    if(pos == 0){
        head=head->next;
        return head;
    }
    
    int count = 1;
    while(count<pos){
        temp=temp->next;
        count++;
    }
    temp->next = temp->next->next;
    return head;
}

