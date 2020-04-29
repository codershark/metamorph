// Source : https://oj.leetcode.com/problems/<insert problem>/
// Author : Sukriti
// Date   : 2020-03-01


/********************************************************************************** 
* 
* Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very * right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. 
* Return the max sliding window.
* 
* Follow up:
* Could you solve it in linear time?
* 
* Example:
* 
* Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
* Output: [3,3,5,5,6,7] 
* Explanation: 
* 
* Window position                Max
* ---------------               -----
* [1  3  -1] -3  5  3  6  7       3
*  1 [3  -1  -3] 5  3  6  7       3
*  1  3 [-1  -3  5] 3  6  7       5
*  1  3  -1 [-3  5  3] 6  7       5
*  1  3  -1  -3 [5  3  6] 7       6
*  1  3  -1  -3  5 [3  6  7]      7
*  
*               
**********************************************************************************/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        if (nums.size() == 0 || k == 0 || nums.size() < k) return result;
        deque<pair<int, int>> q; //value, index
        for (int i = 0; i < k && i < nums.size(); ++i) {
            while (!q.empty() && q.back().first < nums[i]) {
                q.pop_back();
            }
            q.push_back({nums[i], i});
        }        
        int index = k - 1;
        while (index < nums.size()) {
            while (!q.empty() && q.back().first < nums[index]) {
                q.pop_back();
            }
            q.push_back({nums[index], index});
            result.push_back(q.front().first);
            if (q.front().second < index - k - 1) q.pop_front();
            index++;
        }
        return result;
    }
};