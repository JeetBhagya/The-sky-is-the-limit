#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>&v, int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-i-1; j++)
		{
			if(v[j]>v[j+1]) 
				swap(v[j], v[j+1]);	
		}
	}
}

int main()
{
	int n=5;
	vector<int>v={1, 6, 3, 2, 4};
	bubbleSort(v, 5);
	for(auto x: v) 
		cout<<x<<" ";

}