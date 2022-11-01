#include<bits/stdc++.h>
using namespace std;

int frogJump1(int n, vector<int>energy)
{
	if(n==0) return 0;
	if(n==1) return abs(energy[0] - energy[1]);
	int oneJump=frogJump1(n-1, energy)+abs(energy[n] - energy[n-1]);
	int twoJump=INT_MAX;
	// if(n>1) 
		twoJump=frogJump1(n-2, energy) + abs(energy[n]- energy[n-2]);

	return min(oneJump, twoJump);
}

int frogJump2(int n, vector<int>&energy, vector<int>&dp)
{
	if(n==0) return 0;
	if(n==1) return abs(energy[0] - energy[1]);
	if(dp[n]!=-1) return dp[n];

	int oneJump=frogJump2(n-1, energy, dp)+abs(energy[n] - energy[n-1]);
	int twoJump=INT_MAX;
	// if(n>1) 
		twoJump=frogJump2(n-2, energy, dp) + abs(energy[n]- energy[n-2]);

	return dp[n]=min(oneJump, twoJump);
}

int frogJump3(int n, vector<int>energy)
{
	vector<int>dp(n+1);
	dp[0]=0;
	dp[1]=abs(energy[0] - energy[1]);
	// vector<int>dp(n+1);
	for(int i=2; i<=n; i++)
	{
		int oneJump=dp[i-1]+abs(energy[n] - energy[n-1]);
		int twoJump=dp[i-2] + abs(energy[n]- energy[n-2]);

		dp[i]=min(oneJump, twoJump);
	}
	return dp[n];
}

int main()
{
	int n=4;
	vector<int>energy={10, 20, 30, 10};

	cout<<frogJump1(n-1, energy)<<endl;

	vector<int>dp(n+1, -1);
	cout<<frogJump2(n-1, energy, dp)<<endl;

	cout<<frogJump3(n-1, energy)<<endl;
}