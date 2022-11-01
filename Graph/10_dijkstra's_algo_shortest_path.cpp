#include <bits/stdc++.h>
using namespace std;

void shortest_path(int n, vector<pair<int, int>>adj[], int src)
{
    vector<int>dist(n+1, INT_MAX);
    dist[src]=0;
    priority_queue<pair<int, int>>pq;
    pq.push({0, src});
    while(!pq.empty())
    {
        pair<int, int>top=pq.top();
        pq.pop();
        int dis=top.first;
        int node=top.second;
        for(auto x: adj[node])
        {
            if(dist[x.first]>(dis+x.second))
            {
                dist[x.first]=dis+x.second;
                pq.push({dist[x.first], x.first});
            }
        }
    }
    for(int i=1; i<=n; i++) dist[i]==INT_MAX ? cout<<"INT_MAX"<<" " : cout<<dist[i]<<" ";
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    int n, m;
    cin>>n>>m;
    
    vector<pair<int, int>>adj[n+1];

    for(int i=0; i<m; i++)
    {
        int u, v, wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    
    shortest_path(n, adj, 1);
}