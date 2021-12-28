#include <iostream>
#include<cmath>
using namespace std;



int balancedBTs(int h) {
    // Write your code here
    // dp array
    int dp[h+1];
    // setting 1st 2 indexes of dp array as we did in fibonacci
    dp[0]=1;
    dp[1]=1;
    // mod to get answer in range
    int mod = (int) (pow(10,9)+ 7);
    // for loop to iterate over the array and insert our answers in array
    for(int i=2 ;i<=h; i++)
    {
        dp[i]=(int)( ( (long)(dp[i-1])*dp[i-1] )%mod + (2*(long)(dp[i-1])*dp[i-2])%mod  ) % mod;
        
    }
        
return dp[h];
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}
