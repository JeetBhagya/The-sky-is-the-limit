#include<bits/stdc++.h>
using namespace std;


bool isSafe(vector<vector<int>>&v, int row, int col, int ele)
{
    for(int i=0; i<9; i++)
    {
        if(v[row][i]==ele) return false;
        if(v[i][col]==ele) return false;
        if(v[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==ele) return false;
    }
    return true;
}

bool solve(vector<vector<int>>&v)
{
    for(int row=0; row<9; row++)
    {
        for(int col=0; col<9; col++)
        {
            if(v[row][col]=='.')
            {
                for(int ele=0; ele<10; ele++)
                {
                    if(isSafe(v, row, col, ele))
                    {
                        v[row][col]=ele;
                        if(solve(n, v)) return true;
                        v[row][col]='.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}


int main()
{
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    vector<vector<int>>v;
    cout<<solve(v)<<endl;
}