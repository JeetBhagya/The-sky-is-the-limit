#include<bits/stdc++.h>
using namespace std;

int connectRopes(int n, vector<int>&v)
{
	priority_queue<int>pq;

	for(int i=0; i<n; i++) pq.push(v[i]);

	while(pq.size()>1)
	{
		int a=pq.top(); pq.pop();
		int b=pq.top(); pq.pop();

		pq.push(a+b);
	}
	return pq.top();
}

int main()
{
	int n=5;
	vector<int>v={1, 2, 3, 4, 5};
	cout<<connectRopes(n, v)<<endl;
}