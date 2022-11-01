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

pair<int, int> maxsum(node* root)
{
	if(root==NULL) return {0, 0};

	pair<int, int>x=maxsum(root->left);
	pair<int, int>y=maxsum(root->right);

	int left1=x.first, left2=x.second;
	int right1=y.first, right2=y.second;

	int take=root->data+left2+right2
	int notTake=max(left1, left2)+max(right1, right2);
	pair<int, int>res={take, notTake};
	return res;
}

int main()
{
	// #ifndef ONLINE_JUDGE
 //        freopen("input.txt","r",stdin);
 //        freopen("output.txt","w",stdout);
 //    #endif
   	
   	node* root=new node(1);
   	root->left=new node(2);
   	root->right=new node(3);
   	root->left->left=new node(2);
   	root->left->right=new node(4);
   	root->right->left=new node(5);
   	// root->right->right=new node(2);

   	pair<int, int>ans=maxsum(root);
   	cout<<max(ans.first, ans.second);
}   

///this problem is same as house robber-iii