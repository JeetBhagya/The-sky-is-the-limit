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

bool search(node* root, int src)
{
    if(root==NULL) return false;
    if(root->data==src) return true;

    if(root->data>src)
    {
        return search(root->left, src);
    }
    return search(root->right, src);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    node* root=new node(10);
    root->left=new node(8);
    root->right=new node(15);
    root->left->left=new node(4);
    root->left->right=new node(9);
    root->right->left=new node(11);
    root->right->right=new node(17);
    root->right->left->right=new node(13);

    cout<<search(root, 18)<<endl;
    
}