#include <bits/stdc++.h>
using namespace std;

void shortest_path(int n, vector<int>adj[], int src)
{
    vector<int>dist(n+1, INT_MAX);
    dist[src]=0;

    queue<int>q;
    q.push(src);

    while(!q.empty())
    {
        int top=q.front();
        q.pop();

        for(auto x: adj[top])
        {
            if((1+dist[top])<dist[x])
            {
                dist[x]=1+dist[top];
                q.push(x);
            }
        }
    }
    for(int i=1; i<=n; i++) cout<<dist[i]<<" ";
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    int n, m;
    cin>>n>>m;
    
    vector<int>adj[n+1];

    for(int i=0; i<m; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    shortest_path(n, adj, 1);
}