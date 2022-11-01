
//this one almost same as burning tree solution

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

void parent_node(node* root, map<node*, node*>&mp)
{
    if(root==NULL) return;
    queue<node*>q;
    q.push(root);

    mp[root]=NULL;

    while(!q.empty())
    {
        node* top=q.front();
        q.pop();
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
}

vector<int>solve(node* targetNode, int k, map<node*, node*>&mp)
{
    vector<int>ans;
    queue<node*>q;
    q.push(targetNode);
    map<node*, bool>visited;
    visited[targetNode]=true;
    int n=0;
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
                if(n==k) ans.push_back(top->left->data);
            }
            if(top->right and !visited[top->right])
            {
                flag=true;
                q.push(top->right);
                visited[top->right]=true;
                if(n==k) ans.push_back(top->right->data);
            }
            if(mp[top] and !visited[mp[top]])
            {
                flag=true;
                q.push(mp[top]);
                visited[mp[top]]=true;
                if(n==k) ans.push_back(mp[top]->data);
            }
        }
        if(flag) n++;
    }
    return ans;
}

vector<int> distanceK(node* root, node* target, int k) 
{
    if(k==0) return {target->data};
    map<node*, node*>mp;
    parent_node(root, mp);
    auto ans=solve(target, k-1, mp);
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
    root->right->right->right=new node(8);

    node* targetNode=root->right;
    int k=2;
    auto ans=distanceK(root, targetNode, k);
    for(auto x: ans) cout<<x<<" ";
}