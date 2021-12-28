#include<queue>
#include<iostream>
using namespace std;

void findMedian(int *arr, int n)
{
    // Write your code here
    
    // making a max priority queue and a min priority queue first
    priority_queue <int> max;
    priority_queue <int , vector<int>, greater<int>> min;
    
    
	// adding elements from arr to these queues 
	
    for(int i = 0; i<n;i++){
        
        // first element will be added to max queue
        if(i==0){
            max.push(arr[i]);
        }
        else{
            if(max.top()>arr[i]){
                max.push(arr[i]);
            }
            else{
                min.push(arr[i]);
            }
        }    
    
    
        // BALANCING queues so that their size remains >= abs(1)

        if(int(min.size() - max.size()) >1){
            int top_ele = min.top();
            min.pop();
            max.push(top_ele);
        }
        else if(int(max.size() - min.size())>1){
            int top_ele = max.top();
            max.pop();
            min.push(top_ele);
        }

        // finding the median 
        int count = min.size()+max.size();  // total size of both queues 
        // even number of elements then average of top elements of both queues
        if(count%2 == 0){
            cout<<(max.top() + min.top())/2<<" ";
        }
        else{
            // if count is odd...answer will be top element of queue having greater size
            if(max.size()>min.size()){
                cout<<max.top()<<" ";
            }
            else{
                cout<<min.top()<<" ";
            }
        }
    }
}