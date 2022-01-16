#include<bits/stdc++.h>
using namespace std;
bool bipartite_BFS(int src , vector<int> adj[] , int color []){
queue<int>q;
q.push(src);
color[src] = 1;
while(!q.empty()){
    int node = q.front();
    q.pop();
    for(auto it : adj[node]){
        if(color[it] == -1){
            color[it] = 1 - color[node];
            q.push(it);
        }
        else if(color[it] == color[node]){
            return false;
        }
    }
}
return true;
}

bool check_bipartite(vector<int>adj[] , int n){
    int color[n];
    memset(color , -1 , sizeof color);
    for(int i = 0 ; i < n ; i++){
        if(color[i] == -1){
            if(!bipartite_BFS(i, adj, color)) return false;
        }
    }
    return true;
}
main(){
int n,e;
cin>>n>>e;
vector<int>adj[n];
for(int i = 0 ; i < e ; i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
if(check_bipartite(adj, n)) cout<<"YES";
else cout<<"NO";
}
