/*
Given an unsorted integer array nums, return the smallest missing positive integer.
You must implement an algorithm that runs in O(n) time and uses constant extra space.

Example 1:
  Input: nums = [1,2,0]
  Output: 3

Example 2:
  Input: nums = [3,4,-1,1]
  Output: 2
*/

/* Approach: Complexity - O(N*Log(N)) */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int minPos = 1, curVal=1; 
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0){
                if(nums[i]==curVal) {
                    curVal++;
                    minPos = curVal;
                }
                else if(nums[i] < curVal) {}
                else{
                    break;
                }
            }          
            if(nums[i]>minPos) break;
        }
        return minPos;
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        
        while (i < n)
        {
            if (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
            else
                i++;
        }
        
        for (i = 0; i < n; i++){
            if (nums[i] != (i + 1)) return i + 1;
        }
        return n + 1;
    }
};

/* Approach: Complexity - O(N) */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == i + 1) i++;
            else if (nums[i] <= 0 || nums[i] > nums.size() || nums[i] == nums[nums[i] - 1]) {
                nums[i] = nums[nums.size() - 1];
                nums.pop_back();
            }
            else {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        return i + 1;
    }
};
