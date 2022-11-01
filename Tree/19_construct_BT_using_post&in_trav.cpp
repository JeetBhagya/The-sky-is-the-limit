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


int position(int in[], int n, int ele)
{
	for(int i=0; i<n; i++)
	{
		if(in[i]==ele) return i;
	}
	return -1;
}

node* solve(int in[], int post[], int n, int& ind, int in_s, int in_e)
{
	if(ind<0 or in_s>in_e) return NULL;

	int ele=post[ind--];
	node* root=new node(ele);

	int pos=position(in, n, ele);

	root->right=solve(in, post, n, ind, pos+1, in_e);
	root->left=solve(in, post, n, ind, in_s, pos-1);
	return root;
}


void inorder(node* root)
{
	if(root==NULL) return;
	cout<<root->data<<" ";
	inorder(root->left);
	inorder(root->right);
}

int main()
{
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    int n=6;
    int in[6]={3, 1, 4, 0, 5, 2};
    int post[6]={0, 1, 3, 4, 2, 5};
    int ind=5;
    // map<int, int>mp;
    // position(in, mp, n);
    node* ans=solve(in, post, n, ind, 0, n-1);
    inorder(ans);

}