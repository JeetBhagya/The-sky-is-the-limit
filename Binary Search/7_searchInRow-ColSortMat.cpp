#include <bits/stdc++.h>
using namespace std;

pair<int, int>Search(int n, int m, vector<vector<int>>&v, int k)
{
	int s=0, e=m-1;
	while(s<n and e>=0)
	{
		if(v[s][e]==k) return {s, e};
		else if(v[s][e]>k) e--;
		else s++;
	}
	return {-1, -1};
}

int main()
{
	int n=3, m=4;
	vector<vector<int>>v={{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
	auto ans=Search(n, m, v, 0);
	cout<<ans.first<<" "<<ans.second<<endl;
}