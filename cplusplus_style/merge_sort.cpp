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
    void qsort(vector<int>& a, int l, int r) {
        
        if (l >= r) return;
        int x = a[r];
        int i = l;
        int j = r - 1;
        while (i <= j) {
            while (a[i] < x) ++i;
            while (i <= j && a[j] > x) --j;
            if (i <= j) {
                swap(a[i], a[j]);
                ++i;
                --j;
            }
        }
        swap(a[i], a[r]);
        qsort(a, l, i -1);
        qsort(a, i + 1, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        if (nums.size() < 2) return nums;
        vector<int> copy = nums;
        qsort(copy, 0, nums.size() -1);
        return copy;
    }
};
