#include <bits/stdc++.h>
using namespace std;

int nextElement(int n, vector<char>&v, char c)
{
	int s=0, e=n-1;
	int ans=-1;
	while(s<=e)
	{
		int mid=s+(e-s)/2;
		if(v[mid]>c)
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
	vector<char>v={'a', 'e', 'f', 'h'};

	cout<<nextElement(n, v, 'c')<<endl;
}