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

//preorder
void moris_traversal_preorder(node *root)
{
    node* cur=root;
        // Node* prev=NULL;
    while(cur)
    {
        if(cur->left)
        {
            node* prev=cur->left;
            while(prev->right)
            {
                prev=prev->right;
            }
            prev->right=cur->right;
            cur->right=cur->left;
        }
        cur->left=NULL;
        cout<<cur->data<<" "; 
        cur=cur->right;
    }
}
//inorder
void moris_traversal_inorder(node* root)
{
    if (root==NULL) return;
 
    node *cur=root, *pre;
    while(cur!=NULL) 
    {
        if(cur->left==NULL) 
        {
            cout<<cur->data<< " ";
            cur=cur->right;
        }
        else 
        {
            node *pre=cur->left;
            while(pre->right!=NULL && pre->right!=cur) pre = pre->right;

            if(pre->right==NULL) 
            {
                pre->right=cur;
                cur=cur->left;
            }
            else 
            {
                pre->right=NULL;
                cout<<cur->data<<" ";
                cur=cur->right;
            } 
        }
    } 
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

   	moris_traversal_preorder(root);
}