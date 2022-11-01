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

node* parent_node(node* root, int target, map<node*, node*>&mp)
{
	node* ans=NULL;
	queue<node*>q;
	q.push(root);

	mp[root]=NULL;

	while(!q.empty())
	{
		node* top=q.front();
		q.pop();
		if(top->data==target)
		{
			ans=top;
		}
		if(top->left)
		{
			q.push(top->left);
			mp[top->left]=top;
		}
		if(top->right)
		{
			q.push(top->right);
			mp[top->right]=top;
		}
	}
	return ans;

}

int burningTime(node* targetNode, map<node*, node*>&mp)
{
	queue<node*>q;
	map<node*, bool>visited;
	q.push(targetNode);
	visited[targetNode]=true;

	int time=0;

	while(!q.empty())
	{
		int size=q.size();
		bool flag=false;
		for(int i=0; i<size; i++)
		{
			node* top=q.front();
			q.pop();

			if(top->left and !visited[top->left])
			{
				flag=true;
				q.push(top->left);
				visited[top->left]=true;
			}
			if(top->right and !visited[top->right])
			{
				flag=true;
				q.push(top->left);
				visited[top->left]=true;
			}
			if(mp[top] and !visited[mp[top]])
			{
				flag=true;
				q.push(mp[top]);
				visited[mp[top]]=true;
			}
		}
		if(flag) time++;
	}
	return time;
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

   	int target=2;
   	map<node*, node*>mp;
   	node* targetNode=parent_node(root, target, mp);
   	int ans=burningTime(targetNode, mp);
   	cout<<ans<<endl;
}