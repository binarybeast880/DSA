//  prims algo
// // TC-->O(N+E)+O(NlogN) ~= O(NlogN)
#include <bits/stdc++.h>
 using namespace std;
 main()
 {
     int n, m;
     cin >> n >> m;
     vector<pair<int, int>> adj[n + 1];
     int a, b, wt;
     for (int i = 0; i < m; i++)
     {
         cin >> a >> b >> wt;
         adj[a].push_back(make_pair(b, wt));
         adj[b].push_back(make_pair(a, wt));
     }
     int parent[n];
     vector<int> key(n, INT_MAX), mstset(n, -1);
     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
          key[0] = 0;
   parent[0] = -1;
     pq.push({0, 0});
     for (int i = 0; i < n - 1; i++)
     {
         int u = pq.top().second;
         pq.pop();
        mstset[u] = 1;
         for (auto it : adj[u])
         {
             int v = it.first;
             int wt = it.second;
             if (mstset[v] == -1 & wt < key[v])
             {
                 parent[v] = u;
                 pq.push({key[v], v});
                 key[v] = wt;
             }
         }
     }
     for (int i = 1; i < n; i++)
         cout << parent[i] << "--" << i << "\n";
 }


/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, m;
    cin >> N >> m;
    vector<pair<int, int>> adj[N];

    int a, b, wt;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> wt;
        adj[a].push_back(make_pair(b, wt));
        adj[b].push_back(make_pair(a, wt));
    }

    int parent[N];

    int key[N];

    bool mstSet[N];

    for (int i = 0; i < N; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    parent[0] = -1;
    pq.push({0, 0});
    // Run the loop till all the nodes have been visited
    // because in the brute code we checked for mstSet[node] == false while computing the minimum
    // but here we simply take the minimal from the priority queue, so a lot of times a node might be taken twice
    // hence its better to keep running till all the nodes have been taken.
    // try the following case:
    // Credits: Srejan Bera
    // 6 7
    // 0 1 5
    // 0 2 10
    // 0 3 100
    // 1 3 50
    // 1 4 200
    // 3 4 250
    // 4 5 50
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        mstSet[u] = true;

        for (auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v])
            {
                parent[v] = u;
                key[v] = weight;
                pq.push({key[v], v});
            }
        }
    }

    for (int i = 1; i < N; i++)
        cout << parent[i] << " - " << i << " \n";
    return 0;
}
*/
