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

vector<vector<int>> zigzagLevelOrder(node* root) 
{
    vector<vector<int>>ans;
    if(root==NULL) return ans;
    queue<node*>q;
    q.push(root);
    bool leftToRight=true;
        
    while(!q.empty())
    {
        int size=q.size();
        vector<int>row(size);
        for(int i=0; i<size; i++)
        {
            node* temp=q.front();
            q.pop();
            int ind=(leftToRight)?i:(size-1-i); //push it first index or last index
            row[ind]=temp->data;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        ans.push_back(row);
        leftToRight=(!leftToRight);
    }
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
   	
   	auto ans=zigzagLevelOrder(root);
   	for(auto x: ans)
   	{
   		for(auto y: x) cout<<y<<" ";
   		cout<<endl;
   	}
}   