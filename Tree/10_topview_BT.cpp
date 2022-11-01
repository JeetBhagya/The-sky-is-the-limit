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


void bfs(node*A, int pos, map<int, int>&mp)
{
    if(A==NULL) return;
    queue<pair<node*,int>>q;
    q.push({A, pos});
    while(!q.empty())
    {
        pair<node*, int>front=q.front(); q.pop();
        
        if(mp.find(front.second)==mp.end())
        	mp[front.second]=front.first->data;
        if(front.first->left!=NULL) 
            q.push({front.first->left, front.second-1});
        if(front.first->right!=NULL)  
            q.push({front.first->right, front.second+1});
    }
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
   	
   	map<int, int>mp;
   	bfs(root, 0, mp);
   	for(auto x: mp) cout<<x.second<<" ";
}   