#include<bits/stdc++.h>
using namespace std;

int firstOccurance(int n, vector<int>&v, int k)
{
	int s=0, e=n-1;
	int ans=-1;
	while(s<=e)
	{
		int mid=s+(e-s)/2;
		if(v[mid]>=k)
		{
			ans=mid;
			e=mid-1;
		}
		else s=mid+1;
	}
	return ans;
}

int lastOccurance(int n, vector<int>&v, int k)
{
	int s=0, e=n-1;
	int ans=-1;
	while(s<=e)
	{
		int mid=s+(e-s)/2;
		if(v[mid]>k)
		{
			e=mid-1;
		}
		else 
		{
			ans=mid;
			s=mid+1;
		}
	}
	return ans;
}

int main()
{
	int n=5;
	vector<int>v={1, 3, 3, 3, 5};
	cout<<"first Occurance: "<<firstOccurance(n, v, 3)<<endl;
	cout<<"last Occurance: "<<lastOccurance(n, v, 3)<<endl;

	cout<<"Element 3 present in array v is: "<<lastOccurance(n, v, 3)-firstOccurance(n, v, 3)+1<<endl;
}