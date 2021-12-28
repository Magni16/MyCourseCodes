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

Node *appendLastNToFirst(Node *head, int n)
{
    Node *temp = head;
    Node *extratemp = head;
    Node *temp2 =head;
    Node *prev =NULL;

    int count = 0;
    if(head == NULL){
        return NULL;
    }
// checking number of elements in list using count
    while (temp2 != NULL)
    {
        temp2=temp2->next;
        count++;
    }
    int temp_index_from_start = count - n;


    while(temp->next != NULL){
        temp=temp->next;                                  // 1ST MAIN THING (APPEND LAST NODE TO HEAD)
    }
    temp->next = head;

    while (temp_index_from_start>0)
    {   prev =extratemp;
        
        extratemp = extratemp->next;

        temp_index_from_start--;                           // 2ND MAIN THING (SET HEAD TO DESIRED NODE AND SET PREV NODE TO NULL TO AVOID INFINTE LOOP)
    }
    prev->next =NULL;
    head = extratemp;
    

    
return head;

}