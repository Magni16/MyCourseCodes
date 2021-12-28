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

Node* insertNode(Node *head, int i, int data) {
	
    Node *newNode = new Node(data);

    Node *temp = head;
    int counter = 1;
    Node *temp1 = head;
    if (temp == NULL){
        return 0;
    }
    while(temp1->next != NULL){
        counter +=1;
        temp1 = temp1 -> next;
        
    }
    if(i>counter ){
        return head;
    }
    if (temp != NULL)
    {
        
        
        // edge case 
        if (i == 0)
        {
            newNode->next = head;
            head = newNode;
            return head;
        }
        // loop to traverse to our position i
        int count = 0;
        while (count < i - 1)
        {
            temp = temp->next;
            count++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    return head;

}