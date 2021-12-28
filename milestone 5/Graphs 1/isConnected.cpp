#include <iostream>
#include<queue>
using namespace std;

void BFS(int**graph ,int v , int sv,bool* visited)
{
  
    queue<int> pn;
    pn.push(sv);
    visited[sv]=true;

    while(!pn.empty())
    {
        int t= pn.front();
        pn.pop();
     
        for(int i=0 ; i<v ;i++)
        {
            if(graph[t][i]==1 && !visited[i])
            { 
                pn.push(i);
                visited[i]=true;
            }
        }
    }
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
    
    BFS(edges ,n, 0 , visited);
    
   int x;  
   for(x =0 ; x<n ;x++)
   {    if( !visited[x])
   {cout<<"false";
            break;}
   }
    if(x==n)
        cout<< "true";
    
    // delete
    delete []  visited;
    for(int i = 0 ;i <n ;i++)
        delete [] edges[i];

    delete[] edges;
    

    return 0;
}