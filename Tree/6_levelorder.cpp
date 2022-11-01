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


void levelorder(node* root)
{
	if(root==NULL) return;
	vector<vector<int>>ans;
	queue<node*>q;
	q.push(root);
	while(!q.empty())
	{
		int size=q.size();
		vector<int>level;
		for(int i=0; i<size; i++)
		{
			node* temp=q.front();
			q.pop();
			if(temp->left!=NULL) q.push(temp->left);
			if(temp->right!=NULL) q.push(temp->right);
			level.push_back(temp->data);
		}
		ans.push_back(level);
	}
	for(auto x: ans)
	{
		for(auto y: x) cout<<y<<" ";
		cout<<endl;
	}
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
   	levelorder(root);
}   