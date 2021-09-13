/*
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
You can assume that you can always reach the last index.

Example 1:
  Input: nums = [2,3,1,1,4]
  Output: 2
  Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/

/* Approach: Complexity - O(N) - Greedy Solution */

class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0, curFarthest = 0, curEnd = 0;
        int n = nums.size();
        for(int i=0; i<n-1; i++){
            curFarthest = max(i+nums[i], curFarthest);
            if(i==curEnd){
                count++;
                curEnd = curFarthest;
            }
        }
        return count;
    }
};

/* Approach: Complexity - O(N) */

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
    
        int maxReach=nums[0], step=nums[0];
        int jump=1;

        for(int i=1;i<nums.size();i++)
        {
            if(i==nums.size()-1) return jump;
            maxReach = max(maxReach,i+nums[i]);
            step--;
            if(step==0) {       
                jump++;   
                step=maxReach-i;   
            }  
        }
        return -1;
    }
};

/* Approach: Complexity - O(N^2) - Dynamic Programming */

class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(j+nums[j] >= i){
                    dp[i] = min(dp[i],dp[j]+1);
                }
            }
        }
        return dp[n-1];
    }
};
