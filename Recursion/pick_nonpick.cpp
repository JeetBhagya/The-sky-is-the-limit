#include<bits/stdc++.h>
using namespace std;

//return all subsequence of array v, elemets sum=k

void solve1(int n, vector<int>&v, int k, vector<int>&ans, int i, int sum)
{
	if(i==n)
	{
		if(sum==k)
		{
			for(auto x: ans) cout<<x<<" ";
			cout<<endl;
		}
		return;
	}
	if(sum>k) return;
	ans.push_back(v[i]);
	solve1(n, v, k, ans, i+1, sum+v[i]);
	ans.pop_back();
	solve1(n, v, k, ans, i+1, sum);
}


//return one subsequence from array v, elemets sum=k

bool solve2(int n, vector<int>&v, int k, vector<int>&ans, int i, int sum)
{
	if(i==n)
	{
		if(sum==k)
		{
			for(auto x: ans) cout<<x<<" ";
			cout<<endl;
			return true; //one subsequence return technique
		}
		return false; //one subsequence return technique
	}
	if(sum>k) return false;
	ans.push_back(v[i]);
	if(solve2(n, v, k, ans, i+1, sum+v[i])==true) return true; //one subsequence return technique
	ans.pop_back();
	if(solve2(n, v, k, ans, i+1, sum)==true) return true; //one subsequence return technique
}

//count the subsequences of array v, elements sum=k

int solve3(int n, vector<int>&v, int k, vector<int>&ans, int i, int sum)
{
	if(i==n)
	{
		if(sum==k)
		{
			return 1;
		}
		return 0;
	}
	if(sum>k) return 0;
	ans.push_back(v[i]);
	int pick=solve3(n, v, k, ans, i+1, sum+v[i]);
	ans.pop_back();
	int non_pick=solve3(n, v, k, ans, i+1, sum);
	return pick+non_pick;
}

int main()
{
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n=4; 
    vector<int>v={1, 2, 3, 3};
    int k=3;
    vector<int>ans;
    solve1(n, v, k, ans, 0, 0);
    solve2(n, v, k, ans, 0, 0);
    cout<<solve3(n, v, k, ans, 0, 0);
}

