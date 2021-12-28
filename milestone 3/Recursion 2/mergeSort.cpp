void merge(int arr1[], int m,int arr2[], int n, int output[]){
    int i = 0;
    int j=0;
    int k=0;
    while(i<m && j<n){
        if(arr1[i] <arr2[j]){
            output[k] = arr1[i];
            k++;
            i++;
        }
        else{
            output[k] = arr2[j];
            j++;
            k++;
        }
    }
    while(i<m){
        output[k] = arr1[i];
        k++;
        i++;
    }
    while(j<n){
        output[k] = arr2[j];
        j++;
        k++;
    }
}



void mergeSort(int input[], int size){
	// Write your code here
    if(size<=1){
        return;
    }
    int mid = size/2;
    int subarr1[500],subarr2[500];
    int m = mid ,n = size - mid;
    for(int i =0 ;i <mid;i++){
        subarr1[i] = input[i];
    }
    int k=0;
    for(int i =mid;i<size;i++){
        subarr2[k] = input[i];
        k++;
    }
    mergeSort(subarr1,m);
    mergeSort(subarr2,n);
    merge(subarr1,m,subarr2,n,input);
}
