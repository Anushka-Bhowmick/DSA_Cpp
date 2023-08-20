/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca=nullptr;
        TreeNode* cur=root;
        while(cur) {
            if(cur->val>p->val && cur->val>q->val) {
                cur=cur->left;
            } else if(cur->val<p->val && cur->val<q->val) {
                cur=cur->right;
            } else {
                lca=cur;
                break;
            }
        }
        return lca;
    }
};
