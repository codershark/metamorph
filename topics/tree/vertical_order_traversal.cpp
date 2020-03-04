// Source : https://oj.leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// Author : Sukriti
// Date   : 2020-03-01


/********************************************************************************** 
* 
* Given a binary tree, return the vertical order traversal of its nodes values.
* 
* For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).
* 
* Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, we report the values of * the nodes in order from top to bottom (decreasing Y coordinates).* 
* 
* If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.
* Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes.
*               
**********************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    unordered_map<int, unordered_map<int, set<int>>> m;
    int min_x = INT_MAX;
    int max_x = INT_MIN;
    int max_y = INT_MIN;
    void traverse(TreeNode* node, int x, int y) {
        if (!node) return;
        m[x][y].insert(node->val);
        min_x = min(min_x, x);
        max_x = max(max_x, x);
        max_y = max(max_y, y);
        traverse(node->left, x-1, y+1);
        traverse(node->right, x+1, y+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        traverse(root, 0, 0);
        ans.resize(m.size());
        for (int i = min_x, pos = 0; i <= max_x; ++i) {
            if (m.find(i) == m.end()) continue;
            for (int j = 0; j <= max_y; j++) {
                if (m[i].find(j) == m[i].end()) continue;
                ans[pos].insert(ans[pos].end(), m[i][j].begin(), m[i][j].end());
            }
            pos++;
        }
        return ans;
    }
};
