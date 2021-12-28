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
#include <cmath>


Node *midPoint(Node *head)
{
    int count=1;
    Node * temp =head;
    while(temp)
    {
        count++;
        temp=temp->next;
    }
    
    int x=ceil(count/2);
    for(int i=1;i<x;i++)
    {
        head=head->next;
    }
  
    return head;
}

// Node *midPoint(Node *head) {
//     int l=0;
//     Node *p = head;
//     while (p != NULL) {
//         p = p->next;
//         l = l + 1;
//     }
//     p = head;
//     int c = 0;
//     while (c < l/2) {
//         p = p->next;
//         c = c + 1;
//     }
//     return p;
// }