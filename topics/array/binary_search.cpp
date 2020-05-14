// Source : https://oj.leetcode.com/problems/<insert problem>/
// Author : Sukriti
// Date   : 2020-03-01


/********************************************************************************** 
* 
* Given a sorted (in ascending order) integer array nums of n elements and a target value, write a function to search target in nums. If target exists, then return its index, otherwise return -1.
* 
* 
* Example 1:
* 
* Input: nums = [-1,0,3,5,9,12], target = 9
* Output: 4
* Explanation: 9 exists in nums and its index is 4
* 
* Example 2:
* 
* Input: nums = [-1,0,3,5,9,12], target = 2
* Output: -1
* Explanation: 2 does not exist in nums so return -1
*               
**********************************************************************************/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0; 
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
};

// Bnary insertion search left and right

class Solution {
public:
    int getIndex(vector<int> nums, int target, bool left) {
        int lo = 0;
        int hi = nums.size();

        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] > target || (left && target == nums[mid])) {
                hi = mid;
            }
            else {
                lo = mid+1;
            }
        }
        return lo;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        int left = getIndex(nums, target, true);
        if (left == nums.size() || nums[left] != target) {
            return ans;
        }
        ans[0] = left;
        ans[1] = getIndex(nums, target, false) - 1;
        return ans;
    }
};