// Source : https://oj.leetcode.com/problems/is-graph-bipartite/
// Author : Sukriti
// Date   : 2020-03-01


/********************************************************************************** 
* 
* Given an undirected graph, return true if and only if it is bipartite.
* 
* Recall that a graph is bipartite if we can split it's set of nodes into two independent subsets A and B such that every edge in the graph has one node in A and another node in B.
* 
* The graph is given in the following form: graph[i] is a list of indexes j for which the edge between nodes i and j exists.  Each node is an integer between 0 and graph.length - 1.  There are no self edges or parallel edges: graph[i] does not contain i, and it doesn't contain any element twice.
* 
* Example 1:
* Input: [[1,3], [0,2], [1,3], [0,2]]
* Output: true
* Explanation: 
* The graph looks like this:
* 0----1
* |    |
* |    |
* 3----2
* We can divide the vertices into two groups: {0, 2} and {1, 3}.
* Example 2:
* Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
* Output: false
* Explanation: 
* The graph looks like this:
* 0----1
* | \  |
* |  \ |
* 3----2
* We cannot find a way to divide the set of nodes into two independent subsets.
*               
**********************************************************************************/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // 0: blue, 1: red, -1: uncolored
        vector<int> color(graph.size(), -1);
        for (int i = 0; i < graph.size(); i++) {
            if (color[i] != -1) continue;
            stack<int> s;
            s.push(i);
            color[i] = 0;
            while (!s.empty()) {
                int curr = s.top();
                s.pop();
                for (auto neigh : graph[curr]) {
                    if (color[neigh] == -1) {
                        color[neigh] = color[curr] ^ 1;
                        s.push(neigh);
                    } else if (color[neigh] == color[curr]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};