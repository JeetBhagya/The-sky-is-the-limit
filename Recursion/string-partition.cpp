#include<bits/stdc++.h>
using namespace std;

bool pali(string s)
{
    for(int i=0; i<s.size()/2; i++)
    {
        if(s[i]!=s[s.size()-i-1]) return false;
    }
    return true;
}

//s.substr(from the pos, length to pos)

void solve(string s, int ind, vector<string>&temp)
{
    if(ind==s.size())
    {
        for(auto x: temp) cout<<x<<" ";
        cout<<endl;
        return;
    }
    for(int i=ind; i<s.size(); i++)
    {
        if(pali(s.substr(ind, i-ind+1)))
        {
            temp.push_back(s.substr(ind, i-ind+1));
            solve(s, i+1, temp);
            temp.pop_back();
        }
    }
}

int main()
{
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    string s="aabbc";
    vector<string>temp;
    solve(s, 0, temp);
}