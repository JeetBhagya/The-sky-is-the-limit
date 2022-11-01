#include<bits/stdc++.h>
using namespace std;

void topKFrequent(int n, vector<int>&v, int k)
{
	unordered_map<int, int>ump;
	for(auto x: v) ump[x]++;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	for(auto x: ump)
	{
		pq.push({x.second, x.first});
		if(pq.size()>k) pq.pop();
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
	int k=2;
	topKFrequent(n, v, k);
}