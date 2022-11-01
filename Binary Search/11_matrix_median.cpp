#include<bits/stdc++.h>
using namespace std;

int bs(vector<int>&v, int src)
{
	int s=0, e=v.size()-1;

	while(s<=e)
	{
		int mid=s+(e-s)/2;

		if(v[mid]==src) return mid+1;
		else if(v[mid]>src) e=mid-1;
		else s=mid+1;
	}
	return s;
}

int medianMatrix(vector<vector<int>>&v)
{
	int n=v.size();
	int m=v[0].size();

	int s=INT_MAX;
	int e=INT_MIN;
	for(int row=0; row<n; row++)
	{
		s=min(s, v[row][0]);
		e=max(e, v[row][m-1]);
	}
	s=0;
	while(s<=e)
	{
		int mid=s+(e-s)/2;
		int cnt=0;
		for(auto x: v)
		{
			cnt+=bs(x, mid);
		}
		if(cnt<=(n*m)/2) s=mid+1;
		else e=mid-1;
	}
	return s;
}

int main()
{
	int n=3;
	int m=4;
	vector<vector<int>>v={
							{1, 3, 5},
							{2, 6, 9},
							{3, 6, 9},
						};

	cout<<medianMatrix(v)<<endl;

}