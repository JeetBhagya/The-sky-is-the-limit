#include<bits/stdc++.h>
using namespace std;

int bs(vector<int>&v, int src)
{
	int s=0, e=v.size()-1;

	while(s<=e)
	{
		int mid=s+(e-s)/2;

		if(v[mid]==src) return mid;
		else if(v[mid]>src) e=mid-1;
		else s=mid+1;
	}
	return -1;
}

int minElement(int n, int m, vector<vector<int>>&v)
{
	for(int i=0; i<m; i++)
	{
		int src=v[0][i];
		bool flag=false;
		for(int i=1; i<n; i++)
		{
			int posAns=bs(v[i], src);
			if(posAns==-1) flag=true;
		}
		if(flag==false) return src;
	}
	return -1;
}

int main()
{
	int n=3;
	int m=4;
	vector<vector<int>>v={
							{1, 2, 3, 4},
							{2, 4, 5, 8},
							{3, 4, 7, 9},
						};

	cout<<minElement(n, m, v)<<endl;

}