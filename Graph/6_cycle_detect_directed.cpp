#include <bits/stdc++.h>
using namespace std;

//using bfs (kahn's algorithm-topology sort)
//if topo sort is possible means it is a direted acyclic graph, not a cyclic graph

bool isCyclicBFS(int n, vector<int>adj[])
{
    vector<int>indegree(n+1, 0);
    for(int i=1; i<=n; i++)
    {
        for(auto x: adj[i])
        {
            indegree[x]++;
        }
    }
    queue<int>q;
    for(int i=1; i<=n; i++)
    {
        if(indegree[i]==0) q.push(i);
    }
    int cnt=0; //for storing the count of topo sort elements
    while(!q.empty())
    {
        int top=q.front();
        q.pop();
        cnt++; //counting the elements which can sort 
        for(auto x: adj[top])
        {
            indegree[x]--;
            if(indegree[x]==0) q.push(x);
        }
    }
    if(cnt==n) //cnt==n means it can sort all the elements, topo sort is possible
        return false;
    return true;
}



//using dfs

bool cycle(int src, vector<int>adj[], vector<bool>&visit, vector<bool>&dfsvisit)
{
    visit[src]=true;
    dfsvisit[src]=true;
    
    for(auto x: adj[src])
    {
        if(!visit[x])
        {
            if(cycle(x, adj, visit, dfsvisit))
                return true;
        }
        else if(dfsvisit[x]) return true;
    }
    dfsvisit[src]=false;
    return false;
}

bool isCyclicDFS(int V, vector<int> adj[]) 
{
    vector<bool>visit(V+1, false);
    vector<bool>dfsvisit(V+1, false);
    for(int i=0; i<V; i++)
    {
        if(!visit[i])
        {
            if(cycle(i, adj, visit, dfsvisit)) return true;
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
    }

    cout<<isCyclicDFS(n, adj)<<endl;
    cout<<isCyclicBFS(n, adj)<<endl;
}