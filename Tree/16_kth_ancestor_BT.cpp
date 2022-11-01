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


// bool solve(node* root, int k, int node, vector<int>&temp)
// {
//     if(root==NULL) return false;
//     // temp.push_back(root->data);
//     if(root->data==node)
//     {
//         temp.push_back(node);
//         return true;
//     }
//     bool x=solve(root->left, k, node, temp);
//     bool y;
//     if(x==false)
//         y=solve(root->right, k, node, temp);
//     temp.push_back(root->data);
//     if(x==false and y==false) 
//     {
//         temp.pop_back();
//         return false;
//     }
//     if(x==true or y==true) return true;
// }
bool solve(node* root, int& k, int node, int& ans)
{
    if(root==NULL) return false;
    if(root->data==node) return true;

    bool x=solve(root->left, k, node, ans);
    bool y;
    if(x==false) y=solve(root->right, k, node, ans);

    if(x==false and y==false) return false;
    if(x==true or y==true) 
    {
        k--;
        if(k==0) ans=root->data;
        return true;
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
    root->left->right->right=new node(8);
    int k=3, node=6;
    // vector<int>temp;
    int ans=-1;
    solve(root, k, node, ans);
    cout<<ans;
    // for(auto x: temp) cout<<x<<" ";
    // if(k>temp.size()-1) cout<<-1<<endl;
    // else cout<<temp[temp.size()-1-k]<<endl;
} 