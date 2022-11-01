#include <bits/stdc++.h>
using namespace std;

// 1)undirected graph
//using bfs 
bool cycle_bfs(int src, vector<int>adj[], vector<bool>&visited)
{
    queue<pair<int, int>>q;
    q.push({src, -1});
    visited[src]=true;

    while(!q.empty())
    {
        pair<int, int>top=q.front();
        q.pop();
        int node=top.first;
        int parent=top.second;
        for(auto neighbour: adj[node])
        {
            if(!visited[neighbour])
            {
                q.push({neighbour, node});
                visited[neighbour]=true;
            }
            else if(visited[neighbour] and parent!=neighbour)
            {
                return true;
            }
        }
    }
    return false;
}

bool cycleDetectBFS(int n, vector<int>adj[])
{
    vector<bool>visited(n+1, false);
    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            bool ans=cycle_bfs(i, adj, visited);
            if(ans==true) return true;
        }
    }
    return false;
}


//using dfs

bool cycle_dfs(int src, vector<int>adj[], vector<bool>&visited, int parent)
{
    visited[src]=true;
    for(auto neighbour: adj[src])
    {
        if(!visited[neighbour])
        {
            if(cycle_dfs(neighbour, adj, visited, src)) return true;
        }
        else if(neighbour!=parent) return true;
    }
    return false;
}

bool cycleDetectDFS(int n, vector<int>adj[])
{
    vector<bool>visited(n+1, false);
    // unordered_map<int, int>parent;
    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            bool ans=cycle_dfs(i, adj, visited, -1);
            if(ans) return true;
        }
    }
    return false;
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
    cout<<cycleDetectBFS(n, adj)<<endl;
    cout<<cycleDetectDFS(n, adj)<<endl;

}