/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Example 1:
  Input: nums = [-1,0,1,2,-1,-4]
  Output: [[-1,-1,2],[-1,0,1]]
  
Example 2:
  Input: nums = []
  Output: []
*/

/* Approach 1: Complexity - O(N^2) - Two Pointer Algorithm */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-1; ++i) {
            
            // skip duplicate values;
            if(i!=0 && nums[i]==nums[i-1]) continue;
            if(nums[i] > 0) break;
            int lo = i+1;
            int hi = n-1;
            while(lo < hi) {
                int tempSum = nums[i] + nums[lo] + nums[hi];
                if(tempSum > 0) hi--;
                else if(tempSum < 0) lo++;
                else {
                    res.push_back({nums[i], nums[lo], nums[hi]});
                    lo++;
                    hi--;
                    while(lo < hi && nums[lo] == nums[lo-1])
                        lo++;
                }
            }
        }
        return res;
    }
};

/* Approach 2: Complexity - O(N^3) - Brute Force Algorithm - TLE and 315/318 TestCases are Passed */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Brute Force Solution Time O(N^3) & Auxiliary Space O(1)
        int len=nums.size();
        if(len==0 || len<3) // Atleast three elemnets needed for a triplet
            return {};
        set<vector<int>> s; // Set stores unique elements only(duplicate triplets not added)
        sort(nums.begin(),nums.end());
        // Compare all cases of group of three elements for their sum=0 in O(N^3) time
        for(int i=0;i<len-2;i++){
            for(int j=i+1;j<len-1;j++){
                for(int k=j+1;k<len;k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        s.insert({nums[i],nums[j],nums[k]});
                    }
                }
            }
        }
        // Insert all unique triplets in result vector
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
};
