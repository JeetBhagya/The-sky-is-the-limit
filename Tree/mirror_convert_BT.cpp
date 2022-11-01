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

node* preorder(node* root)
{
    if(root==NULL) return NULL ;

    swap(root->left, root->right);

    preorder(root->left);
    preorder(root->right);
    return root;
}

void print(node* root)
{
    if(root==NULL) return;

    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    node* root=new node(10);
    root->left=new node(8);
    root->right=new node(9);
    root->left->left=new node(4);
    root->left->right=new node(15);
    root->right->left=new node(11);
    root->right->right=new node(17);
    root->right->left->right=new node(13);

    
    node* res=preorder(root);

    print(res);
    
}