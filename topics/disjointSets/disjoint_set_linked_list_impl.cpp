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
private:
    struct Node {
        int val;
        int rank;
        Node* parent;
        Node(int x) : val(x), rank(0), parent(nullptr){};
    };
    
    unordered_map<int, Node*> node_map;
    
    Node* findSetParent(Node* node) {
        if (node->parent != node) {
            node->parent = findSetParent(node->parent);
        }
        return node->parent;
    }

public:
    void makeSet(int val) {
        if (node_map.find(val) == node_map.end()) {
            node_map[val] = new Node(val);
            node_map[val]->parent = node_map[val];
        }
    }
    
    bool unionSet(int u, int v) {
        // Returns false if no union operation has been done
        Node* u_node = node_map[u];
        Node* v_node = node_map[v];

        int u_parent = (findSetParent(u_node))->val;
        int v_parent = (findSetParent(v_node))->val;
        
        // They're already in the same set so no need to union
        if (u_parent == v_parent) return false;
        
        if (node_map[u_parent]->rank == node_map[v_parent]->rank) {
            node_map[u_parent]->rank++;
            node_map[v_parent]->parent = node_map[u_parent];
        } else if (node_map[u_parent]->rank > node_map[v_parent]->rank) {
            node_map[v_parent]->parent = node_map[u_parent];
        } else {
            node_map[u_parent]->parent = node_map[v_parent];
        }
        
        return true;
    } 
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointSet dsu;
        for (auto edge : edges) {
            dsu.makeSet(edge[0]);
            dsu.makeSet(edge[1]);
            if (dsu.unionSet(edge[0], edge[1]) == false) {
                return edge;
            }
        }
        return vector<int>();
    }
};
