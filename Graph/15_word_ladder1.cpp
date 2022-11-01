#include <bits/stdc++.h>
using namespace std;

void shortest_path(unordered_map<string, unordered_set<string>>edges, string src, string t)
{
    // vector<int>dist(n+1, INT_MAX);
    // dist[src]=0;

    unordered_map<string, int>dist;
    for(auto x: edges)
    {
        // for(auto y: edges[x.first])
        // {
            dist[x.first]=INT_MAX;
            // visited[x.first]={x.first, false};
        // }
    }
    dist[src]=0;
    queue<string>q;
    q.push(src);

    while(!q.empty())
    {
        string top=q.front();
        q.pop();
        // for(auto x: edges)
        // {
            for(auto y: edges[top])
            {
                if((1+dist[top])<dist[y])
                {
                    dist[y]=1+dist[top];
                    q.push(y);
                }
            }
        // }
    }
    int ans=INT_MIN;
    for(auto x: dist)
    {
        cout<<x.first<<" : "<<x.second<<endl;
        // ans=max(ans, x.second);
    }
    // cout<<ans<<endl;
    cout<<dist[t]<<endl;
    // return ans;
}

void wordLadderLength(string s, string t, vector<string>&words) 
{
    unordered_map<string, unordered_set<string>>edges;

    if(find(words.begin(), words.end(), s)==words.end()) 
        words.push_back(s);

    for(auto str: words)
    {
        string temp=str;
        for(int i=0; i<str.size(); i++)
        {
            for(char c='a'; c<='z'; c++)
            {
                temp[i]=c;

                if(find(words.begin(), words.end(), temp)!=words.end() and temp!=str)
                {
                    edges[str].insert(temp);
                }
                temp=str;
            }
        }
    }
    // cout<<"edges: "<<endl;
    // for(auto x: edges)
    // {
    //     cout<<x.first<<":-";
    //     for(auto y: edges[x.first]) cout<<y<<" ";
    //     cout<<endl;
    // }
    // cout<<endl;

    shortest_path(edges, s, t);

}

int main()
{
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
   	
   	vector<string>words={"hot","pot","pod","dod","dog", "hog", "hig", "hit"};

   	wordLadderLength("hot", "hit", words);

}