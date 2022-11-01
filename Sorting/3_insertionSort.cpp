#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>&v, int n)
{
	for(int i=1; i<n; i++)
	{
		int temp=v[i];
		int j=i-1;
		while(j>=0)
		{
			if(temp<v[j]) v[j+1]=v[j];
			else break;
			j--;
		}
		v[j+1]=temp;
	}
}

int main()
{
	int n=5;
	vector<int>v={1, 6, 3, 2, 4};
	
	//3 1 2
	//

	insertionSort(v, 5);
	for(auto x: v) 
		cout<<x<<" ";

}