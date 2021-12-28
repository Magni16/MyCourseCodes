/*
2
    Time complexity: O(N * log(K))
3
    Space complexity: O(K)
4
​
5
    where N is the size of the input array
6
    and K is the number of smallest elements that are to be found
7
*/
#include <queue>
#include <vector>
vector<int> kSmallest(int arr[], int n, int k)
{

    priority_queue<int> maxHeap;
    for (int i = 0; i < k; i++)
    {
        maxHeap.push(arr[i]);
    }
    for (int i = k; i < n; i++)
    {
        if (arr[i] < maxHeap.top())
        {
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
    }
    vector<int> output;
    while (!maxHeap.empty())
    {

        output.push_back(maxHeap.top());

        maxHeap.pop();
    }
    return output;
}