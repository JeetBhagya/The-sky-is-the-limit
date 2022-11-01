#include <bits/stdc++.h>
using namespace std;

void minimum_coins(vector<int>coins, int money) //coins should be in from of decreasing order
{
	int cnt=0;
	int i=0;
	vector<int>ans;
	while(money)
	{
		if(coins[i]<=money)
		{
			money=money-coins[i];
			if(money<coins[i])
				cnt++;
			ans.push_back(coins[i]);
		}
		else i++;
	}
	for(auto x: ans) cout<<x<<" ";
	cout<<endl;
	cout<<cnt;
}

int main()
{
	// #ifndef ONLINE_JUDGE
 //        freopen("input.txt","r",stdin);
 //        freopen("output.txt","w",stdout);
 //    #endif
	vector<int>coins={100, 50, 20, 10, 5, 2, 1};
	minimum_coins(coins, 300);

   	
}   