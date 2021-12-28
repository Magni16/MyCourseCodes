#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
using namespace std;


vector<int> * getpath( int ** graph , int v , int s ,int e , bool * visited)
{
    queue<int> pn;
    unordered_map<int ,int> m;
    pn.push(s);
    visited[s]=true;

    while(!pn.empty())
    {
        int t= pn.front();
        
        pn.pop();
       

        for(int i=0 ; i<v ;i++)
        {
            if(graph[t][i]==1 && !visited[i])
            { 
                pn.push(i);
                m[i]=t;
                
                visited[i]=true;
                if(i==e)
                {
                    vector<int> * ans = new vector<int>();
                    
                    ans->push_back(e);
                    int x =e;
                    while(m[x]!=s)
                    {
                        ans->push_back(m[x]);
                        x=m[x];
                    }
                    ans->push_back(s);
                    
                    return ans;
                }
            }
        }
        
    }     
    return NULL;
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
    
    vector<int> * ans = getpath(edges , n, s, end, visited);
    if(ans)
    {
    for(int i=0 ;i< ans->size(); i++)
        cout<< ans->at(i) << " ";
    }
    
    // delete
    delete []  visited;
    for(int i = 0 ;i <n ;i++)
        delete [] edges[i];

    delete[] edges;
    

    return 0;
}