int height(TreeNode *root)
    {
        if(root == NULL)
            return 0;
        
        int leftH = height(root->left);
        int rightH = height(root->right);
        
        return 1 + max(leftH,rightH);
    }
