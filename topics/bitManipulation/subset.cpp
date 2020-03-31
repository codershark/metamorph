// Source : https://oj.leetcode.com/problems/subsets/
// Author : Sukriti
// Date   : 2020-03-01


/********************************************************************************** 
* https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/tutorial/
* Given a set of distinct integers, nums, return all possible subsets (the power set).
* 
* Note: The solution set must not contain duplicate subsets.
* 
* Example:
* 
* Input: nums = [1,2,3]
* Output:
* [
*   [3],
*   [1],
*   [2],
*   [1,2,3],
*   [1,3],
*   [2,3],
*   [1,2],
*   []
* ]
*               
**********************************************************************************/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        // 1 << N = 2^N this will generate all the combinations of binary numbers from 1 to 2^N
        for (int i = 0; i < (1 << nums.size()); i++) {
            vector<int> temp;
            for (int j = 0; j < nums.size(); j++) {
            	// Check if jth bit is set in i
                if (i & (1 << j)) {
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};