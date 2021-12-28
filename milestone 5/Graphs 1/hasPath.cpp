#include <iostream>
#include <queue>
using namespace std;



bool haspath(int**graph ,int v ,bool* visited,int s ,int e)
{
    if(graph[s][e]==1){
        return true;
    }
    visited[s] = true;
    bool ans = false;
    for (int i = 0; i < v; i++)
    {
        if (graph[s][i] == 1 && !visited[i])
        {
            ans = haspath(graph,v,visited,i,e);
        }
        if(ans == true){
            return true;
        }
        
    }
    return false;
}




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
    
    if(haspath(edges,n,visited,s,end))
        cout<< "true";
    else 
        cout<<"false";

    return 0;
}