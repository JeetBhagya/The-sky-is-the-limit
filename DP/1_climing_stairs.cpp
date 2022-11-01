#include<bits/stdc++.h>
using namespace std;

//recursive

int climb1(int n)
{
	if(n==0 or n==1) return 1;

	return climb1(n-1)+climb1(n-2);
}


int climb2(int n, vector<int>&dp)
{
	if(n==0 or n==1) return 1;

	if(dp[n]!=-1) return dp[n];

	return dp[n]=climb2(n-1, dp)+climb2(n-2, dp);
}

int climb3(int n)
{
	vector<int>dp(n+1);
	dp[0]=dp[1]=1;
	for(int i=2; i<=n; i++)
	{
		dp[i]=dp[i-1]+dp[i-2];
	}
	return dp[n];
}

int main()
{
	int n=7;
	cout<<climb1(n)<<endl;

	vector<int>dp(n+1, -1);
	cout<<climb2(n, dp)<<endl;
	cout<<climb3(n)<<endl;
}