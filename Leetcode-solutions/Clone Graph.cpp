/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> nodeMap;
    void dfs(Node* node,vector<bool>& vis) {
        vis[node->val]=true;
        if(nodeMap.find(node)==nodeMap.end()) {
            nodeMap[node]=new Node(node->val);
        }

        for(int i=0;i<node->neighbors.size();i++) {
            if(nodeMap.find(node->neighbors.at(i))==nodeMap.end()) {
                nodeMap[node->neighbors.at(i)]=new Node(node->neighbors.at(i)->val);
            }
            nodeMap[node]->neighbors.push_back(nodeMap[node->neighbors.at(i)]);
        }

        for(int i=0;i<node->neighbors.size();i++) {
            if(!vis[node->neighbors.at(i)->val]) {
                dfs(node->neighbors.at(i), vis);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if(node==nullptr) {
            return nullptr;
        }
        if(node->neighbors.size()==0) {
            return new Node(node->val);
        }
        vector<bool> vis(101,false);
        dfs(node,vis);
        return nodeMap[node];
    }
};
