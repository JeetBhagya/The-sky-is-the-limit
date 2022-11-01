#include <bits/stdc++.h>
using namespace std;

//using dfs
void dfs(vector<int>adj[], int src, vector<bool>&visited)
{
    visited[src]=true;
    for(auto neighbour: adj[src])
    {
        if(!visited[neighbour])
            dfs(adj, neighbour, visited);
    }
}

//using union find(disjoint set)
//why union find => those element connected , there parent also same, 
//so here we can count, how many elements are connected with parent for one connected component, as rank vector
int findPar(int x, vector<int>&parent)
{
    if(parent[x]==x) return x;
    return parent[x]=findPar(parent[x], parent);
}

void unionFind(int u, int v, vector<int>&parent, vector<int>&rank)
{
    int x=findPar(u, parent);
    int y=findPar(v, parent);
    if(rank[x]>=rank[y])
    {
        parent[y]=x;
        rank[x]++;
    }
    else if(rank[x]<rank[y])
    {
        parent[x]=y;
        rank[y]++;
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
   	
   	vector<int>adj[n];

   	for(int i=0; i<m; i++)
   	{
   		int u, v;
   		cin>>u>>v;
   		adj[u].push_back(v);
        adj[v].push_back(u);
   	}
    //using dfs
    vector<bool>visited(n, false);
    int cnt=0;

    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            cnt++;
            dfs(adj, i, visited);
        }
    }
    cout<<cnt<<endl;




//using union fiind
    vector<int>parent(n);
    vector<int>rank(n, 0);

    for(int i=0; i<n; i++) 
        parent[i]=i;

    for(int i=0; i<m; i++)
    {
        int u=*adj[i].begin();
        int v=*adj[i].begin()+1;
        unionFind(u, v, parent, rank);
    }

    int sum=0;
    for(auto x: rank) 
    {
        sum+=x;
    }
    cout<<n-sum<<endl;
}