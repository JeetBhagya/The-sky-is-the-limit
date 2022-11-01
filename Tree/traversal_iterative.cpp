#include<bits/stdc++.h>
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

void preorder(node* root)
{
	if(root==NULL) return;
	vector<int>ans;
	stack<node*>st;
	st.push(root);
	while(!st.empty())
	{
		node* temp=st.top();
		st.pop();
		ans.push_back(temp->data);
		if(temp->right!=NULL) st.push(temp->right);
		if(temp->left!=NULL) st.push(temp->left);
	}
	for(auto x: ans) cout<<x<<" ";
}

void inorder(node* root)
{
	// if(root==NULL) return;
	stack<node*>st;
	node* temp=root;
	vector<int>ans;
	while(true)
	{
		if(temp!=NULL)
		{
			st.push(temp);
			temp=temp->left;
		}
		else
		{
			if(st.empty()==true) break;
			temp=st.top();
			st.pop();
			ans.push_back(temp->data);
			temp=temp->right;
		}
	}
	for(auto x: ans) cout<<x<<" ";
}


void postorder(node* root)
{
	if(root==NULL) return;
	stack<node*>st1;
	stack<int>st2;
	st1.push(root);
	while(!st1.empty())
	{
		node* temp=st1.top();
		st1.pop();
		st2.push(temp->data);
		if(temp->left!=NULL) st1.push(temp->left);
		if(temp->right!=NULL) st1.push(temp->right);
	}
	while(!st2.empty())
	{
		cout<<st2.top()<<" ";
		st2.pop();
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
   	preorder(root);
   	cout<<endl;
   	inorder(root);
   	cout<<endl;
   	postorder(root);
}