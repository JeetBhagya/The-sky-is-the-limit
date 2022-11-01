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

int height(node* root, int& maxi)
{
	if(root==NULL) return 0;
	int lh=height(root->left, maxi);
	int rh=height(root->right, maxi);
	maxi=max(maxi, lh+rh);
	return 1+max(lh, rh);
}

int diameter(node* root)
{
	int maxi=INT_MIN;
	height(root, maxi);
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
   	node* temp=root;
   	cout<<diameter(temp);
}   