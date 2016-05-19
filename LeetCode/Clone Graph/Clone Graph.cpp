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
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (NULL == node) {
            return NULL;
        }
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> nodeMap;
        queue<UndirectedGraphNode*> visit;
        visit.push(node);
        UndirectedGraphNode *nodeCopy = new UndirectedGraphNode(node->label);
        nodeMap[node] = nodeCopy;
        while (visit.size()) {
            UndirectedGraphNode *cur = visit.front();
            visit.pop();
            int size = cur->neighbors.size();
            for (int i = 0; i < size; i++) {
                UndirectedGraphNode *neighbor = cur->neighbors[i];
                if (nodeMap.find(neighbor) == nodeMap.end()) {
                    UndirectedGraphNode *neighborCopy = new UndirectedGraphNode(neighbor->label);
                    nodeMap[cur]->neighbors.push_back(neighborCopy);
                    nodeMap[neighbor] = neighborCopy;
                    visit.push(neighbor);
                } else {
                    nodeMap[cur]->neighbors.push_back(nodeMap[neighbor]);
                }
            }
        }
        return nodeCopy;
    }
};