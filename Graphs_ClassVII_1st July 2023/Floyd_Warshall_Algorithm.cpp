#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adjList;
    void addEdge(int u, int v, int wt, bool direction)
    {
        // direction = 1 -> undirected
        // direction = 0 -> directed
        adjList[u].push_back({v, wt});
        if (direction == 1)
        {
            adjList[v].push_back({u, wt});
        }
    }
    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << "(" << j.first << "," << j.second << "), ";
            }
            cout << endl;
        }
    }
    void floydWarshall(int n)
    {
        vector<vector<int>> dist(n, vector<int>(n, 100000));
        // Place 0 at diagonal
        for (int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }
        // Traverse the adjacency list
        for (auto t : adjList)
        {
            for (auto nbr : t.second)
            {
                int u = t.first;
                int v = nbr.first;
                int wt = nbr.second;
                dist[u][v] = wt;
            }
        }
        for (int helper = 0; helper < n; helper++)
        {
            for (int src = 0; src < n; src++)
            {
                for (int dest = 0; dest < n; dest++)
                {
                    dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
                }
            }
        }
        cout << "Printing the answer" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << dist[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 3, 0);
    g.addEdge(0, 3, 5, 0);
    g.addEdge(1, 0, 2, 0);
    g.addEdge(1, 3, 4, 0);
    g.addEdge(2, 1, 1, 0);
    g.addEdge(3, 2, 2, 0);
    g.floydWarshall(4);

    return 0;
}