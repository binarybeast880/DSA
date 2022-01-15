#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pp pop_back
#define vi vector<int>
#define vll vector<ll>
#define rep(i, a, b) for (i = a; i < b; i++)
vector<int> adj(8741, -1);
void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storedfstraversal)
{
    storedfstraversal.pb(node);
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(it, vis, adj, storedfstraversal);
    }
}

void dfs_Traversal(int v, vector<int> adj[])
{
    vector<int> storedfstraversal;
    vector<int> vis(v, 0);
    for (int i = 1; i < v; i++)
    {
        if (!vis[i])
            dfs(i, vis, adj, storedfstraversal);
    }
    cout << "DFS traversal of the given graph is here" << '\n';
    for (int i = 0; i < storedfstraversal.size(); i++)
        cout << storedfstraversal[i] << " ";
}

vector<int> bfsTraversal(int v, vector<int> adj[])
{
    vector<int> storebfs;
    vector<int> vis(v + 1, 0);
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        storebfs.pb(node);
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                q.push(it);
                vis[it] = 1;
            }
        }
    }
    cout << "BFS traversal of the given graph is\n";
    for (auto x : storebfs)
        cout << x << " ";
    cout << "\n";
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex " << v
             << "\n head ";
        for (auto x : adj[v])
            cout << "-> " << x;
        printf("\n");
    }
}
main()
{
    int V = 4;
    cout << "Enter no of vertices\n";
    cin >> V;
    vector<int> adj[V + 1];
    for (int i = 0; i < V; i++)
    {
        int u; // doing 0 based indexing
        int v;
        cin >> u >> v;

        // adj[u].pb(v);
        // adj[v].pb(u);
        addEdge(adj, u, v);
    }
    printGraph(adj, V);    // function to print the graph
    bfsTraversal(V, adj);  // function to print the bfs traversal of the given graph
    dfs_Traversal(V, adj); // function to print the dfs traversal of the graph
}