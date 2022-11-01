#include <bits/stdc++.h>
using namespace std;



void kCloser(int n, vector<int>&v, int x, int k)
{
	priority_queue<pair<int, int>>pq;
	for(int i=0; i<n; i++)
	{
		pq.push({abs(x-v[i]), v[i]});
		if(pq.size()>k)
			pq.pop();
	}
	while(pq.size()>0) 
	{
		cout<<pq.top().second<<" ";
		pq.pop();
	}
}

int main()
{
	int n=5;
	vector<int>v={1, 2, 3, 5, 6};
	int x=3;
	int k=2;
	kCloser(n, v, x, k);
}