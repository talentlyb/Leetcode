// First time. 4/1/2015

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hashTable;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) {
            return NULL;
        }
        if (hashTable.find(node) == hashTable.end()) {
            hashTable[node] = new UndirectedGraphNode (node->label);
            for (int i = 0; i < (node->neighbors).size(); ++i) {
                ((hashTable[node])->neighbors).push_back(cloneGraph((node->neighbors)[i]));
            }
        }
        return hashTable[node];
    }
};