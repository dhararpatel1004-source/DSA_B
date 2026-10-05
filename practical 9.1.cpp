#include <iostream>
#include <queue>
using namespace std;

int graph[20][20];
int visited[20];
int n;

void DFS(int node)
{
    visited[node] = 1;

    cout << node << " ";

    for(int i = 0; i < n; i++)
    {
        if(graph[node][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

void BFS(int start)
{
    for(int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    queue<int> q;

    q.push(start);
    visited[start] = 1;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for(int i = 0; i < n; i++)
        {
            if(graph[node][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

int main()
{
    cout << "Enter number of buildings: ";
    cin >> n;

    cout << "Enter adjacency matrix:" << endl;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    int start;

    cout << "Enter starting building: ";
    cin >> start;

    for(int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    cout << "DFS Traversal: ";
    DFS(start);

    cout << endl;

    cout << "BFS Traversal: ";
    BFS(start);

    cout << endl;

    return 0;
}
