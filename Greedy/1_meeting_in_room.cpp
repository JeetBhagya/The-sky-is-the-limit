#include <bits/stdc++.h>
using namespace std;

void meeting(int n, vector<int>start, vector<int>end)
{
	//for mapping <end, start, ind>
	vector<vector<int>>mapping;
	for(int i=0; i<n; i++)
	{
		mapping.push_back({end[i], start[i], i});
	}
	//sort the mapping by end value
	sort(mapping.begin(), mapping.end());

	vector<int>ans;
	int ending=INT_MIN;
	for(auto x: mapping)
	{
		if(ending<x[1]) //if ending<start then can take the index and update ending=start
		{
			ans.push_back(x[2]);
			ending=x[0];
		}
	}
	for(auto x: ans)
	{
		cout<<x<<" ";
	}
}


int main()
{
	// #ifndef ONLINE_JUDGE
 //        freopen("input.txt","r",stdin);
 //        freopen("output.txt","w",stdout);
 //    #endif
	vector<int>start={1, 0, 3, 8, 5, 8};
	vector<int>end={2, 6, 4, 9, 7, 9};
	meeting(6, start, end);
   	
}   