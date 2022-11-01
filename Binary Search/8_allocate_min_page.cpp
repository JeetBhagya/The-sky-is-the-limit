#include<bits/stdc++.h>
using namespace std;

bool isPos(int n, vector<int>&v, int k, int mid)
{
	int Stcnt=1;
	int cntPage=0;
	for(int i=0; i<n; i++)
	{
		cntPage+=v[i];
		if(cntPage>mid)
		{
			Stcnt++;
			cntPage=v[i];
		}
		if(Stcnt>k) return false;
	}
	return true;
}
// 10, 20, 30, 40};
int Max_page(int n, vector<int>&v, int k)
{
	int sum=0, mini=INT_MAX;
	for(int i=0; i<n; i++)
	{
		mini=min(mini, v[i]);
		sum+=v[i];
	}
	int s=mini, e=sum;
	int ans=-1;
	while(s<=e)
	{
		int mid=s+(e-s)/2;
		if(isPos(n, v, k, mid))
		{
			ans=mid;
			e=mid-1;
		}
		else s=mid+1;
	}
	return ans;
}
int main()
{
	int n=4;
	vector<int>v={10, 20, 30, 40};
	int k=2;
	cout<<Max_page(n, v, k)<<endl;
}