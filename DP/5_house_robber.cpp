#include<bits/stdc++.h>
using namespace std;

int rec(int s, int e, vector<int>arr)
{
	if(n<0) return 0;
	if(n==0) return arr[0];

	int pick=arr[e]+rec(s, e-2, arr);
	int nonpick=0+rec(s, e-1, arr);
	return max(pick, nonpick);
}

int max_non_adj3(int s, int e, vector<int>arr)
{
	vector<int>dp(e+1);
	dp[0]=arr[s];
	dp[1]=arr[s];
	for(int i=2; i<=e; i++)
	{
		int pick=arr[i]+dp[e-2];
		int non_pick=0+dp[e-1];
		dp[i]=max(pick, non_pick);
	}
	return dp[e];
}

int main()
{
	int n=4;
	vector<int>arr={2, 1, 4, 9};
	
	// leaving last element
	int ans1=max_non_adj3(0, n-2, arr);
	int ans2=max_non_adj3(1, n-1, arr);
	cout<<max(ans1, ans2);

}