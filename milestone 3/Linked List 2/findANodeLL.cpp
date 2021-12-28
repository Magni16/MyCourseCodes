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

int findNodeRec(Node *head, int element)

{
    int count = -1;
    Node *temp = head;
    if(head == NULL){
        return -1;
    }
    
    if (head->data == element)
    {
        return 0;
    }

    while (temp != NULL)
    {

        
        count++;
        if (temp->data == element)
        {
            return count;
        }
        temp = temp->next;

    }
    if (temp == NULL)
    {
        return -1;
    }
    return -1;

}