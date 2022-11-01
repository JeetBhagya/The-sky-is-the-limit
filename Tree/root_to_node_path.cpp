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


bool solve(node* root, node* final, vector<int>&ans)
{
	if(root==NULL) return false;
	ans.push_back(root->data);
	cout<<root->data<<endl;
	if(root->data==final->data) return true;

	bool x=solve(root->left, final, ans);
	bool y=solve(root->right, final, ans);
	if(x==true or y==true) return true;
	else {

	ans.pop_back();
		return false;}
	// return false;
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
   	node* final=root->left->right;
   	node* temp=root;
   	vector<int>ans;
   	solve(root, final, ans);
   	for(auto x: ans) cout<<x<<" ";
   	
}   