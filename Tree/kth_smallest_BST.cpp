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


    void inorder(node* root, int& ans, int& k)
    {
        if(root==NULL) return;
        inorder(root->left, ans, k);
        if(k==0) ans=root->data;
        k--;
        inorder(root->right, ans, k);
    }
    int kthSmallest(node* root, int k) 
    {
        int ans;
        int i=k-1;
        inorder(root, ans, i);
        return ans;
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

    cout<<kthSmallest(root, 2);
    
}