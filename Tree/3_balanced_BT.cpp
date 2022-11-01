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

//balanced BT: (height of left sub tree-height of right sub tree<=1)

int isbalanced(node* root)
{
	if(root==NULL) return 0;
	int lh=isbalanced(root->left);
	int rh=isbalanced(root->right);
	if(lh==-1 or rh==-1) return -1;
	if(abs(lh-rh)>1) return -1;
	return 1+max(lh, rh);
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
   	root->left->left=new node(4);
   	root->left->right=new node(5);
   	root->right->left=new node(6);
   	root->right->right=new node(7);
   	node* temp=root;
   	int ans=isbalanced(temp);
   	if(ans==-1) cout<<"not balanced"<<endl;
   	else cout<<"balanced"<<endl;
}   