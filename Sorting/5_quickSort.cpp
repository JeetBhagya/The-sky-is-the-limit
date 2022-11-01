#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&v, int s, int e)
{
	int pivot=v[s];
	int cnt=0;
	//counting how many elements are there greater than pivot
	for(int i=s+1; i<=e; i++)
	{
		if(pivot>=v[i]) cnt++;
	}

	//this is the partition(pivot index)
	int partInd=s+cnt;
	//put pivot in correct index
	swap(v[partInd], v[s]);

	//work for put lesser elemet than pivot in left of pivot , and put greater elements than pivot in right of pivot 
	int left=s, right=e;
	while(left<partInd and right>partInd)
	{
		while(v[left]<v[partInd]) left++; //if pivot is greater than left side element just go forward i.e. left++
		while(v[right]>v[partInd]) right--; //if pivot is lesser than right side element just go backward i.e. right--

		//now we are in that position, where fail all cases of uper 2 lines 
		if(left<partInd and right>partInd)
			swap(v[left++], v[right--]);
	}
	return partInd;
}

void quickSort(vector<int>&v, int s, int e)
{
	if(s>=e) return;

	//partitioning into two sections with placing the pivot in right position 
	int part=partition(v, s, e);

	//sorting left part
	quickSort(v, s, part-1);
	//sorting right part
	quickSort(v, part+1, e);
}

int main()
{
	int n=5;
	vector<int>v={1, 6, 3, 2, 4};
	quickSort(v, 0, 4);
	for(auto x: v) 
		cout<<x<<" ";

}