/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.
Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.
Return k after placing the final result in the first k slots of nums.
Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
Custom Judge:

The judge will test your solution with the following code:
int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

  int k = removeDuplicates(nums); // Calls your implementation
  assert k == expectedNums.length;
  for (int i = 0; i < k; i++) {
      assert nums[i] == expectedNums[i];
  }

If all assertions pass, then your solution will be accepted.

Example 1:
  Input: nums = [1,1,2]
  Output: 2, nums = [1,2,_]
  Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
  It does not matter what you leave beyond the returned k (hence they are underscores).
*/

/* Approach: Complexity - O(N) - 18% faster*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int i=0;
        for(int j=1; j<nums.size(); j++){
            if(nums[j] != nums[i]){
                ++i;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};

/* Approach: Complexity - O(N) - 99% faster*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        int i=0;
        for(int j=1; j<len; j++){
            if(nums[j] != nums[i]){
                ++i;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};

/* Approach: Complexity - O(N) */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        return nums.size();
    }
};

/* Approach: Complexity - O(N) - Two Pointer Algorithm */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0,mini=INT_MIN;
        
        while(r<n)
        {
            if(nums[r]>mini)
            {
                mini=nums[r];
                swap(nums[l],nums[r]);
                l++;
                r++;
            }
            else
                r++;
        }
        return l;
    }
};
