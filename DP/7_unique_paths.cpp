#include<bits/stdc++.h>
using namespace std;


int unique_path(int row, int col)
{
	if(row<0 or col<0) return 0;
	if(row==0 and col==0) return 1;

	int up=unique_path(row-1, col);
	int left=unique_path(row, col-1);

	return up+left;
}

int unique_path1(int row, int col, vector<vector<int>>&dp)
{
	if(row<0 or col<0) return 0;
	if(row==0 and col==0) return 1;
	if(dp[row][col]!=-1) return dp[row][col];
	int up=unique_path(row-1, col);
	int left=unique_path(row, col-1);

	return dp[row][col]=up+left;
}


int unique_path2(int row, int col)
{
	vector<vector<int>>dp(row+1, vector<int>(col+1));

	for(int i=0; i<=row; i++)
	{
		for(int j=0; j<=col; j++)
		{
			if(i==0 and j==0) dp[i][j]=1;
			else
			{
				int up=dp[i-1][j];
				int left=dp[i][j-1];
				dp[i][j]=up+left;
			}
		}
	}
	return dp[row][col];
}



int main()
{
	int row=3, col=2;
	cout<<unique_path(row-1, col-1)<<endl;

	vector<vector<int>>dp(row+1, vector<int>(col+1, -1));
	cout<<unique_path1(row-1, col-1, dp)<<endl;

	cout<<unique_path2(row-1, col-1)<<endl;
}