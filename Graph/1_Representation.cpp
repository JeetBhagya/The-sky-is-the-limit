#include <bits/stdc++.h>
using namespace std;



//storing by 2d matrix
//complexity: O(n*n)
int main()
{
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
   	
   	int n, m;
   	cin>>n>>m;
   	
   	int adj[n+1][n+1];

   	for(int i=0; i<m; i++)
   	{
   		int u, v;
   		cin>>u>>v;
   		adj[u][v]=1;
   		adj[v][u]=1;
   	}
}


//storing by adjacency list
//complexity: O(n+2e)

// 1)undirected graph
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
}   

// 2)directed graph
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
} 


// 1)weighted graph
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
} 