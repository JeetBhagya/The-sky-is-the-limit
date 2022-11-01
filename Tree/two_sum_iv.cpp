class BSTIterator 
{
    stack<TreeNode*>st;
    bool reverse=true;
public:
    //storing elements in stack
    BSTIterator(TreeNode* root, bool isReverse) 
    {
        reverse=isReverse;
        pushAll(root);
    }
    
    /*return the cur next element
    step: 1)find top element from stack
             2) check right elemet if having then push in stack of all left elements of st.top()->right
             3) return topNode->val
    */
    int next() 
    {
        TreeNode* topNode=st.top();
        st.pop();
        
        if(!reverse) pushAll(root->right);
        else pushAll(root->left);
        return topNode->val;
        
    }
    
    bool hasNext() 
    {
        return !st.empty();    
    }

    void pushAll(node* root)
    {
        while(root!=NULL) 
        {
            st.push(root);
            if(reverse=true) root=root->right;
            else root=root->left;
        }

    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k)
    {
        if(root==NULL) return false;
        BSTIterator left(root, false);
        BSTIterator right(root, true);
        int start=left.next();
        int end=right.next();
        while(start<end)
        {
            if(start+end==k) return true;
            else if(start+end<k) start=left.next();
            else end=right.next();
        }
        return false;
    }
};