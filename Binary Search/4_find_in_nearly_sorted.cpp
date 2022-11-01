#include<bits/stdc++.h>
using namespace std;

int Seach(int n, vector<int>&v, int k)
{
	int s=0, e=n-1;
	while(s<=e)
	{
		int mid=s+(e-s)/2;
		if(v[mid]==k) 
			return mid;
		else if(mid-1>=0 and v[mid-1]==k) 
			return mid-1;
		else if(mid+1<n and v[mid+1]==k) 
			return mid+1;
		else if(v[mid]>k) 
			e=mid-1;
		else if(v[mid]<k) 
			s=mid+1;
	}
	return -1;
}

int main()
{
	int n=5;
	vector<int>v={5, 10, 30, 20, 40};
	cout<<Seach(n, v, 20);
}