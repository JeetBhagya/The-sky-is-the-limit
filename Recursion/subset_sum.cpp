#include<bits/stdc++.h>
using namespace std;


//returns all subset of array v(no duplicate value)

void solve1(int n, vector<int>&v, int i, int sum, vector<int>&ans)
{
    if(i==n)
    {
        ans.push_back(sum);
        return;
    }
    solve1(n, v, i+1, sum+v[i], ans);
    solve1(n, v, i+1, sum, ans);
}

//returns all subset of array v(duplicate value)
//when it comes to repeatation value, always follow this technique
void solve2(int n, vector<int>&v, int i, int sum, vector<int>&ans)
{
    for(auto x: ans) cout<<x<<" ";
    cout<<endl;
    for(int ind=i; ind<n; ind++)
    {
        if(i!=ind and v[ind]==v[ind-1]) continue;
        ans.push_back(v[ind]);
        solve2(n, v, ind+1, sum, ans);
        ans.pop_back();
    }
}

int main()
{
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n=3;
    vector<int>v={1, 2, 2};
    vector<int>ans;
    solve2(n, v, 0, 0, ans);
    // sort(ans.begin(), ans.end());
    // for(auto x: ans) cout<<x<<" ";
}