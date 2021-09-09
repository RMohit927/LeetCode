/*
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.

Example 1:
  Input: nums = [-1,2,1,-4], target = 1
  Output: 2
  Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2
  
Example 2:
  Input: nums = [0,0,0], target = 1
  Output: 0
*/

/* Approach 1: Complexity - O(N^2) - Two Pointer Algorithm */

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size(), ans = INT_MAX / 2;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++)
        {
            int left  = i + 1, right = n - 1;
            int value = nums[i] + nums[left] + nums[right];
            while (left < right)
            {
                if (abs(value - target) < abs(ans - target))
                    ans = value;
                if (value < target)
                {
                    left++;
                    value = value - nums[left - 1] + nums[left];
                }
                else if (value > target)
                {
                    right--;
                    value = value - nums[right + 1] + nums[right];
                }
                else if (value == target)
                    return target;
            }
        }
        return ans;
    }
};

