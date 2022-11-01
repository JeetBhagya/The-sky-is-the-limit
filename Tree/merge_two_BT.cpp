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


node* merge(node* root1, node* root2)
{
    if(root1==NULL) return root2;
    if(root2==NULL) return root1;

    root1->data+=root2->data;

    root1->left=merge(root1->left, root2->left);
    root1->right=merge(root1->right, root2->right);
    return root1;
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

    node* root1=new node(10);
    root1->left=new node(8);
    root1->right=new node(9);
    root1->left->left=new node(4);
    root1->left->right=new node(15);
    root1->right->left=new node(11);
    root1->right->right=new node(17);
    root1->right->left->left=new node(13);
    
    node* temp=merge(root, root1);
    print(temp);
}