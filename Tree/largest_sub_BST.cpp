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


vector<int> solve(node* root)
{
    if(root==NULL) return {1, 0, INT_MAX, INT_MIN};
           
    auto left=solve(root->left);
    auto right=solve(root->right);
        
    if(left[0] and right[0])
    {
        if(root->data > left[3] and root->data < right[2])
        {
            int x = min(left[2], root->data);
            int y = max(right[3], root->data);
                
            return {1, left[1]+right[1]+1, x, y};
        }
    }
    return {0, max(left[1], right[1]), 0, 0};
}
int largestBst(node *root)
{
    vector<int>res=solve(root);
    return res[1];
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

    cout<<largestBst(root);
    
    
}