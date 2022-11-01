#include<bits/stdc++.h>
using namespace std;


void sortKSort(int n, vector<int>&v, int k)
{
	priority_queue<int, vector<int>, greater<int>>pq;
	int j=0;
	for(int i=0; i<n; i++)
	{
		pq.push(v[i]);
		if(pq.size()>k)
		{
			v[j++]=pq.top();
			pq.pop();
		}
	}
	
	while(!pq.empty())
	{
		v[j++]=pq.top();
		pq.pop();
	}
}
int main()
{
	int n=6;
	vector<int>v={1, 2, 3, 6, 8, 0};
	int k=3;

	sortKSort(n, v, k);
	for(auto x: v) cout<<x<<" ";
}