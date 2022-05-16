#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Graph
{
public:
    int v;
    vector<vector<int>> adj;
    map<int, bool> visit;

    Graph(int v)
    {
        this->v = v;
        adj.resize(v);
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    void display_graph()
    {
        int i = 0;
        int j = 0;
        for (i = 0; i < v; i++)
        {
            cout << i << "->";
            for (j = 0; j < adj[i].size(); j++)
            {
                cout << adj[i][j] << ",";
            }
            cout << endl;
        }
    }

    void BFS_iter(int s)
    {
        vector<bool> visited(v, false);
        queue<int> q;
        visited[s] = true;
        q.push(s);
        while (!q.empty())
        {
            s = q.front();
            cout << s << " ";
            q.pop();
            int k = 0;
            for (k = 0; k < adj[s].size(); k++)
            {
                if (!visited[adj[s][k]])
                {
                    visited[adj[s][k]] = true;
                    q.push(adj[s][k]);
                }
            }
        }
    }

    void DFS_iter(int s)
    {
        vector<bool> visited(v, false);
        stack<int> q;
        q.push(s);
        visited[s] = true;
        int i = 0;
        while (!q.empty())
        {
            s = q.top();
            q.pop();
            cout << s << " ";
            for (i = 0; i < adj[s].size(); i++)
            {
                if (!visited[adj[s][i]])
                {
                    visited[adj[s][i]] = true;
                    q.push(adj[s][i]);
                }
            }
        }
    }

    void DFS(int v)
    {
        // Mark the current node as visited and
        // print it
        visit[v] = true;
        cout << v << " ";

        // Recur for all the vertices adjacent
        // to this vertex
        vector<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visit[*i])
                DFS(*i);
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);

    g.display_graph();
    g.BFS_iter(0);
    cout << endl;
    g.DFS_iter(0);
    cout << endl;
    bool arr[4];
    int i;
    for (i = 0; i < 5; i++)
    {
        arr[i] = false;
    }
    g.DFS(0);
    return 0;
}