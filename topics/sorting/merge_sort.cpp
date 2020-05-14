// Source : https://oj.leetcode.com/problems/sort-an-array/
// Author : Sukriti
// Date   : 2020-03-02


/********************************************************************************** 
* 
* Given an array of integers nums, sort the array in ascending order.
* Example 1:
* 
* Input: nums = [5,2,3,1]
* Output: [1,2,3,5]
* Example 2:
* 
* Input: nums = [5,1,1,2,0,0]
* Output: [0,0,1,1,2,5]
*               
**********************************************************************************/


class Solution {
public:
    void merge(vector<int>& nums, int l, int m, int r) {
        vector<int> result;
        int i, j;
        for (i = l, j = m; i < m && j < r; ){
            if (nums[i] < nums[j]) {
                result.push_back(nums[i++]);
            } else {
                result.push_back(nums[j++]);
            }
        }
        while (i < m) {
            result.push_back(nums[i++]);
        }
        while (j < r) {
            result.push_back(nums[j++]);
        }
        for (i = l; i < r; i++) {
            nums[i] = result[i - l];
        }
    }
    void split(vector<int>& nums, int l, int r) {
        if (r - l <= 1) return;
        int mid = (l + r) / 2;
        split(nums, l, mid);
        split(nums, mid, r);
        merge(nums, l, mid, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        split(nums, 0, nums.size());
        return nums;
    }
};
