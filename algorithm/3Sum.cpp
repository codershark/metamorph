// Source : https://oj.leetcode.com/problems/3sum/
// Author : Sukriti
// Date   : 2020-03-01

/********************************************************************************** 
* 
* Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
* Find all unique triplets in the array which gives the sum of zero.
* 
* Note:
* 
* Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
* The solution set must not contain duplicate triplets.
* 
*     For example, given array S = {-1 0 1 2 -1 -4},
* 
*     A solution set is:
*     (-1, 0, 1)
*     (-1, -1, 2)
* 
*               
**********************************************************************************/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    if (nums.size() == 0) return ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; ++i) {
        if (i > 0 && nums[i - 1] == nums[i]) continue;
        int start = i + 1;
        int end = nums.size() - 1;
        while (start < end) { 
            int sum = nums[i] + nums[start] + nums[end];
            if (sum > 0) {
                --end;
            } else if (sum < 0) {
                ++start;
            } else {
                vector<int> temp = {nums[i], nums[start], nums[end]};
                ans.push_back(temp);
                while (start < end && nums[start + 1] == nums[start]) {
                    ++start;
                }
                ++start;
                --end;
            }
        }
    }
    
    return ans;
}


void printMatrix(vector<vector<int>> &matrix)
{
    for(int i = 0; i < matrix.size(); i++) {
        printf("{");
        for(int j = 0; j < matrix[i].size(); j++) {
            printf("%3d ", matrix[i][j]) ;
        }
        printf("}\n");
    }
    cout << endl;
}


int main()
{
    //int a[] = { -1, 0, 1, 2, -1, 1, -4 };
    int a[] = { -1, 1, 1, 1, -1, -1, 0,0,0 };
    vector<int> n(a, a + sizeof(a)/sizeof(int));
    vector< vector<int>> result = threeSum(n);
    printMatrix(result);    
    return 0;
}

