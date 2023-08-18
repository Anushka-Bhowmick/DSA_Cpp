/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class BSTIterator {
private:
    bool reverse;
    stack<TreeNode*> order;
public:
    BSTIterator(TreeNode* root,bool reverse) {
        this->reverse=reverse;
        TreeNode* running=root;
        while(running) {
            order.push(running);
            running=reverse?running->right:running->left;
        }
    }
    
    TreeNode* next() {
        TreeNode* cur=order.top();
        order.pop();
        TreeNode* running=reverse?cur->left:cur->right;
        while(running) {
            order.push(running);
            running=reverse?running->right:running->left;
        }
        return cur;
    }
    
    bool hasNext() {
        return !order.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        bool isPresent=false;

        BSTIterator* forward=new BSTIterator(root,false);
        BSTIterator* backward=new BSTIterator(root,true);

        TreeNode* i=forward->next();
        TreeNode* j=backward->next();

        while(i!=j) {
            if(i->val+j->val==k) {
                isPresent=true;
                break;
            } else if(i->val+j->val<k) {
                i=forward->next();
            } else {
                j=backward->next();
            }
        }

        return isPresent;
    }
};
