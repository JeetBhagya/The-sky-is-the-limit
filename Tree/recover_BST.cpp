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


    
void inorder(node* root, node* &prev, node* &first, node* &second) 
{
    if(root==NULL) return;
    inorder(root->left, prev, first, second);
    
    if(prev!=NULL && root->data<prev->data)
    {
        if(first==NULL)
            first=prev;
        second=root;
    }
    prev=root;
        
    inorder(root->right, prev, first, second);
}

void recoverTree(node* root) 
{
    node* cur=root;
    node *prev=NULL, *first=NULL, *second=NULL;
    inorder(cur, prev, first, second);
    swap(first->data, second->data);
}

void print(node* root)
{
    if(root==NULL) return;

    print(root->left);
    cout<<root->data<<" ";
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

    print(root);
    cout<<endl;
    recoverTree(root);
    print(root);
}