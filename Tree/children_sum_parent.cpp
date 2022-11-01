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

//return true or false if parent =left child + right child
bool children(node* root)
{
    if(root==NULL) return 1;
    if(root->left==NULL and root->right==NULL) return 1;

    int left=(root->left)? (root->left->data) : 0;
    int right=(root->right)? (root->right->data) : 0;

    if(left+right!=root->data) return 0;
    return children(root->left) and children(root->right);
}

//modification of tree with parent =left child + right child
void modification(node* root)
{
    if(root==NULL) return;

    int child_sum=0;
    if(root->left) child_sum+=root->left->data;
    if(root->right) child_sum+=root->right->data;

    if(child_sum>root->data) root->data=child_sum;
    else
    {
        if(root->left) root->left->data=root->data;
        if(root->right) root->right->data=root->data;
    }

    modification(root->left);
    modification(root->right);

    int merge_tot=0;

    if(root->left) merge_tot+=root->left->data;
    if(root->right) merge_tot+=root->right->data;
    
    if(root->left or root->right) root->data=merge_tot;
}

void preorder(node* root)
{
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
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
    // root->right->right->left=new node(8);
    
    modification(root);
    preorder(root);
}