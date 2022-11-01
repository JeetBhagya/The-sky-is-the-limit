#include <bits/stdc++.h>
using namespace std;

//compare function for sorted the vector by profit  =>{jobs[i][2]}
bool cmp(vector<int>a, vector<int>b)
{
	return a[2]>b[2];
}

int train_scheduling(int n, vector<vector<int>>&jobs, int k)
{
	vector<int>scheduling(k, -1);
	sort(jobs.begin(), jobs.end(), cmp); //sorted the vector by profit
	int sum=0;
	for(int i=0; i<k; i++)
	{
		int j=jobs[i][1];
		while(scheduling[j]!=-1 and j<-1) 
		{
			j--;
		}
		scheduling[j+1]=jobs[i][0];
		sum+=jobs[i][2];
	}
	return sum;
}


int main()
{
	// #ifndef ONLINE_JUDGE
 //        freopen("input.txt","r",stdin);
 //        freopen("output.txt","w",stdout);
 //    #endif
	vector<vector<int>>jobs={{1, 4, 20}, {2, 5, 60}, {3, 6, 70}, {4, 6, 65}, {5, 4, 25}, {6, 2, 80}, {7, 2, 10}, {8, 2, 22}};
	cout<<train_scheduling(8, jobs, 6);
   	
}   