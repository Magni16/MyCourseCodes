#include <bits/stdc++.h>
using namespace std;



// int minCount(int n)
// {
// 	// if number is complete square
//     if(sqrt (n) - floor(sqrt(n))==0)
//        return 1;
    
//     // if number is less than 3 then we will get same count
//     if(n <=3)
//         return n;
    
//    int ans= n;
//     for(int i=1 ; i*i<=n ; i++)
//     {
//       ans = min(ans , 1 + minCount(n-i*i));
//     }


//    return ans;
// }


// memoization
int mincount ( int n , int *arr)
{

    if( sqrt (n) -floor(sqrt(n))==0)
    {   arr[n]=1;
        return arr[n];
    }
    if(n <=3)
    {  arr[n]=n;
        return n;
    }
    int ans= n;
    if(arr[n] != 0) return arr[n];
    for(int i=1 ; i*i<=n ; i++)
    {   
       
       arr[n] =ans= min(ans , 1 + mincount(n-i*i,arr));
    }
    
    return arr[n];
}

int minCount(int n){
    int arr [n+1];
    for(int i=0 ;i<=n ;i++)
        arr[i]=0;
    return mincount(n , arr); 

}

// main
int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}