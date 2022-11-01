#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& v, int k) 
{
    int s=0, e=v.size()-1;
    
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        
        if(v[mid]==k) return mid;
        
        if(v[s]<=v[mid])
        {
            if(v[s]<=k and v[mid]>=k) 
                e=mid-1;
            else s=mid+1;
        }
        else
        {
            if(v[mid]<k and v[e]>=k) 
                s=mid+1;
            else e=mid-1;
        }
    }
    return -1;
}
 
int main()
{
	int n=8;
	vector<int>v={4, 5, 6, 6, 7, 1, 2, 3};
	
}