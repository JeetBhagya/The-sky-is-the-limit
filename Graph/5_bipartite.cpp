#include <bits/stdc++.h>
using namespace std;


//using bfs
bool bipartiteBFS(int src, vector<int>adj[], vector<int>&color, vector<bool>&visited)
{
    queue<int>q;
    q.push(src);
    color[src]=1;

    while(!q.empty())
    {
        int top=q.front();
        q.pop();

        for(auto neighbour: adj[top])
        {
            if(visited[neighbour] and color[neighbour]==color[top]) return false;

            else if(!visited[neighbour])
            {
                q.push(neighbour);
                color[neighbour]=!color[top];
                visited[neighbour]=true;
            }
        }
    }
    return true;
}

bool bipartiteDFS(int src, vector<int>adj[], vector<int>&color)
{
    if(color[src]==-1) color[src]=1;

    for(auto neighbour: adj[src])
    {
        if(color[neighbour]==-1)
        {
            color[neighbour]=1-color[src];
            if(bipartiteDFS(neighbour, adj, color)==false) return false;
        }
        else if(color[neighbour]==color[src]) return false;
    } 
    return true;
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

    vector<bool>visited(n+1, false);
    vector<int>color(n+1);

    bool ans=bipartiteBFS(1, adj, color, visited);
    cout<<ans<<endl;
    vector<int>color1(n+1, -1);
    bool ans1=bipartiteDFS(1, adj, color1);
    cout<<ans1<<endl;

}