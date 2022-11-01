#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>&v, int n)
{
	for(int i=0; i<n-1; i++)
	{
		int minInd=i;
		for(int j=i+1; j<n; j++)
		{
			if(v[j]<v[minInd]) minInd=j;
		}
		swap(v[minInd], v[i]);
	}
}

int main()
{
	int n=5;
	vector<int>v={1, 6, 3, 2, 4};
	selectionSort(v, 5);
	for(auto x: v) 
		cout<<x<<" ";

}