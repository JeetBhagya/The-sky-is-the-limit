#include<bits/stdc++.h>
using namespace std;

int max_non_adj(int n, vector<int>arr)
{
	if(n==0) return arr[0];
	if(n<0) return 0;

	int pick=arr[n]+max_non_adj(n-2, arr);
	int non_pick=0+max_non_adj(n-1, arr);

	return max(pick, non_pick);
}

int max_non_adj2(int n, vector<int>arr, vector<int>&dp)
{
	if(n==0) return arr[0];
	if(n<0) return 0;
	if(dp[n]!=-1) return dp[n];

	int pick=arr[n]+max_non_adj(n-2, arr);
	int non_pick=0+max_non_adj(n-1, arr);
	return dp[n]=max(pick, non_pick);
}

int max_non_adj3(int n, vector<int>arr)
{
	vector<int>dp(n+1);
	dp[0]=arr[0];
	dp[1]=arr[0];
	for(int i=2; i<=n; i++)
	{
		int pick=arr[i]+dp[n-2];
		int non_pick=0+dp[n-1];
		dp[i]=max(pick, non_pick);
	}
	return dp[n];
}

int main()
{
	int n=4;
	vector<int>arr={2, 1, 4, 9};
	cout<<max_non_adj(n-1, arr)<<endl;

	vector<int>dp(n+1, -1);
	cout<<max_non_adj2(n-1, arr, dp)<<endl;

	cout<<max_non_adj3(n-1, arr)<<endl;
}