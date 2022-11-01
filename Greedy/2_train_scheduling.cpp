#include <bits/stdc++.h>
using namespace std;

int train_scheduling(int n, vector<int>&arrival, vector<int>&deprature)
{
	sort(arrival.begin(), arrival.end());
	sort(deprature.begin(), deprature.end());
	int i=1, j=0;
	int cnt=1;
	int ans=INT_MIN;
	while(i<n and j<n)
	{
		if(arrival[i]<=deprature[j]) //if arival time is smallaer than the previous train deptrature time, we need one more station to stop the train
		{
			cnt++;
			i++;
		}
		else if(arrival[i]>deprature[j]) //other wise
		{
			cnt--;
			j++;
		}
		if(cnt>ans) ans=cnt;
	}
	return ans;
}


int main()
{
	// #ifndef ONLINE_JUDGE
 //        freopen("input.txt","r",stdin);
 //        freopen("output.txt","w",stdout);
 //    #endif
	vector<int>arrival={900, 940, 950, 1100, 1500, 1800};
	vector<int>deprature={910, 1200, 1120, 1130, 1900, 2000};
	cout<<train_scheduling(6, arrival, deprature);
   	
}   