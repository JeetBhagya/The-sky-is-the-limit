#include<bits/stdc++.h>
using namespace std;

void kClosestPoints(int n, vector<pair<int, int>>&v, int k)
{
	priority_queue<pair<int, pair<int, int>>>pq;
	for(auto x: v)
	{
		int dis=(x.first*x.first + x.second*x.second);
		pq.push({dis, {x.first, x.second}});
		if(pq.size()>k)
			pq.pop();
	}
	while(pq.size()>0)
	{
		auto x=pq.top();
		cout<<"point is: ("<<x.second.first<<", "<<x.second.second<<") and dist: "<<x.first<<endl;
		pq.pop();
	}
	
}

int main()
{
	int n=4;
	vector<pair<int, int>>v={{1, 1}, {1, 0}, {-1, -1}, {1, 2}};
	kClosestPoints(n, v, 2);
}