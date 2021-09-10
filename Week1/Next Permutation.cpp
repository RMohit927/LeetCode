/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).
The replacement must be in place and use only constant extra memory.

Example 1:
  Input: nums = [1,2,3]
  Output: [1,3,2]

Example 2:
  Input: nums = [3,2,1]
  Output: [1,2,3]
*/

/* Approach: Complexity - O(N) - One Line Code - 80% Faster */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Optimal Solution Time O(N) & Auxiliary Space O(1)
	      // Inbuilt Function
        next_permutation(nums.begin(),nums.end());
    }
};

/* Approach: Complexity - O(N) - */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = -1, n = nums.size();
        for(int i=n-1; i>0; i--){
            if(nums[i] > nums[i-1]){
                idx = i;
                break;
            }
        }
        if(idx == -1){
            reverse(nums.begin(),nums.end());
        }else{
            int prev = idx;
            for(int i = idx+1; i<n; i++){
                if(nums[i]>nums[idx - 1] and nums[i]<=nums[prev]){
                    prev = i;
                }
            }
            swap(nums[idx - 1], nums[prev]);
            reverse(nums.begin()+idx, nums.end());
        }
    }
};
