void heapSort(int pq[], int n) {
    // Write your code
    // creating heap
    for(int i=1; i<n ; i++){
        
        int childIndex = i;
        
        while(childIndex > 0){
            int parentIndex = (childIndex - 1)/2;
            if(pq[childIndex] < pq[parentIndex]){
                
                int temp  = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
                
            }
            else{
                break;
            }
            childIndex = parentIndex;

        }
    }
    
    // removing / sorting last element
    int size = n;
    
    while(size>1)
    {
    int temp = pq[0];
    pq[0] = pq[size-1];
    pq[size-1] = temp;
    
    size--;
    
    //down heapify
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

    while(leftChildIndex < size){

            

            int minIndex = parentIndex;
            if (pq[minIndex] > pq[leftChildIndex])
            {
                minIndex = leftChildIndex;
            }
            if (rightChildIndex < size && pq[minIndex] > pq[rightChildIndex])
            {
                minIndex = rightChildIndex;
            }

            if (minIndex == parentIndex)
            {
                break;
            }
            
            // swap minindex(minimum of leftchild or rightchild) and parentindex
            int temp2 = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp2;

            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
           
    }
}
}