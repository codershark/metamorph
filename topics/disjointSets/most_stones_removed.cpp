// Source : https://oj.leetcode.com/problems/most-stones-removed-with-same-row-or-column/
// Author : Sukriti
// Date   : 2020-03-01


/********************************************************************************** 
* 
* On a 2D plane, we place stones at some integer coordinate points.  Each coordinate point may have at most one stone.
* 
* Now, a move consists of removing a stone that shares a column or row with another stone on the grid.
* 
* What is the largest possible number of moves we can make?
* 
*  
* 
* Example 1:
* 
* Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
* Output: 5
* 
* Example 2:
* 
* Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
* Output: 3
*               
**********************************************************************************/


class DisjointSet {
public:
    DisjointSet(int n) {
        parent = vector<int>(n, 0);
        rank = vector<int>(n, 0);
        for (int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }
    }
    int findSetParent(int u) {
        if (parent[u] != u) {
            parent[u] = findSetParent(parent[u]);
        }
        return parent[u];
    }
    void UnionSet(int u, int v) {
        int pu = findSetParent(u);
        int pv = findSetParent(v);
        if (pu == pv) return;
        
        if (rank[pu] == rank[pv]) {
            parent[pv] = pu;
            rank[pu]++;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pu] = pv;
        }
        return;
    }
private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        DisjointSet dsu(20000);
        unordered_set<int> seen;
        for (const auto& stone : stones) {
            dsu.UnionSet(stone[0], 10000 + stone[1]);
        }
        for (const auto& stone : stones) {
            seen.insert(dsu.findSetParent(stone[0]));
        }
        return stones.size() - seen.size();
    }
};
