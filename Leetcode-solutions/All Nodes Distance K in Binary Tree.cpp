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
    void genParents(TreeNode* root, TreeNode* par, unordered_map<TreeNode*, TreeNode*>& parent)
    {
        if(!root)
            return;
        parent.insert({root,par});
        genParents(root->left, root, parent);
        genParents(root->right, root, parent);
    }
    
    bool visited(unordered_set<TreeNode*>& vis, TreeNode* node)
    {
        return vis.find(node)!=vis.end();
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(k==0)
            ans.push_back(target->val);
        else
        {
            int dist=0;
            unordered_map<TreeNode*, TreeNode*> parent;
            unordered_set<TreeNode*> vis;
            queue<TreeNode*> pendingNodes;
            genParents(root, nullptr, parent);
            pendingNodes.push(target);
            vis.insert(target);
            while(!pendingNodes.empty())
            {
                int size=pendingNodes.size();
                for(int i=0;i<size;i++)
                {
                    TreeNode* curNode=pendingNodes.front();
                    pendingNodes.pop();
                    if(parent[curNode] && !visited(vis, parent[curNode]))
                    {
                        pendingNodes.push(parent[curNode]);
                        vis.insert(parent[curNode]);
                    }
                    if(curNode->left && !visited(vis, curNode->left))
                    {
                        pendingNodes.push(curNode->left);
                        vis.insert(curNode->left);
                    }
                    if(curNode->right && !visited(vis, curNode->right))
                    {
                        pendingNodes.push(curNode->right);
                        vis.insert(curNode->right);
                    }
                }
                if(++dist==k)
                {
                    while(!pendingNodes.empty())
                    {
                        ans.push_back(pendingNodes.front()->val);
                        pendingNodes.pop();
                    }
                    break;
                }
            }
        }
        return ans;
    }
};
