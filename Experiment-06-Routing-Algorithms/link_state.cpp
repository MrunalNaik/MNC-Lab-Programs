// uses Dijkstra algorithm (single source shortest path algorithm) to find the shortest path from a source node to all other nodes in a network
#include <iostream>
#include <climits>
using namespace std;

int cost[10][10];
int dist[10]; // 1D array that stores the shortest dist from the source router
bool visited[10];
int parent[10];
int routers;
int source;

void input()
{
    cout << "enter number of routers : ";
    cin >> routers;

    cout << "enter cost matrix(999 for infinity) : \n";
    for (int i = 0; i < routers; i++)
    {
        for (int j = 0; j < routers; j++)
        {
            cin >> cost[i][j];
        }
    }

    cout << "enter source router : ";
    cin >> source;
    source--; // decrementing source to make it 0-indexed beacuse array starts at 0
}

void dijkstra()
{
    for (int i = 0; i < routers; i++)
    {
        dist[i] = cost[source][i];
        visited[i] = false;
        parent[i] = source;
    }

    dist[source] = 0;
    visited[source] = true;

    for (int i = 0; i < routers - 1; i++)
    {
        int minDistance = INT_MAX;
        int minIndex = -1;

        // Find the unvisited router having the minimum dist
        for (int j = 0; j < routers; j++)
        {
            if (!visited[j])
            {
                if (dist[j] < minDistance)
                {
                    minDistance = dist[j];
                    minIndex = j;
                }
            }
        }

        if (minIndex == -1)
            break;

        visited[minIndex] = true;

        // Update the dist of the neighboring routers of the selected router
        //         Router j should not already be visited.
        // There should be a connection (cost[minIndex][j] != 999).
        // The new path should be shorter than the current dist[j].
        for (int j = 0; j < routers; j++)
        {
            if (!visited[j] && cost[minIndex][j] != 999 && dist[minIndex] != 999) //dist[minIndex] != 999 for disconnected graphs
            {
                if (dist[minIndex] + cost[minIndex][j] < dist[j])
                {
                    dist[j] = dist[minIndex] + cost[minIndex][j];
                    parent[j] = minIndex;
                }
            }
        }
    }
}

void display()
{
    cout << "\nShortest Distance from router " << source + 1 << endl;
    cout << "Destination\tDistance\n";

    for (int i = 0; i < routers; i++)
    {
        cout << i + 1 << "\t\t" << dist[i] << endl;
    }
}

int main()
{
    input();
    dijkstra();
    display();
}