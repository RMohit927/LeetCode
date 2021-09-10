/*
There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
    Input: nums = [4,5,6,7,0,1,2], target = 0
    Output: 4
*/

/* Approach: Complexity - O(N) - Brute Force Algorithm  - 100% Faster*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int  n=nums.size();
        for(int i=0;i<n;++i){
            if(nums[i]==target) return i;
        }
        return -1;
    }
};

/* Approach: Complexity - O(log(N)) - Binary Search Algorithm - 75% Faster */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), low = 0, high = n-1;
        
        while(low <= high){
            int mid = ((low + high) >> 1);
            
            if(nums[mid] == target) return mid;
            else if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target < nums[mid]){
                    high = mid - 1;
                }
                else low = mid + 1;
            }
            else{
                if(nums[mid] < target && target <= nums[high]){
                    low = mid + 1;
                }
                else high = mid - 1;
            }
        }
        return -1;
    }
};
