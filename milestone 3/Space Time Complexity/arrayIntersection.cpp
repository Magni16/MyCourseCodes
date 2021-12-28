#include<climits>
#include <bits/stdc++.h>
using namespace std;

void intersection(int *arr1, int *arr2, int size1, int size2) 
{
    sort(arr1, arr1 + size1);
    sort(arr2, arr2 + size2);
	for(int i = 0;i<size1;i++){
        for (int j = 0;j<size2;j++){
            if (arr1[i] == arr2[j]){
                cout<<arr1[i]<<" ";
                arr2[j] = INT_MIN;
                break;
            }
        }
    }    
}