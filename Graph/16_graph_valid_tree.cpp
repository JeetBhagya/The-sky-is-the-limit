#include<bits/stdc++.h>
using namespace std;

int findPar(int u, vector<int>&parent)
{
    if(u==parent[u]) return u;
    return parent[u]=findPar(parent[u], parent);
}

void unionFind(int u, int v, vector<int>&parent, vector<int>&rank)
{
    u=findPar(u, parent);
    v=findPar(v, parent);
//     if(u==v) //here we can return as false
    if(rank[u]>=rank[v])
    {
        parent[v]=u;
        rank[u]++;
    }
    else
    {
        parent[u]=v;
        rank[v]++;
    }
}

bool checkgraph(vector<vector<int>> edges, int n, int m)
{
    vector<int>parent(n);
    for(int i=0; i<n; i++) parent[i]=i;
    vector<int>rank(n, 0);
    for(auto x: edges)
    {
        int u=x[0];
        int v=x[1];
        if(parent[u]==parent[v]) return false;
        unionFind(u, v, parent, rank);
    }
    int sum=0;
    for(auto x: rank)
    {
        sum+=x;
    }
    if(n-sum==1) return true;
    return false;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    vector<vector<int>>edges={{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
    cout<<checkgraph(edges, 5, 5);

}