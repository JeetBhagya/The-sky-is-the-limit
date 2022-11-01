#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val)
    {
        data=val;
        left=right=NULL;
    }
};

void inorder(TreeNode* root, int &ans, int i, int k)
{
	if(root==NULL) return;
	if(k==root->data) 
	{
		ans=i;	
		return;
	}
	i++;
	inorder(root->left, ans, i, k);
	inorder(root->right, ans, i, k);
}

int sumOflevel(int k, TreeNode* root)
{
	queue<TreeNode*>q;
	q.push(root);
	int j=0;
	int ans=0;
	inorder(root, ans, 0, k);
	int sum=0;
	while(!q.empty())
	{
		int size=q.size();
		for(int i=0; i<size; i++)
		{
			TreeNode* topNode=q.front();
			q.pop();
			if(topNode->left) q.push(topNode->left);
			if(topNode->right) q.push(topNode->right);
			if(j==ans) sum+=topNode->data;
		}
		j++;
	}
	return sum;
}


int main()
{
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
	
    TreeNode* root=new TreeNode(2);
    root->left=new TreeNode(3);
    root->right=new TreeNode(6);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(7);
    root->right->left=new TreeNode(7);
    root->right->right=new TreeNode(4);
    root->right->left->right=new TreeNode(13);
	int ans=sumOflevel(4, root);
	cout<<ans;
	
}