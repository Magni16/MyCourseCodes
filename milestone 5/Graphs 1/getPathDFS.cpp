#include <iostream>
#include <queue>
#include<vector>

using namespace std;


bool getpath ( int ** graph , int v , bool* visited , int s , int e , vector<int> & res)
{
    if( s ==e)
    { res.push_back(s);
       return true;
    }

    visited[s]=true;

    bool ans =false;

    for(int i=0 ;i<v ;i++)
    {		
        if(!visited[i] && graph[s][i]==1)
            ans=getpath(graph,v,visited,i,e,res);
        if( ans== true)
        {
            res.push_back(s);
            return true;
        }

    }

    return false;
}
//main
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
    
    vector <int> res;

    if(getpath( edges , n , visited , s, end, res ))
        for(auto i : res )
            cout<< i <<" ";
    
    // delete
    delete []  visited;
    for(int i = 0 ;i <n ;i++)
        delete [] edges[i];

    delete[] edges;
    

    return 0;
}