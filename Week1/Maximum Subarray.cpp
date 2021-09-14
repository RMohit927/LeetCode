/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
A subarray is a contiguous part of an array.

Example 1:
  Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
  Output: 6
  Explanation: [4,-1,2,1] has the largest sum = 6.
*/

/* Approach: Complexity - O(N) - Kanades Algo. */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far=INT_MIN;
        int max_ends_here=0;
        for(int i=0;i<nums.size();i++){
            max_ends_here+=nums[i];
            max_so_far=max(max_so_far,max_ends_here);
            if(max_ends_here<0){
                max_ends_here=0;
            }
        }
        return max_so_far;
    }
};

/* Approach: Complexity - O(N) - Dynamic Programming Algo.  */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        for(int i=1; i<n; i++){
            dp[i] =max(0, dp[i-1]) + nums[i];
        }
        return *max_element(dp.begin(), dp.end());
    }
};

/* Approach: Complexity - O(N) - Kanades Algo. */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best = nums[0];
        int curr = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
          curr = max(nums[i], curr + nums[i]);
          best = max(best, curr);
        }
        return best;
    }
};
