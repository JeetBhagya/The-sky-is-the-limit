#include <bits/stdc++.h>
using namespace std;

int midDiffEle(int n, vector<int>&v, int k)
{
	int s=0, e=n-1;
	while(s<=e)
	{
		int mid=s+(e-s)/2;
		if(v[mid]==k) return mid;
		else if(v[mid]>k) e=mid-1;
		else if(v[mid]<k) s=mid+1;
	}
	return s;
}

int main()
{
	int n=6;
	vector<int>v={3, 5, 8, 9, 10, 11};
	int k=12;
	int ind=midDiffEle(n, v, k);
	
	if(abs(v[ind]-k)<=abs(v[ind-1]-k)) cout<< ind;
	else cout<<ind-1;
	
}