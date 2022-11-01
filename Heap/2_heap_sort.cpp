#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>&v, int n, int i)
{
	if(i>=n) return;

	int large=i;
	int left=2*i+1;
	int right=2*i+2;

	if(left<n and v[left]>v[large]) large=left;
	if(right<n and v[right]>v[large]) large=right;

	if(large!=i)
	{
		swap(v[large], v[i]);
		heapify(v, n, large);
	}
}

void buildHeap(vector<int>&v, int n)
{
	int i=(n-2)/2;
	while(i>=0)
	{
		heapify(v, n, i);
		i--;
	}
}

//approach
//step 1:make the random vector to a heap vector
//step 2: swap first and last element
// and repeat same condition untill 0 index

void heapSort(vector<int>&v, int n)
{
	buildHeap(v, n);
	for(int i=n-1; i>0; i--)
	{
		swap(v[0], v[i]);
		heapify(v, i, 0);
	}
}

int main()
{
	vector<int>v={3, 1, 4, 5, 6};
	heapSort(v, 5);
	for(auto x: v) cout<<x<<" ";
}

