#include<bits/stdc++.h>
using namespace std;

int singleElement(vector<int>&v)
{
	int s=0, e=v.size()-1;

	while(s<=e)
	{
		int mid=s+(e-s)/2;

		int num=(mid%2==0) ? mid+1 : mid-1;

		if(v[mid]==v[num]) s=mid+1;
		else e=mid-1;
	}
	return v[s];
}

int main()
{
	int n=5;
	vector<int>v={5, 10, 10, 30, 30};
	cout<<singleElement(v);
}