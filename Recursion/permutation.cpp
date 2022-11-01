#include<bits/stdc++.h>
using namespace std;


// isOk vector tu lagibo, nhole ami keneke gom pam j agote ami heitu value use korisu buli
void solve1(int n, vector<int>&v, vector<int>&temp, vector<bool>&isOk)
{
    if(temp.size()==n)
    {
        for(auto x: temp) cout<<x<<" ";
        cout<<endl;
        return;
    }
    for(int i=0; i<n; i++)
    {
        if(i>0 and v[i]==v[i-1] and !isOk[i-1]) continue; //condition for duplicate value
        if(!isOk[i])
        {
            temp.push_back(v[i]);
            isOk[i]=true;
            solve1(n, v, temp, isOk);
            isOk[i]=false;
            temp.pop_back();
        }
    }
}


//using swap
void solve2(int n, vector<int>&v, int ind)
{
    if(ind==n)
    {
        for(auto x: v) cout<<x<<" ";
        cout<<endl;
        return;
    }
    for(int i=ind; i<n; i++)
    {
        if(i>ind and v[i]==v[i-1]) continue; //condition for duplicate value
        swap(v[i], v[ind]);
        solve2(n, v, ind+1);
        swap(v[i], v[ind]);
    }
}

int main()
{
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n=4;
    vector<int>v{2, 2, 3, 3};
    vector<int>temp; vector<bool>isOk(n, false);
    // solve1(n, v, temp, isOk);
    solve2(n, v, 0);
}