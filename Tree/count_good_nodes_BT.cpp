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

void preorder(node* root, int max, int& cnt)
{
    if(root==NULL) return ;

    if(root->data>=max)
    {
        cnt++;
        max=root->data;
    }
    preorder(root->left, max, cnt);
    preorder(root->right, max, cnt);
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

    int cnt=0;
    preorder(root, INT_MIN, cnt);
    cout<<cnt<<endl;
    
}