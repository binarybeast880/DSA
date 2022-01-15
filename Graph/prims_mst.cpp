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
