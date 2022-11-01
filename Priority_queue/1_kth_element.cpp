#include<bits/stdc++.h>
using namespace std;

//use max heap(only int) for smallest, closser etc
int kthSmallest(int n, vector<int>&v, int k)
{
	priority_queue<int>pq;
	for(int i=0; i<n; i++)
	{
		pq.push(v[i]);
		if(pq.size()>k)
		{
			pq.pop();
		}
	}
	return pq.top();
}

//use max heap(only int) for largest, top etc
int kthlargest(int n, vector<int>&v, int k)
{
	priority_queue<int, vector<int>, greater<int>>pq;
	for(int i=0; i<n; i++)
	{
		pq.push(v[i]);
		if(pq.size()>k)
		{
			pq.pop();
		}
	}
	return pq.top();
}

int main()
{
	int n=5;
	vector<int>v={1, 4, 5, 7, 2};
	int k=2;
	cout<<kthSmallest(n, v, k)<<endl;
	cout<<kthlargest(n, v, k)<<endl;
}