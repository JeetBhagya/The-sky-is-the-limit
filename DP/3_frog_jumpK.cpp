#include<bits/stdc++.h>
using namespace std;


//recursive
int frogJumpk1(int n, vector<int>energy, int k)
{
	if(n==0) return 0;

	int mini=INT_MAX;
	for(int i=1; i<=k; i++)
	{
		if(n-i>=0)
		{
			int jump=frogJumpk1(n-i, energy, k)+abs(energy[n] - energy[n-i]);
			mini=min(mini, jump);
		}
	}
	return mini;
}

//memoization
int frogJumpk2(int n, vector<int>energy, int k, vector<int>&dp)
{
	if(n==0) return 0;

	if(dp[n]!=-1) return dp[n];

	int mini=INT_MAX;
	for(int i=1; i<=k; i++)
	{
		if(n-i>=0)
		{
			int jump=frogJumpk2(n-i, energy, k, dp)+abs(energy[n] - energy[n-i]);
			mini=min(mini, jump);
		}
	}
	return dp[n]=mini;
}

//top down
int frogJumpk3(int n, vector<int>energy, int k)
{
	vector<int>dp(n+1);
	dp[0]=0;

	for(int j=1; j<=n; j++)
	{
		int mini=INT_MAX;
		for(int i=1; i<=k; i++)
		{
			if(j-i>=0)
			{
				int jump=dp[j-i]+abs(energy[j] - energy[j-i]);
				mini=min(mini, jump);
			}
		}
		dp[j]=mini;
	}
	return dp[n];
}

int main()
{
	int n=4;
	vector<int>energy={10, 20, 30, 10};
	int k=2;

	cout<<frogJumpk1(n-1, energy, k)<<endl;

	vector<int>dp(n+1, -1);
	cout<<frogJumpk2(n-1, energy, k, dp)<<endl;

	cout<<frogJumpk3(n-1, energy, k)<<endl;
}