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

void solve(node* root, int len, int sum, pair<int, int>&ans)
{
	if(root==NULL) return;
	sum+=root->data;
	if(root->left==NULL and root->right==NULL)
	{
		if(len>=ans.second)
		{
			ans={sum, len};
		}
		return;
	}
	solve(root->left, len+1, sum, ans);
	solve(root->right, len+1, sum, ans);
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

   	pair<int, int>ans;
   	solve(root, 0, 0, ans);
   	cout<<ans.first<<endl;
}   