class Solution {
public:
    
    void dfs(TreeNode* root, int val, int depth)
    {
        if(depth==2)
        {
            TreeNode* nodeOne=new TreeNode(val);
            TreeNode* nodeTwo=new TreeNode(val);
            TreeNode* leftAdd=root->left;
            TreeNode* rightAdd=root->right;
            root->left=nodeOne;
            root->right=nodeTwo;
            nodeOne->left=leftAdd;
            nodeTwo->right=rightAdd;
        }
        if(root->left)
            dfs(root->left,val,depth-1);
        if(root->right)
            dfs(root->right,val,depth-1);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode* node=new TreeNode(val);
            node->left=root;
            return node;
        }
        dfs(root,val,depth);
        return root;
    }
};
