#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

// dfs func to add vertices in array
void printDFS(int** graph ,int v,int s,bool* visited ,vector<int> &ans)
{ 
    
  	ans.push_back(s);
    visited[s]= true;
    
    for(int i =0 ;i< v ;i++)
    {
        if(!visited[i]&& graph[s][i]==1)
    	printDFS( graph ,v, i ,visited,ans);
    }
    
}

// dfs func to print 
void printDFS(int** graph ,int v,int s,bool* visited )
{
    vector<int >ans;
    printDFS( graph ,v, s,visited,ans);
    
    sort(ans.begin() , ans .end());
        
    for( auto i :ans )
        cout << i<<" ";    
    
}


// MAIN
int main()
{
    int n, e;
    cin >> n;
    cin >> e;

    // making edge array and initialising with 0
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    // connect edges
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    int s,end;
    
    cin>> s>>end;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] =false;
    }
    
    
    
	// call to check for disconnected components
    for(int i=0;i<n;i++)
       {
   	   if(!visited[i])
           { 
        	printDFS(edges ,n ,i ,visited);
          	cout<<endl; // to separately print
            }  
		}
    // delete
    delete []  visited;
    for(int i = 0 ;i <n ;i++)
        delete [] edges[i];

    delete[] edges;
    

    return 0;
}