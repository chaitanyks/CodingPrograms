TreeNode* lca(TreeNode* root, TreeNode* x,TreeNode* y)
    {
        if(root==NULL || root == x || root == y)
            return root;
        
        TreeNode* left = lca(root->left,x,y);
        TreeNode* right = lca(root->right,x,y);
        
        if(left!=NULL && right!=NULL)
            return root;
        
        if(left!=NULL)
            return left;
        else
            return right;
        
    }
