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

//left nodes: pre order traversal with some condition
void leftVeiw(node* root , vector<int>&ans)
{
   if(root==NULL) return;
   if(root->left==NULL and root->right==NULL) return;
   ans.push_back(root->data);  
   leftVeiw(root->left, ans);  
   if(root->left==NULL )
   {
       leftVeiw(root->right, ans);
   }
}

//leaf nodes: pre order traversal with some condition
void leafNodes(node* root , vector<int>&ans)
{
   if(root==NULL) return;
   if(root->left==NULL and root->right==NULL)
   {
       ans.push_back(root->data);  
       return;  
   }
   leafNodes(root->left, ans);  
   leafNodes(root->right, ans); 
}

//right nodes: post order traversal(but right-left-root) with some condition
void rightVeiw(node* root, vector<int>&ans)
{
   if(root==NULL) return;
   if(root->right==NULL and root->left==NULL) return;

   rightVeiw(root->right, ans);  
   if(root->right==NULL) rightVeiw(root->left, ans);
   ans.push_back(root->data) ;
}

vector<int> traverseBoundary(node* root)
{
   vector<int> ans;  
   if(!root) return ans;
   ans.push_back(root->data);  
   if(root->left) leftVeiw(root->left, ans);
   leafNodes(root, ans);
   if(root->right) rightVeiw(root->right, ans);
   return ans;  
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
   	
   	auto ans=traverseBoundary(root);
   	for(auto x: ans) cout<<x<<" ";
}   