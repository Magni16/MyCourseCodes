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

Node *skipMdeleteN(Node *head, int M, int N)
{
   Node *current = head;
   Node *temp;
   int count;
    
    if(M == 0){
        return NULL;
    }

   while (current != NULL) {
      // skip M nodes
      for (count = 1; count < M && current!= NULL; count++) {
         current = current->next;
      }
      // end of the linked list
      if (current == NULL) {
         return head;
      }
      // deleting N nodes after M nodes
      temp = current->next;
      for (count = 1; count <= N && temp != NULL; count++) {
        //  Node *deletingNode = temp;
         temp = temp->next;
        //  free(deletingNode);
      }
      current->next = temp;
      current = temp;
   }
    return head;
}

