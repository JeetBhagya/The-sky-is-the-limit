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


//using while loop
node* insert_bst(node* root, int x)
{
    if(root==NULL) return new node(x);
    node* temp=root;

    while(true)
    {
        if(temp->data<=x)
        {
            if(temp->right!=NULL) temp=temp->right;
            else
            {
                temp->right=new node(x);
                break;
            }
        }
        else
        {
            if(temp->left!=NULL) temp=temp->left;
            else
            {
                temp->left=new node(x);
                break;
            }
        }
    }
    return root;
}

//using recursion
void insert_bst(TreeNode* root, int x)
{
    if(root->left==NULL and root->val>x)
    {
        root->left=new TreeNode(x);
        return;
    }
    if(root->right==NULL and root->val<x)
    {
        root->right=new TreeNode(x);
        return;
    }

    if(root->val>x) insert_bst(root->left, x);
    if(root->val<x) insert_bst(root->right, x);
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
    
    node* root=new node(10);
    root->left=new node(8);
    root->right=new node(15);
    root->left->left=new node(4);
    root->left->right=new node(9);
    root->right->left=new node(11);
    root->right->right=new node(17);
    root->right->left->right=new node(13);

    node* ans=insert_bst(root, 5);
    preorder(ans);

}