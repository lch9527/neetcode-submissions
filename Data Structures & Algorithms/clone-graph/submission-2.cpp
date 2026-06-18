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
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> oldmap;
        return dfs(node,oldmap);

    }

    Node* dfs(Node* node, unordered_map<Node*, Node*>& oldmap){
        if(node == nullptr){
            return nullptr;
        }

        if(oldmap.count(node)){
            return oldmap[node];
        }

        Node* copy = new Node(node->val);
        oldmap[node] = copy;

        for(Node* nd : node->neighbors){
            copy->neighbors.push_back(dfs(nd,oldmap));
        }
        return copy;
    }
};
