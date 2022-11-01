#include <bits/stdc++.h>
using namespace std;

//topo sort: if u->v then in the topo sort u always stays before v



//using bfs or kahn's algorithm

//step1: indegree of each node, store in a vector
//step2: indegree with 0, initially put in a queue
//step3: take the deont node from the queue
//       i)push in ans vector
//      ii)for each adjacent decrease the indegree by 1
//     iii)if indegree is zero push in queue
//step4: repeat

vector<int>topoSortBFS(int n, vector<int>adj[])
{
    vector<int>indegree(n+1, 0);
    for(int i=1; i<=n; i++)
    {
        for(auto x: adj[i]) 
            indegree[x]++;
    }

    queue<int>q;
    for(int i=1; i<=n; i++)
    {
        if(indegree[i]==0) q.push(i);
    }

    vector<int>ans;
    while(!q.empty())
    {
        int top=q.front();
        q.pop();
        ans.push_back(top);
        for(auto x: adj[top])
        {
            indegree[x]--;
            if(indegree[x]==0) q.push(x);
        }
    }
    return ans;
}




//using dfs

void findTopoSort(int src, vector<int>adj[], vector<bool>&visited, stack<int>&st)
{
    visited[src]=true;

    for(auto neighbour: adj[src])
    {
        if(!visited[neighbour])
        {
            findTopoSort(neighbour, adj, visited, st);
        }
    }
    st.push(src);
}

vector<int>topoSortDFS(int n, vector<int>adj[])
{
    vector<bool>visited(n+1, false);
    stack<int>st;
    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            findTopoSort(i, adj, visited, st);
        }
    }
    vector<int>ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
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
    }

    vector<int>ans=topoSortDFS(n, adj);
    for(auto x: ans) cout<<x<<" ";
    cout<<endl;
    vector<int>ans1=topoSortBFS(n, adj);
    for(auto x: ans1) cout<<x<<" ";
}