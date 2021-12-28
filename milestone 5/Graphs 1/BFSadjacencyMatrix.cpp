#include <iostream>
#include <queue>
using namespace std;

// print func

void printbfs(int **edges, int n, int start, int *visited)
{
    queue<int> pendingVertices;
    pendingVertices.push(start);
    visited[start] =1;
    while (!pendingVertices.empty())
    {

        int currentVertex = pendingVertices.front();
        cout << currentVertex;
        pendingVertices.pop();
        for (int i = 0; i < n; i++)
        {
            if(i == currentVertex){
                continue;
            }
            if (!visited[i] && edges[currentVertex][i] == 1)
            {
                pendingVertices.push(i);
                visited[i] = 1;
            } 
        }
    }
}

void print_BFS(int **edges, int n){
    int *visited = new int[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] =0;
    }

    // for disconnected graph
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printbfs(edges, n, i, visited);
        }
    }
    delete [] visited;
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

    
    print_BFS(edges, n);
    return 0;
}