class Solution {
    unordered_set<int> vist;

public:
    bool validTree(int n, vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> graph;

        for (const auto& i : edges) {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }

        if (!dfs(graph, 0, -1)) {
            return false;
        }

        if (vist.size() < n) {
            return false;
        }

        return true;
    }

    bool dfs(unordered_map<int, vector<int>>& graph, int node, int parent) {

        if (vist.count(node)) {
            return false;
        }

        vist.insert(node);

        for (int neighbor : graph[node]) {

            if (neighbor == parent) {
                continue;
            }

            if (!dfs(graph, neighbor, node)) {
                return false;
            }
        }

        return true;
    }
};