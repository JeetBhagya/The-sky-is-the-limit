#include <bits/stdc++.h>
using namespace std;


vector<int>nextGreater(vector<int>&arr)
{
    int n=arr.size();
    vector<int>nge(n);
    stack<int>st;
    for(int i=n-1; i>=0; i--)
    {
        while(!st.empty() and st.top()<=arr[i]) st.pop();

        if(st.empty()) nge[i]=-1;
        else nge[i]=st.top();
        st.push(arr[i]);
    }
    return nge;
}

//condition: circuler
vector<int>nextGreater1(vector<int>&arr)
{
    int n=arr.size();
    vector<int>nge(n);
    stack<int>st;
    for(int i=2*n; i>=0; i--)
    {
        while(!st.empty() and st.top()<=arr[i%n]) st.pop();
        if(i<n)
        {
            if(st.empty()) nge[i]=-1;
            else nge[i]=st.top();
        }
        st.push(arr[i%n]);
    }
    return nge;
}

int main()
{
	// #ifndef ONLINE_JUDGE
 //        freopen("input.txt","r",stdin);
 //        freopen("output.txt","w",stdout);
 //    #endif
	
	vector<int>arr={1, 5, 1, 4};
    for(auto x: nextGreater(arr)) cout<<x<<" ";
    cout<<endl;
    for(auto x: nextGreater1(arr)) cout<<x<<" ";
}   