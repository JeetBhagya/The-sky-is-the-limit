#include <bits/stdc++.h>
using namespace std;

void findtopo(int src, vector<pair<int, int>>adj[], vector<bool>&visited, stack<int>&st)
{
    visited[src]=true;

    for(auto x: adj[src])
    {
        if(!visited[x.first])
        {
            findtopo(x.first, adj, visited, st);
        }
    }
    st.push(src);
}

stack<int>topoSort(int n, vector<pair<int, int>>adj[])
{
    vector<bool>visited(n+1, false);
    stack<int>st;

    for(int i=1; i<=n; i++)
    {
        if(!visited[i]) findtopo(i, adj, visited, st);
    }
    return st;
}


void shortest_path(int n, vector<pair<int, int>>adj[], int src)
{
    stack<int>st=topoSort(n, adj);
    vector<int>dist(n+1, INT_MAX);
    dist[src]=0;
    while(!st.empty())
    {
        int top=st.top();
        st.pop();
        for(auto x: adj[top])
        {
            if(dist[x.first]>(x.second+dist[top]))
            {
                dist[x.first]=x.second+dist[top];
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
    
    vector<pair<int, int>>adj[n+1];

    for(int i=0; i<m; i++)
    {
        int u, v, wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v, wt});
    }
    
    shortest_path(n, adj, 1);
}