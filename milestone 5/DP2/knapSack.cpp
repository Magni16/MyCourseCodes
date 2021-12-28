#include <iostream>
using namespace std;

// brute
int knapsack(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
    // base
    if(n==0 || maxWeight == 0){
        return 0;
    }
    
    
    if(weights[0] > maxWeight){
        return knapsack(weights+1,values+1,n-1,maxWeight);
    }
    
    
    int x = knapsack(weights+1,values+1,n-1,maxWeight - weights[0]) + values[0];
    int y = knapsack(weights+1,values+1,n-1,maxWeight);
    
    return max(x,y);
}

// dp solution
// int knapsack(int* weights, int* values, int n, int maxW)
// {   int dp[n+1][maxW+1];
// 	 for(int i =0 ; i<=n ;i++)
// 		 { for(int j=0 ;j<=maxW ;j++)
// 			 {
//  			    if( i==0 || j== 0)
//  			        dp[i][j]=0;
//  			    else
//  			    {  if(weights[i-1]>j)
//  		  	         dp[i][j]  = dp[i-1][j];
//  			        else
//  			         dp[i][j]= max( values[i-1] + dp[i-1][j-weights[i-1]], dp[i-1][j]) ; 
//  			    }
// 			 }
// 		 }
//  return dp[n][maxW];
// }





// main
int main()
{
	int n;
	cin >> n;

	int *weights = new int[n];
	int *values = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> weights[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> values[i];
	}

	int maxWeight;
	cin >> maxWeight;

	cout << knapsack(weights, values, n, maxWeight) << endl;

	delete[] weights;
	delete[] values;
}