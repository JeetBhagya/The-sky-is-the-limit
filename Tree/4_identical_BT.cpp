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



bool identical(node* p, node* q)
{
	if(p==NULL or q==NULL) return p==q;
	return (p->data==q->data and identical(p->left, q->left) and identical(p->right, q->right));
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
   	if(identical(root, temp)) cout<<"identical"<<endl;
   	else cout<<"not identical"<<endl;
   	
}   