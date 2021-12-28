#include <bits/stdc++.h>
using namespace std;


// int mincostpath(int **input , int m,int n,int row,int col){
    // base case
//     if(row == m-1 && col == n-1){
//         return input[row][col];
//     }
//     int x = INT_MAX;
//     int y = INT_MAX;
//     int z = INT_MAX;
    
//     if(row<m-1)
// 		x = mincostpath(input , m , n,row+1,col);
//     if(col<n-1)
//     	y = mincostpath(input , m ,n,row,col+1);
//     if(row<m-1 && col<n-1)
//     	z = mincostpath(input , m ,n,row+1,col+1);
    
//     int ans = min(x , min(y , z));
//     return ans+input[row][col];
// }

// memoization
// int minCostPath_Mem(int **input, int m, int n, int i, int j, int **output) {
//     if(i == m- 1 && j == n- 1) {
//         return input[i][j];
//     }
    
//     if(i >= m || j >= n) {
//         return INT_MAX;
//     }
    
//     // Check if ans already exists
//     if(output[i][j] != -1) {
//         return output[i][j];
//     }
    
//     // Recursive calls
//     int x = minCostPath_Mem(input, m, n, i, j+1, output);
//     int y = minCostPath_Mem(input, m, n, i+1, j+1, output);
//     int z = minCostPath_Mem(input, m, n, i+1, j, output);
    
//     // Small Calculation
//     int a = min(x, min(y, z)) + input[i][j];
    
//     // Save the answer for future use
//     output[i][j] = a;
    
//     return a;
// }


// dp
int minCOst_DP(int **input, int m, int n) {
	int **ans = new int*[m];
	for(int i = 0; i < m; i++) {
		ans[i] = new int[n];
	}

	ans[m-1][n-1] = input[m-1][n-1];

	// Last row
	for(int j = n - 2; j >= 0; j--) {
		ans[m-1][j] = input[m-1][j] + ans[m-1][j+1];
	}

	// Last col
	for(int i = m-2; i >= 0; i--) {
		ans[i][n-1] = input[i][n-1] + ans[i+1][n-1];
	}

	for(int i = m-2; i >= 0; i--) {
		for(int j = n-2; j >= 0; j--) {
			ans[i][j] = input[i][j] + min(ans[i][j+1], min(ans[i+1][j+1], ans[i+1][j]));
		}
	}
	return ans[0][0];
}





int minCostPath(int **input, int m, int n)
{
    return minCOst_DP(input,m,n);
    // return mincostpath(input,m,n,0,0);
}



// main
int main()
{
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << minCostPath(arr, n, m) << endl;
}
