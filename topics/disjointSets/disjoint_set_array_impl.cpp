// Source : https://oj.leetcode.com/problems/redundant-connection/
// Author : Sukriti
// Date   : 2020-03-01


/********************************************************************************** 
* 
* In this problem, a tree is an undirected graph that is connected and has no cycles.
* 
* The given input is a graph that started as a tree with N nodes 
* (with distinct values 1, 2, ..., N), with one additional edge added.
* The added edge has two different vertices chosen from 1 to N, 
* and was not an edge that already existed.
* 
* The resulting graph is given as a 2D-array of edges.
* Each element of edges is a pair [u, v] with u < v, that represents an 
* undirected edge connecting nodes u and v.
* 
* Return an edge that can be removed so that the resulting graph 
* is a tree of N nodes. If there are multiple answers, return the answer 
* that occurs last in the given 2D-array. 
* The answer edge [u, v] should be in the same format, with u < v.
* 
* Example 1:
* 
* Input: [[1,2], [1,3], [2,3]]
* Output: [2,3]
* Explanation: The given undirected graph will be like this:
*   1
*  / \
* 2 - 3
*               
**********************************************************************************/


class DisjointSet {
public:
    DisjointSet(int n) {
        parent = vector<int> (n + 1, 0);
        rank = vector<int> (n + 1, 0);
        for (int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }
    }
    
    int findSetParent(int node) {
        if (parent[node] != node) {
            parent[node] = findSetParent(parent[node]);
        }
        return parent[node];
    }
    
    bool unionSet(int u, int v) {
        // Returns false if no union operation has been done
        int u_parent = findSetParent(u);
        int v_parent = findSetParent(v);
        
        // They're already in the same set so no need to union
        if (u_parent == v_parent) return false;
        
        if (rank[u_parent] == rank[v_parent]) {
            rank[u_parent]++;
            parent[v_parent] = parent[u_parent];
        } else if (rank[u_parent] > rank[v_parent]) {
            parent[v_parent] = parent[u_parent];
        } else {
            parent[u_parent] = parent[v_parent];
        }
        
        return true;
    }
private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointSet dsu(edges.size());
        for (const auto& edge : edges) {
            if (!dsu.unionSet(edge[0], edge[1])) {
                return edge;
            }
        }
        return {};
    }
};