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

Node *evenAfterOdd(Node *head)
{
    
    

    Node* todd = NULL;
    Node* teven=NULL;
    Node* hodd = NULL;
    Node* heven = NULL;
  
 
// code from line 32 to 55 is for cases when list is composed of either only even or only odd numbers
    
    Node* best = head;
    int flag = 0;
    while(best != NULL){
        if((best->data)%2 == 0){
            flag = 1;
        }
        best = best->next;
        
    }
    if(flag == 0){
        return head;
    }
    
    Node* secondbest = head;
    int secondflag = 0;
    while(secondbest != NULL){
        if((secondbest->data)%2 != 0){
            secondflag =1;
        }
        secondbest = secondbest->next;
    }
    if(secondflag==0){
        return head;
    }
    
    
    if(head == NULL){
        return NULL;
    }

    while (head != NULL)
    {
        if(head->data % 2 ==0){
            if(heven == NULL){
                heven = head;
                teven = head;
                head = head->next;
            }
            else{
                teven -> next = head;
                teven = teven->next;
                head = head->next;
            }
        }

        else{
            if(hodd == NULL){
                hodd = head;
                todd = head;
                head = head->next;
            }
            else{
                todd->next = head;
                todd =todd->next;
                head = head->next;
            }
        }
    }
    todd->next = NULL;
    teven->next = NULL;
    todd->next = heven;

if(hodd == NULL){
    return heven;
}

    
if(heven == NULL){
    return hodd;
}

return hodd;
}
