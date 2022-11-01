#include<bits/stdc++.h>
using namespace std;

void frequencySort(int n, vector<int>&v)
{
	unordered_map<int, int>ump;
	for(auto x: v) ump[x]++;
	priority_queue<pair<int, int>>pq;
	for(auto x: ump)
	{
		pq.push({x.second, x.first});
	}
	while(pq.size()>0)
	{
		cout<<pq.top().second<<" ";
		pq.pop();
	}
}

int main()
{
	int n=8;
	vector<int>v={1, 2, 1, 2, 2, 1, 1, 3};
	frequencySort(n, v);
}