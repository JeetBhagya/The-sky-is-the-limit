#include<bits/stdc++.h>
using namespace std;

//return all subsequence of array v, elemets sum=k. here we can take element more than one.
//combination-1
void solve1(int n, vector<int>&v, int target, int i, int sum, vector<int>&ans)
{
    if(i==n)
    {
        if(sum==target)
        {
            for(auto x: ans) cout<<x<<" ";
            cout<<endl;
        }
        return;
    }
    if(sum>target) return;

    ans.push_back(v[i]);
    solve1(n, v, target, i, sum+v[i], ans);
    ans.pop_back();
    solve1(n, v, target, i+1, sum, ans);
}

//return all subsequence(unique value) of array v(having duplicate value), elemets sum=k. here we can't take element more than one.
//combination-2

void solve2(int n, vector<int>&v, int target, int i, int sum, vector<int>&ans, vector<vector<int>>&res)
{
    if(target==sum)
    {
        res.push_back(ans);
        return;
    }
    for(int ind=i; ind<v.size(); ind++)
    {
        if(ind>i and v[ind]==v[ind-1]) continue;
        //ind>i case for ind=0 coz ind-1 should stay in bound, else condition we can specify only v[ind]=v[ind-1] condition
        if(target<v[ind]) break;
        ans.push_back(v[ind]);
        solve2(n, v, target, ind+1, sum+v[ind], ans, res);
        ans.pop_back();
        
    }
}

int main()
{
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n=5, target=3;
    vector<int>v={1, 1, 1, 2, 2};
    vector<int>ans;
    vector<vector<int>>res;
    // solve1(n, v, target, 0, 0, ans);
    solve2(n, v, target, 0, 0, ans, res);
    for(auto x: res)
    {
        for(auto y: x) cout<<y<<" ";
        cout<<endl;
    }
}