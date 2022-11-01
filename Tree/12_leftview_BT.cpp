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

//all first element from each row (left to right)
void leftVeiw(node* root, int lvl, vector<int>&ans)
{
	if(root==NULL) return;

	if(lvl==ans.size())
		ans.push_back(root->data);
	leftVeiw(root->left, lvl+1, ans);
	leftVeiw(root->right, lvl+1, ans); 
}

//all first element from each row (right to left)
void rightView(node* root, int lvl, vector<int>&ans)
{
	if(root==NULL) return;

	if(lvl==ans.size())
		ans.push_back(root->data);
	rightView(root->right, lvl+1, ans); 
	rightView(root->left, lvl+1, ans);
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
   	node* temp=root;

   	vector<int>ans;
   	leftVeiw(temp, 0, ans);
   	for(auto x: ans) cout<<x<<" ";

   	cout<<endl;
   	ans={};
   	rightView(temp, 0, ans);
   	for(auto x: ans) cout<<x<<" ";
   	
}   