#include<bits/stdc++.h>
using namespace std;

bool isPos(int n, vector<int>&v, int cows, int mid)
{
	int curCow=v[0];
	int cnt=1;
	for(int i=1; i<n; i++)
	{
		if((v[i]-curCow)>=mid)
		{
			cnt++;
			curCow=v[i];
		}
		if(cows==cnt)
		{
			return true;
		}
	}
	return false;
}


int aggresiveCows(int n, vector<int>&v, int cows)
{
	int s=0;
	int e=v[n-1]-v[0];

	int ans=-1;
	while(s<=e)
	{
		int mid=s+(e-s)/2;
		if(isPos(n, v, cows, mid))
		{
			ans=mid;
			s=mid+1;
		}
		else e=mid-1;
	}
	return ans;
}

int main()
{
	int n=5;
	vector<int>v={1, 2, 4, 8, 9};
	int cows=3;
	cout<<aggresiveCows(n, v, cows)<<endl;
}