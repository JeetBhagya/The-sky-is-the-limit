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

node* LCA(node* root, node* p, node* q)
{
	if(root==NULL or root==p or root==q) return root;

	node* leftTree=LCA(root->left, p, q);
	node* rightTree=LCA(root->right, p, q);

	if(leftTree!=NULL and rightTree!=NULL) return root;
	if(leftTree!=NULL and rightTree==NULL) return leftTree;
	if(leftTree==NULL and rightTree!=NULL) return rightTree;
	if(leftTree==NULL and rightTree==NULL) return NULL;
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
   	root->left->right->right=new node(8);

   	node* p=root->left->left;
   	node* q=root->left;
   
   	node*ans=LCA(root, p, q);
   	cout<<ans->data;
}   