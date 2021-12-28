// rat in maze

#include<bits/stdc++.h>
using namespace std;

// my code

// printSolution function
    void printSolution(int ** solution ,int n){
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << solution[i][j]<<" ";
            }
        }
        cout<<endl;
    }


void mazehelper(int maze[][20] ,int n ,int **solution , int x ,int y){

    
    // constraints
    if (x>=n || y>=n || x<0 || y<0 || maze[x][y] ==0 || solution[x][y] ==1)
    {
        return;
    }


    // if reached end print solution
    if (x == n-1 && y == n-1)
    {
        solution[x][y] = 1;
        printSolution(solution,n);
        solution[x][y] = 0;
        return;
    }
    

    // backtracking cases..first we backtrack up,then down,then left,then right
    solution[x][y] = 1;
    mazehelper(maze,n,solution,x-1,y);
	mazehelper(maze,n,solution,x+1,y);
	mazehelper(maze,n,solution,x,y-1);
	mazehelper(maze,n,solution,x,y+1);
    solution[x][y] = 0;
}


void ratInAMaze(int maze[][20] , int n){

    // solution matrix where every entry will be zero initially
    int **solution = new int*[n];
    for (int i = 0; i < n; i++)
    {
        solution[i] = new int[n];
    }

    // now making helper function which takes rows...since we have to iterate over rows
    mazehelper(maze,n,solution,0,0);
    
}



int main() {
    int n;
	cin >> n;
    int maze[n][20];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maze[i][j];
        }
        cout<<endl;
    }
    ratInAMaze(maze,n);
	// Write your code here
	return 0;
}