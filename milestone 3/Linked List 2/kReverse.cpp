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
class Pair
{
public:
    Node *headx;
    Node *tailx;
};

Pair Reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.headx = head;
        ans.tailx = head;
        return ans;
    }
    Pair smallans = Reverse(head->next);
    smallans.tailx->next = head;
    head->next = NULL;
    Pair ans;
    ans.headx = smallans.headx;
    ans.tailx = head;

    return ans;
}


	Node* kReverse(Node *head, int k)
{
    int count = 1;
    Node *h1 = head;
    Node *t1 = head;
    Node *h2 = NULL;

    if(head == NULL){
        return NULL;
    }
    
    while (count < k && t1->next != NULL)
    {
        t1 = t1->next;
        count++;
        
    }
    h2 = t1->next;
    t1->next=NULL;
    Pair nex = Reverse(h1);
    // // Node* headmine = nex.headx;
    // return headmine;
    h1 = nex.headx;
    t1 = nex.tailx;
    Node* newhead = kReverse(h2,k);

    t1->next = newhead;
    return h1;

}
