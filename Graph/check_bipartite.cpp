#include <bits/stdc++.h>
using namespace std;
bool check_Bipartite_using_bfs(int src, vector<int> adj[], int color[])
{
    queue<int> q;
    q.push(src);
    color[src] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if (color[it] == color[node])
                return false;
        }
    }
    return true;
}

bool is_bipartite(vector<int> adj[], int n)
{
    int color[n];
    memset(color, -1, sizeof color);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!check_Bipartite_using_bfs(i, adj, color))
                return false;
        }
    }
    return true;
}

main()
{
    int t;
    cin >> t;
    do
    {
        int n, m;
        cin >> n >> m;
        vector<int> adj[n];
        for (int i = 0; i < m; ++i)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if (is_bipartite(adj, n))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    } while (t--);
}