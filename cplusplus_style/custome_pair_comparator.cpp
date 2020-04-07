// Source : https://oj.leetcode.com/problems/remove-covered-intervals/
// Author : Sukriti
// Date   : 2020-03-01


/********************************************************************************** 
* 
* Given a list of intervals, remove all intervals that are covered by another interval in the list. Interval [a,b) is covered by interval [c,d) if and only if c <= a and b <= d.
* 
* After doing so, return the number of remaining intervals.
* 
* Example 1:
* 
* Input: intervals = [[1,4],[3,6],[2,8]]
* Output: 2
* Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
*               
**********************************************************************************/

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), []
             (const vector<int>& x, const vector<int>& y) {
                 return x[0] == y[0] ? x[1] > y[1] : x[0] < y[0];
        });
        int ans = 0;
        vector<int> curr = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= curr[0] && intervals[i][1] <= curr[1]) {
                ans++;
            } else {
                curr = intervals[i];
            } 
        }
        return intervals.size() - ans;
    }
};