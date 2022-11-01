class BSTIterator 
{
    stack<TreeNode*>st;
public:
    //storing elements in stack
    BSTIterator(TreeNode* root) 
    {
        pushAll(root);
    }
    
    /*return the cur next element
    step: 1)find top element from stack
             2) check right elemet if having then push in stack of all left elements of st.top()->right
             3) return topNode->val
    */
    void pushAll(node* root)
    {
        while(root!=NULL) 
        {
            st.push(root);
            root=root->left;
        }
    }


    int next() 
    {
        TreeNode* topNode=st.top();
        st.pop();
        TreeNode* temp=topNode->right;
        pushAll(temp);
        return topNode->val;
        
    }
    
    bool hasNext() 
    {
        return !st.empty();    
    }
};