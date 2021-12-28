/************************************************************
 
    Following is the structure of the node class 
 
    class Node {
    	public :
    	int data;
    	Node *next;

    	Node(int data) {
        	this->data = data;
        	next = NULL;
    	}
	};

**************************************************************/


class Stack
{
    Node* head;
    int size;

public:
    Stack()
    {
        head = NULL;
        size = 0;
        
    }

    /*----------------- Public Functions of Stack -----------------*/
    void push(int element)
    {
        // Implement the push() function

            Node* newNode = new Node(element);
            newNode->next =head;
            head = newNode;
            size++;
    }
    

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function
        return size==0;
    }


    int pop()
    {
        // Implement the pop() function
        if (isEmpty())
        {
            return -1;
        }
        
        int ans = head->data;
        Node *temp = head;
        head=head->next;
        delete temp;
        size--;
        return ans;

    }

    int top()
    {
        if(isEmpty()){
            return -1;
        }
        return head->data;

    }
};