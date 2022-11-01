#include <bits/stdc++.h>
using namespace std;

// vector<bool>visited={false};
// vector<int>ans={};
void dfs(int src, vector<int>adj[], vector<bool>&visited, vector<int>&ans)
{
    ans.push_back(src);
    visited[src]=true;
    for(auto x: adj[src])
    {
        if(!visited[x])
        {
            dfs(x, adj, visited, ans);
        }
    }
}

vector<int> complete_dfs(int n, vector<int>adj[])
{
    vector<bool>visited(n+1, false);
    vector<int>ans;
    for(int i=1; i<=n; i++)
    {
        if(!visited[i]) 
            dfs(i, adj, visited, ans);
    }
    return ans;
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

    vector<int>ans=complete_dfs(n, adj);
    for(auto x: ans) cout<<x<<" ";
}