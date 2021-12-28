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
Node *midPoint(Node *head)
{
    Node *slow=head;
    Node *fast=head;
    if(head==NULL||head->next==NULL)
    {
      return head;
    }
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
      slow=slow->next;
      fast=fast->next->next;
    }
    return slow;
}

Node* sortedMerge(Node *a,Node *b)
{
  Node *result=NULL;
  if(a==NULL)
  {
    return b;
  }else if(b==NULL)
  {
    return a;
  }
  if(a->data <= b->data)
  {
    result=a;
    result->next=sortedMerge(a->next,b);
  }else
  {
    result=b;
    result->next=sortedMerge(a,b->next);
  }
  return result;
}


Node* mergeSort(Node *head)
{
  if(head==NULL||head->next==NULL)
  {
    return head;
  }
  Node *mid=midPoint(head);
  Node *firstHalfTail=mid;
  Node *secondHalfHead=mid->next;
  firstHalfTail->next=NULL;
  Node *head1=mergeSort(head);
  Node *head2=mergeSort(secondHalfHead);
  Node *mergedListHead=sortedMerge(head1,head2);
  return mergedListHead;
}