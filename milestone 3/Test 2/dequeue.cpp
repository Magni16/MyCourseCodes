/**********
 
 Following is the main function we are using internally.
 Refer this for completing the Dequeue class.
 
 
 int main()
 {
 Deque dq(10);
 int choice,input;
 while(true) {
 cin >> choice;
 switch (choice) {
 case 1:
 cin >> input;
 dq.insertfront(input);
 break;
 case 2:
 cin >> input;
 dq.insertrear(input);
 break;
 case 3:
 dq.deletefront();
 break;
 case 4:
 dq.deleterear();
 break;
 case 5:
 cout << dq.getFront() << "\n";
 break;
 case 6:
 cout << dq.getRear() << "\n";
 break;
 default:
 return 0;
 }
 }
 
 return 0;
 }
 
 ************/
#include<vector>
#include<stack>
#include<queue>

/*
	Time complexity: O(1) for all operations.
	Space Complexity: O(N)
	
	Where N is the size of the deque.
*/

class Deque
{
    vector<int> dq;
    int front, rear;
    int n;

public:
    // Initialize your data structure.
    Deque(int size)
    {
        n = size;
        dq = vector<int>(n);
        front =  -1;
        rear =-1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    void insertFront(int key)
    {
  if (isFull()) {

	cout<<-1<<endl;
    return ;
  }

  if (front == -1) {
    front = 0;
    rear = 0;
  }

  else if (front == 0)
    front = n - 1;

  else
    front = front - 1;

  dq[front] = key;
}

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    void insertRear(int key){
    
  if (isFull()) {
      cout<<-1<<endl;
    return;
  }

  if (front == -1) {
    front = 0;
    rear = 0;
  }

  else if (rear == n - 1)
    rear = 0;

  else
    rear = rear + 1;

  dq[rear] = key;
}

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    void deleteFront()
    {
        if (front == -1)
        {
            cout<<-1<<endl;
            return;
        }

        int item = dq[front];

        if (front == rear)
        {
            // Deque has only one element.
            front = rear = -1;
        }
        else
        {
            // Increment 'front' by 1.
            if (front == n - 1)
            {
                front = 0;
            }
            else
            {
                ++front;
            }
        }

//         return item;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    void deleteRear()
    {
        if (front == -1)
        {
            cout<< -1<<endl;
            return;
        }

        int item = dq[rear];

        if (front == rear)
        {
            // Deque has only one element.
            front = rear = -1;
        }
        else
        {
            // Decrement 'rear' by 1.
            if (rear == 0)
            {
                rear = n - 1;
            }
            else
            {
                --rear;
            }
        }

//         return item;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if (isEmpty() == true)
        {
            // Deque is empty.
            return -1;
        }

        return dq[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if (isEmpty() == true)
        {
            // Deque is empty.
            return -1;
        }

        return dq[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if ((front == 0 && rear == n - 1) || (front == rear + 1))
        {
            return true;
        }
        return false;
    }
};
