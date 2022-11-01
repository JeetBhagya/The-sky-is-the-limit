#include <bits/stdc++.h>
using namespace std;

//TC: O(v*V)
void prims1(int n, int src, vector<pair<int, int>>adj[])
{
    vector<int>key(n+1, INT_MAX);
    key[src]=0;
    vector<bool>mst(n+1, false);
    vector<int>parent(n+1, -1);

    for(int i=1; i<n; i++)
    {
        int mini=INT_MAX, top;
        for(int v=1; v<=n; v++)
        {
            if(!mst[v] and key[v]<mini)
            {
                mini=key[v];
                top=v;
            }
        }
        mst[top]=true;
        for(auto neighbour: adj[top])
        {
            if(!mst[neighbour.first] and parent[neighbour.first]==-1 and key[neighbour.first]>neighbour.second)
            {
                key[neighbour.first]=neighbour.second;
                parent[neighbour.first]=top;
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        cout<<parent[i]<<" ";
    }
}


//optimization using priority queue
//TC-O(V*logn+E)
void prims2(int n, int src, vector<pair<int, int>>adj[])
{
    vector<int>key(n+1, INT_MAX);
    key[src]=0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    pq.push({0, src});
    vector<bool>mst(n+1, false);
    vector<int>parent(n+1, -1);

    for(int i=1; i<n; i++)
    {
        int top=pq.top().second;
        pq.pop();
        mst[top]=true;
        for(auto neighbour: adj[top])
        {
            if(!mst[neighbour.first] and parent[neighbour.first]==-1 and key[neighbour.first]>neighbour.second)
            {
                key[neighbour.first]=neighbour.second;
                pq.push({key[neighbour.first], neighbour.first});
                parent[neighbour.first]=top;
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        cout<<parent[i]<<" ";
    }
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
    
    prims1(n, 1, adj);
    cout<<endl;
    prims2(n, 1, adj);
}