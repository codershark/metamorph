// Source : https://oj.leetcode.com/problems/kth-largest-element-in-an-array/
// Author : Sukriti
// Date   : 2020-03-02


/********************************************************************************** 
* 
* Find the kth largest element in an unsorted array.
* Note that it is the kth largest element in the sorted order, not the kth distinct element. 
* 
* Example 1:
* 
* Input: [3,2,1,5,6,4] and k = 2
* Output: 5
* 
* Example 2:
* 
* Input: [3,2,3,1,2,4,5,5,6] and k = 4
* Output: 4
* 
* Note:
* You may assume k is always valid, 1 ≤ k ≤ array's length.
*               
**********************************************************************************/


class Solution {
public:
    int place (vector<int>& a, int pos, int l, int r) {
        if (l >= r) return a[l];
        int x = a[r];
        int i = l;
        int j = r-1;
        
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
        if (i == pos) return a[i];
        if (i > pos) return place(a, pos, l, i-1);
        return place(a, pos, i+1, r);
    }
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() == 0) return 0;
        return place(nums, nums.size() - k, 0, nums.size() - 1);
    }
};