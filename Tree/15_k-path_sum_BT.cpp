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

void solve(node* root, int k, int& count, vector<int>&temp)
{
	if(root==NULL) return;
	
	temp.push_back(root->data);

	solve(root->left, k, count, temp);
	solve(root->right, k, count, temp);
	int sum=0;
	for(int i=temp.size()-1; i>=0; i--)
	{
		sum+=temp[i];
		if(sum==k) count++;
	}
	temp.pop_back();
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
   	root->left->left=new node(1);
   	root->left->right=new node(2);
   	root->right->left=new node(1);
   	root->right->right=new node(2);

   	int k=4, count=0;
   	vector<int>temp;
   	solve(root, k, count, temp);
   	cout<<count<<endl;
}   