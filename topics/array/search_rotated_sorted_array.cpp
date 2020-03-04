// Source : https://oj.leetcode.com/problems/search-in-rotated-sorted-array/
// Author : Sukriti
// Date   : 2020-03-01


/********************************************************************************** 
* 
* Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
* (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
* 
* You are given a target value to search. If found in the array return its index, otherwise return -1.
* You may assume no duplicate exists in the array.
* Your algorithm's runtime complexity must be in the order of O(log n).
* 
* Example 1:
* Input: nums = [4,5,6,7,0,1,2], target = 0
* Output: 4
*               
**********************************************************************************/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int mid = 0;
        while (l <= r) {
            mid = (l + r) / 2;
            if (target == nums[mid]) return mid;
            if (nums[mid] >= nums[l]) {
                if (target >= nums[l] && target < nums[mid]) {
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            } else {
                if (target > nums[mid] && target <= nums[r]) {
                    l = mid+1;
                } else {
                    r = mid-1;
                }
            }
        }
        return -1;
    }
};
