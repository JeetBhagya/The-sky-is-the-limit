#include<bits/stdc++.h>
using namespace std;


void merge(vector<int>&v, int s, int e)
{
	int mid=s+(e-s)/2;

	int ind1=s;
	int ind2=mid+1;

	//for storing sorting elements
	vector<int>ans;
	

	//same concept of merge two sorted array
	while(ind1<=mid and ind2<=e)
	{
		if(v[ind1]<=v[ind2]) 
			ans.push_back(v[ind1++]);
		else 
			ans.push_back(v[ind2++]);
	}
	//if ind1 still less than or equal mid
	while(ind1<=mid) 
		ans.push_back(v[ind1++]);

	//if ind2 still less than or equal e
	while(ind2<=e) 
		ans.push_back(v[ind2++]);

	//insert all element from ans to v
	for(int i=s; i<=e; i++)
	{
		v[i]=ans[i-s];
	}
}

void mergeSort(vector<int>&v, int s, int e)
{
	if(s>=e) return;

	int mid=s+(e-s)/2;

	//sort left part
	mergeSort(v, s, mid);

	//sort right part
	mergeSort(v, mid+1, e);

	//merge left and right with doing sorting
	merge(v, s, e);

}

int main()
{
	int n=5;
	vector<int>v={1, 6, 3, 2, 4};
	mergeSort(v, 0, 4);
	for(auto x: v) 
		cout<<x<<" ";

}