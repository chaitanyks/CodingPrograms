int depth(TreeNode * root, int x)
    {
        if(root == NULL )
            return 0;
        
        if(root->val == x)
            return 1;
        
        int left = depth(root->left,x);
        if(left>0)
            return 1+left;
        
        int right = depth(root->right,x);
        if(right>0)
            return 1+right;
        return -1;
    }
