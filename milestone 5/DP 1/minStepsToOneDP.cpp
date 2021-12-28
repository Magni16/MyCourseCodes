#include <bits/stdc++.h>
using namespace std;


int counthelper(int n,int *ans){
    
    // base case
    if(n<=1){
        return 0;
    }
    
    if(ans[n] != -1){
        return ans[n];
    }
    
        int x = counthelper(n-1,ans);
        int y = INT_MAX;
        int z = INT_MAX;
        if(n%2 == 0){
            y = counthelper(n/2 , ans);
        }
        if(n%3 == 0){
            z = counthelper(n/3 , ans);
        }
        int output = min(x,min(y,z))+1;
    	ans[n] = output;
        return output;
    
    
}

int countStepsToOne(int n)
{
	//Write your code here
    //  memoization
    // base case
    int *ans = new int[n+1];
    
    for(int i=0;i<=n;i++){
        ans[i]=-1;
    }
    return counthelper(n,ans);
}



int main()
{
	int n;
	cin >> n;
	cout << countStepsToOne(n);
}
