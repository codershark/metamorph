// Source : https://oj.leetcode.com/problems/closest-binary-search-tree-value/
// Author : Sukriti
// Date   : 2020-03-01


/********************************************************************************** 
* 
* Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
* 
* Note:
* 
* Given target value is a floating point.
* You are guaranteed to have only one unique value in the BST that is closest to the target.
* Example:
* 
* Input: root = [4,2,5,1,3], target = 3.714286
* 
*     4
*    / \
*   2   5
*  / \
* 1   3
* 
* Output: 4
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
    int closestValue(TreeNode* root, double target) {
        int curr;
        int ans = root->val;
        while (root != nullptr) {
            curr = root->val;
            ans = abs(target-ans) > abs(target-curr) ? curr : ans;
            if (curr > target) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return ans;
    }
};