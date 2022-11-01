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

node* construct_bst(vector<int>&pre, int& i, int bound)
{
    //edge condition
    if(i==pre.size() or bound<pre[i]) return NULL;

    //make a node for the pre[i]
    node* root=new node(pre[i++]);

    //node of pre[i] left sub tree
    root->left=construct_bst(pre, i, root->data);
    //node of pre[i] right sub tree
    root->right=construct_bst(pre, i, bound);

    //return root
    return root;
}

void inorder(node* root)
{
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    vector<int>pre={3, 2, 1, 6, 5, 7, 8};
    int i=0, bound=INT_MAX;
    node* res=construct_bst(pre, i, bound);
    inorder(res);
}