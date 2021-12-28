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

Node *reverseLinkedListRec(Node *head)
{
	if(head == NULL){
        return NULL;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* next = head->next;

    while(curr != NULL){

        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        
    }

    return prev;
}
