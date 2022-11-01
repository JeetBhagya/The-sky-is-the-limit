#include<bits/stdc++.h>
using namespace std;

int pivot(int n, vector<int>&v)
{
	int s=0, e=n-1;

	while(s<=e)
	{
		int mid=s+(e-s)/2;

		//doing this for sutkara milne k liye from boundary overloading
		int prev=(mid-1+v.size())%v.size();
		int next=(mid+1)%v.size();

		if(v[mid]>=v[prev] and v[mid]>=v[next]) 
			return mid;
		else if(v[mid]>=v[s]) 
			s=mid+1;
		else if(v[mid]<=v[e]) 
			e=mid-1;
	}
	return -1;
}

int main()
{
	int n=2;
	vector<int>v={1, 4};
	cout<<pivot(n, v)<<endl;
	cout<<"No of rotation is: "<<n-1-pivot(n, v)<<endl;
}