#include <bits/stdc++.h>
using namespace std;


void bfs(int src, vector<int>adj[], vector<bool>&visited, vector<int>&ans)
{
    queue<int>q;
    q.push(src);
    visited[src]=true;
    while(!q.empty())
    {
        int top=q.front();
        q.pop();
        ans.push_back(top);
        for(auto  x: adj[top])
        {
            if(!visited[x])
            {
                q.push(x);
                visited[x]=true;
            }
        }
    }
}

vector<int>complete_bfs(int n, vector<int>adj[])
{
    vector<int>ans;
    vector<bool>visited(n+1, false);

    for(int i=1; i<=n; i++) //if nodes are start from 0 we can start i=0
    {
        if(!visited[i])
        {
            bfs(i, adj, visited, ans);
        }
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

    vector<int>ans=complete_bfs(n, adj);

    for(auto x: ans)
    {
        cout<<x<<" ";        
    }
}