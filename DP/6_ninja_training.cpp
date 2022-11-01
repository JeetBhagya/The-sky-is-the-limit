#include<bits/stdc++.h>
using namespace std;

int ninja_training(vector<vector<int>>&grid, int day, int last)
{
	if(day==0)
	{
		int maxi=0;
		for(int i=0; i<3; i++)
		{
			if(i!=last)
			{
				maxi=max(maxi, grid[0][i]);
			}
		}
		return maxi;
	}

	int maxi=0;
	for(int i=0; i<3; i++)
	{
		if(i!=last)
		{
			int x=grid[day][i]+ninja_training(grid, day-1, i);
			maxi=max(maxi, x);
		}
	}
	return maxi;
}

int main()
{
	int n=3;
	vector<vector<int>>grid={{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
	int day=2, last=-1;
	cout<<ninja_training(grid, day, last)<<endl;
}