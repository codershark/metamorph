// Source : https://oj.leetcode.com/problems/clone-graph/
// Author : Sukriti
// Date   : 2020-03-01


/********************************************************************************** 
* 
* Given a reference of a node in a connected undirected graph.
* 
* Return a deep copy (clone) of the graph.
* 
* Each node in the graph contains a val (int) and a list (List[Node]) of its neighbors.
* 
* class Node {
*     public int val;
*     public List<Node> neighbors;
* }
* 
* The graph is represented using an adjacency list.
*               
**********************************************************************************/


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
    UndirectedGraphNode *cloneGraphUtil(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode*>& visited) {
        if (visited.find(node->label) != visited.end()) return visited[node->label];
        UndirectedGraphNode* clone = new UndirectedGraphNode(node->label);
        visited[node->label] = clone;
        for (auto neigh : node->neighbors) {
            clone->neighbors.push_back(cloneGraphUtil(neigh, visited));
        }
        return clone;
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return node;
        unordered_map<int, UndirectedGraphNode*> visited;
        return cloneGraphUtil(node, visited);
    }
};
