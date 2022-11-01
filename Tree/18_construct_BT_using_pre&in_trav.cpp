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

// int position(int in[], int ele, int n)
// {
// 	for(int i=0; i<n; i++)
// 	{
// 		if(in[i]==ele) return i;
// 	}
// 	return -1;
// }
void position(int in[], map<int, int>&mp, int n)
{
	for(int i=0; i<n; i++) mp[in[i]]=i;
}

node* solve(int in[], int pre[], int& ind, int in_s, int in_e, int n, map<int, int>&mp)
{
	if(ind>=n or in_s>in_e) return NULL;

	int ele=pre[ind++];
	node* root=new node(ele);
	// int pos=position(in, ele, n);
	int pos=mp[ele];
	root->left=solve(in, pre, ind, in_s, pos-1, n, mp);
	root->right=solve(in, pre, ind, pos+1, in_e, n, mp);
	return root;
}

void postorder(node* root)
{
	if(root==NULL) return;
	postorder(root->left);
	// cout<<root->data<<" ";
	postorder(root->right);
	cout<<root->data<<" ";
}

int main()
{
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    int n=6;
    int in[6]={3, 1, 4, 0, 5, 2};
    int pre[6]={0, 1, 3, 4, 2, 5};
    int ind=0;
    map<int, int>mp;
    position(in, mp, n);
    node* ans=solve(in, pre, ind, 0, n-1, n, mp);
    postorder(ans);

}