#include <vector>
#include <iostream>
using namespace std;
class PriorityQueue
{

    vector<int> pq;

public:
    PriorityQueue()
    {
    }

    void insert(int element)
    {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] > pq[parentIndex])
            {
                // swapping
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int getMax()
    {
        if (isEmpty())
        {
            return 0;
        }
        return pq[0];
    }

    int removeMax()
    {
        if (isEmpty())
        {
            return 0;
        }

        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        // swapping code to maintain heap order
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        
        // down -heapify
        while (leftChildIndex < pq.size())
        {
            int maxIndex = parentIndex;
            if (pq[maxIndex] < pq[leftChildIndex])
            {
                maxIndex = leftChildIndex;
            }
            if (rightChildIndex < pq.size() && pq[maxIndex] < pq[rightChildIndex])
            {
                maxIndex = rightChildIndex;
            }
            // we dont need to swap if maxIndex is our parent Index
            if (maxIndex == parentIndex)
            {
                break;
            }

            // swap maxIndex with parentIndex
            int temp = pq[maxIndex];
            pq[maxIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = maxIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }

        return ans;
    }

    int getSize()
    {
        return pq.size();
    }

    bool isEmpty()
    {
        return pq.size() == 0;
    }
};