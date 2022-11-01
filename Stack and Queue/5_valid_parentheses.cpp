#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) 
{
    stack<int>st;
    if(s[0]==')' or s[0]=='}' or s[0]==']') return false;
    
    if(s[s.size()-1]=='(' or s[s.size()-1]=='{' or s[s.size()-1]=='[') return false;
    
    for(auto x: s)
    {
        if(x=='(' or x=='{' or x=='[')
            st.push(x);
        else
        {
            if(st.empty() or (st.top()=='(' and x!=')') or (st.top()=='{' and x!='}') or (st.top()=='[' and x!=']')) 
                return false;

            st.pop();
        }
    }
    return st.empty();
    
}

int main()
{
	// #ifndef ONLINE_JUDGE
 //        freopen("input.txt","r",stdin);
 //        freopen("output.txt","w",stdout);
 //    #endif
	string str="({()})";
	cout<<valid_parentheses(str);
	
}   