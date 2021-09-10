/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.

Example 1:
  Input: nums = [5,7,7,8,8,10], target = 8
  Output: [3,4]
*/

/* Approach: Complexity - O(log(N)) - Binary Search Algorithm */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size(), a = -1, b = -1;
        int low = 0, high = n-1;
        
        while(low <= high){
            int mid = (high - low)/2 + low;
            if (nums[mid] == target ) {
                a = b = mid;
                while (a-1 >= 0 && nums[a-1] == target ) a--;
                while (b+1 < n && nums[b+1] == target ) b++;
                return {a,b};
            }
            else if ( nums[mid] < target ) low = mid+1;
            else high = mid-1;
        }
        return {a,b};
    }
};

// [5, 7, 8, 8, 9, 10]

