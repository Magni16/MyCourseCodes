int HelperbinarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        if (arr[mid] == x)
            return mid;
 
        if (arr[mid] > x)
            return HelperbinarySearch(arr, l, mid - 1, x);
 
        return HelperbinarySearch(arr, mid + 1, r, x);
    }

    return -1;
}


int binarySearch(int input[], int size, int element) {
    // Write your code here
    int n = size;
    return HelperbinarySearch( input ,0, n-1,element);
    

}
