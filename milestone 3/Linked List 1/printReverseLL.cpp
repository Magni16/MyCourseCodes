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

void printReverse(Node *head)
{
    int count = 0;
    Node *temp = head;
    Node *newtemp = head;


    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    while (count > 0) //count is length of list
    {
        // cout<<" count is "<<count<<endl;
        newtemp = head;
        for (int i = 1; i < count; i++)
        {
            // cout<<newtemp->data<<" ";
            newtemp = newtemp->next;
        }
        cout<< newtemp->data << " ";
        count--;
    }
}