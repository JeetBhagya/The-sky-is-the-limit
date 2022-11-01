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

node* construct(vector<int>&post, int n, int& i, int min_bound, int max_bound)
{
    if(i<0 or post[i]<min_bound or post[i]>max_bound) return NULL;
    
    node* root=new node(post[i--]);
    root->right=construct(post, n, i, root->data, max_bound);
    root->left=construct(post, n, i,min_bound, root->data);
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
    
    vector<int>post={1, 2, 6, 5, 8, 7, 3};
    int i=6, min_bound=INT_MIN, max_bound=INT_MAX;
    node* res=construct(post, 7, i, min_bound, max_bound);
    inorder(res);
}