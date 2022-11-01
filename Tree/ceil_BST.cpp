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


//recent greater than  equal value 
bool ceil(node* root, int x, int& ans)
{
    if(root==NULL) return false;

    if(root->data>=x) ans=min(ans, root->data);

    if(root->data>=x)
    {
        return ceil(root->left, x, ans);
    }
    else return ceil(root->right, x, ans);
}

int solve(node* root, int x)
{
    if(root==NULL) return -1;
    int ans=INT_MAX;

    ceil(root, x, ans);
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

    cout<<solve(root, 7);
    
}