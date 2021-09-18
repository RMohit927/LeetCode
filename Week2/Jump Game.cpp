/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.

Example 1:
  Input: nums = [2,3,1,1,4]
  Output: true
  Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/

/* Approach: Complexity - O(N) - Better Solution */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int t=0;
        for(int i=0;i<nums.size()-1;i++){
            if(i==0)
                t=nums[i];
            else
                t=max(t-1,nums[i]);
            if(t<=0)
                return false;
        }
        return true;
    }
};

/* Approach: Complexity - O(N) - Two Pointer Algo */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int pos = 0;
        for(int i = 0;i<nums.size()-1;++i) {
            if(nums[i]==0 && pos==i) return false;
            else if(nums[i]+i>=pos)pos = nums[i]+i;
        }
        return pos>=nums.size() - 1;
    }
};
