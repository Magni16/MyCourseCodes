
/*********************************************************
 
    // Following is the node structure

    class Node {
    public:
        int data;
        Node * next;
        Node(int data){
            this -> data = data;
            this -> next = NULL;
        }
    
        ~Node() {
            if(next) {
                delete next;
            }
        }
    };

*********************************************************/

void deleteAlternateNodes(Node *head) {
   Node *current = head;
   Node *temp;
   int count;

   while (current != NULL) {
      // skip M nodes
      for (count = 1; count < 1 && current!= NULL; count++) {
         current = current->next;
      }
      // end of the linked list
      if (current == NULL) {
         return;
      }
      // deleting N nodes after M nodes
      temp = current->next;
      for (count = 1; count <= 1 && temp != NULL; count++) {
        //  Node *deletingNode = temp;
         temp = temp->next;
        //  free(deletingNode);
      }
      current->next = temp;
      current = temp;
   }

}