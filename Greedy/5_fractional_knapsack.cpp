#include <bits/stdc++.h>
using namespace std;


int fraction_knapsack(int n, vector<int>&val, vector<int>&wt, int weight)
{
	vector<vector<int>>mapping; //for mapping <val/wt, val, wt>
	for(int i=0; i<n; i++)
	{
		mapping.push_back({val[i]/wt[i], val[i], wt[i]});
	}
	sort(mapping.begin(), mapping.end(), greater<vector<int>>()); //sort the mapping vector a/c to val/wt decreasing order

	int i=0;
	int sum=0;
	while(weight>0)
	{
		if(weight>mapping[i][2]) //if weight se wt kom ho toh we can add directly the val
		{
			sum+=mapping[i][1];
		}
		else if(weight<mapping[i][2]) //if weight kom ho then wt then have to add (val/wt)*weight
		{
			sum+=mapping[i][0]*weight;
		}

		weight=weight- mapping[i][2]; //every time just weight koma k jao for next calculation
		i++;
	}
	return sum;
}


int main()
{
	// #ifndef ONLINE_JUDGE
 //        freopen("input.txt","r",stdin);
 //        freopen("output.txt","w",stdout);
 //    #endif
	vector<int>val={60, 100, 120};
	vector<int>wt={10, 20, 30};
   	cout<<fraction_knapsack(3, val, wt, 50);
}   