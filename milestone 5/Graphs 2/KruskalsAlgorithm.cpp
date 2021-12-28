#include <iostream>
#include <algorithm>
using namespace std;

// edge class
class Edge
{
public:
    int source;
    int destination;
    int weight;
};

bool compare(Edge const & e1, Edge const & e2)
{
    return e1.weight < e2.weight;
}

// find parent func
int findParent(int n, int *parent)
{
    if (parent[n] == n)
    {
        return n;
    }
    return findParent(parent[n], parent);
}

void kruskals(Edge *input, int n, int E)
{
    // sort the input array -based on weights
    sort(input, input + E, compare);

    // output array of edge type (size = n-1)
    Edge *output = new Edge[n - 1];

    // a parent array for union algorithm (to check if currentEdge can be added to MST or not)
    int *parent = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int count = 0;
    int i = 0;
    while (count != n - 1)
    {
        Edge currentEdge = input[i];

        // check if we can add currentEdge in MST or not
        int sourceParent = findParent(currentEdge.source, parent);
        int destinationParent = findParent(currentEdge.destination, parent);

        // if source and dest's parent is different then we can add that edge
        // else we should skip that edge
        if (sourceParent != destinationParent)
        {
            output[count] = currentEdge;
            count++;
            // updating parent array
            parent[sourceParent] = destinationParent;
        }
        i++;
    }

    // printing The MST(minimum spanning tree)
    for (int i = 0; i < n - 1; i++)
    {
        if (output[i].source < output[i].destination)
        {
            cout << output[i].source << " " << output[i].destination << " " << output[i].weight << endl;
        }
        else
        {
            cout << output[i].destination << " " << output[i].source << " " << output[i].weight << endl;
        }
    }
}

int main()
{
    int n, E;
    cin >> n >> E;

    // input array of Edge type (to take input)
    Edge *input = new Edge[E];
    // taking input
    for (int i = 0; i < E; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].destination = d;
        input[i].weight = w;
    }

    // kruskal algo
    kruskals(input, n, E);
    return 0;
}