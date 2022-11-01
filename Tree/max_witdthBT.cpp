#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(int val)
    {
        data=val;
        left=right=NULL;
    }
};


int max_width(node* root)
{
    queue<pair<node*, int>>q;

    q.push({root, 0});
    int maxi=0;
    while(!q.empty())
    {
        int size=q.size();
        int mini=q.front().second;
        int s=0, e=0;
        for(int i=0; i<size; i++)
        {
            pair<node*, int>temp=q.front();
            q.pop();
            node* top=temp.first;
            int ind=temp.second-mini;

            if(i==0) s=ind;
            if(i==size-1) e=ind;
            if(top->left)
            {
                q.push({top->left, (long long)2*ind+1});
            }
            if(top->right)
            {
                q.push({top->right, (long long)2*ind+2});
            }
        }
        maxi=max(maxi, e-s+1);
    }
    return maxi;
}

int main()
{
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    node* root=new node(1);
   	root->left=new node(2);
   	root->right=new node(3);
   	root->left->left=new node(4);
   	root->left->right=new node(5);
   	root->right->left=new node(6);
   	root->right->right=new node(7);
    root->right->right->left=new node(8);
    cout<<max_width(root);
}