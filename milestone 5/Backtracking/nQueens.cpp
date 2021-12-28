// n queens
#include<bits/stdc++.h>
using namespace std;

int board[11][11];

// your code
// isPossible function
bool isPossible(int n, int row,int col){

        // up
        for (int i = row-1; i >=0 ; i--)
        {
            if(board[i][col] == 1){
                return false;
            }
        }
        
        // left-up
        for (int i = row-1, j = col-1; i >=0 ,j>=0; i--,j--)
        {
            if(board[i][j] == 1){
                return false;
            }
        }
        // right-up
        for (int i = row-1, j = col+1; i >=0 ,j<n; i--,j++)
        {
            if(board[i][j] == 1){
                return false;
            }
        }
        return true;
    }


void nqueenhelper(int n,int row){
    // here basically we will print if reached row 5 (if considered 4*4 chess board)
    // print func
    if(row == n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j]<<" ";
        }
    }
    cout<<endl;
    return;
    }


    // if queen in that particular box is possible then place and set location to 1
    // since we are starting from 0,0 set it to 1
    // iterate over evry column in 1st row to place queen
    for (int j = 0; j < n; j++)
    {
        if(isPossible(n,row,j)){
            board[row][j] = 1;
            nqueenhelper(n,row+1);
            board[row][j] = 0;
        }
    }
    return;
}

void placeNQueens(int n){

    nqueenhelper(n, 0);
}


// main
int main(){
    int n;
    cin>>n;
    placeNQueens(n);
    return 0;
}