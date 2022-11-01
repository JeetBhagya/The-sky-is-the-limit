#include<bits/stdc++.h>
using namespace std;

bool isSafe(int n, vector<string>&v, int row, int col)
{
	int duprow=row;
	int dupcol=col;
	while(row>=0 and col>=0)
	{
		if(v[row][col]=='Q') return false;
		row--; col--;
	}
	row=duprow; col=dupcol;
	while(row>=0)
	{
		if(v[row][col]=='Q') return false;
		row--;
	}
	while(col>=0)
	{
		if(v[row][col]=='Q') return false;
		col--;
	}
	return true;
}


void solve(int n, vector<string>v, int col, vector<vector<string>>&ans)
{
	if(col==n)
	{
		// ans.push_back(v);
		for(auto x: v)
		{
			for(auto y: x) cout<<y<<" ";
			cout<<endl;
		}
		return;
	}
	for(int row=0; row<n; row++)
	{
		if(isSafe(n, v, row, col))
		{
			v[row][col]='Q';
			solve(n, v, col+1, ans);
			v[row][col]='.';
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n=4;
    string s(n, '.');
    vector<string>v(n);
    for(int i=0; i<n; i++)
    {
    	v[i]=s;
    }
    vector<vector<string>>ans;
    solve(n, v, 0, ans);
}