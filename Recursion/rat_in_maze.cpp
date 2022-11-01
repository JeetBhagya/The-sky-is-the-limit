#include<bits/stdc++.h>
using namespace std;

void solve(int n, int m, vector<vector<int>>&v, int row, int col, vector<vector<bool>>&isVisit, string temp, vector<string>&ans)
{
    if(row==n-1 and col==m-1)
    {
        // cout<<temp<<endl;
        ans.push_back(temp);
        return;
    }
    //left
    if(col-1>=0 and !isVisit[row][col-1] and v[row][col-1]==1)
    {
        isVisit[row][col]=1;
        solve(n, m, v, row, col-1, isVisit, temp+'L', ans);
        isVisit[row][col]=0;
    }

    //right
    if(col+1<m and !isVisit[row][col+1] and v[row][col+1]==1)
    {
        isVisit[row][col]=1;
        solve(n, m, v, row, col+1, isVisit, temp+'R', ans);
        isVisit[row][col]=0;
    }

    //up
    if(row-1>=0 and !isVisit[row-1][col] and v[row-1][col]==1)
    {
        isVisit[row][col]=1;
        solve(n, m, v, row-1, col, isVisit, temp+'U', ans);
        isVisit[row][col]=0;
    }

    //down
    if(row+1<n and !isVisit[row+1][col] and v[row+1][col]==1)
    {
        isVisit[row][col]=1;
        solve(n, m, v, row+1, col, isVisit, temp+'D', ans);
        isVisit[row][col]=0;
    }
}

int main()
{
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n=4, m=4;
    vector<vector<int>>v{{0, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<vector<bool>>isVisit(n, vector<bool>(m, false));
    string temp="";
    vector<string>ans;
    solve(4, 4, v, 0, 0, isVisit, temp, ans);
    for(auto x: ans) cout<<x<<endl;
}