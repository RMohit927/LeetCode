/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
Example 1:
  Input: nums = [1,2,3]
  Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
  Input: nums = [0,1]
  Output: [[0,1],[1,0]]
*/

/* Approach: Complexity - O(N*Log(N)) - Next_Permutation Built in function */

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>result;
        sort(nums.begin(),nums.end());
        do{
            result.push_back(nums);
        }while(next_permutation(nums.begin(), nums.end()));
        return result;
    }
};

/* Approach: Complexity - Exponential - BackTracking Algorithm */

class Solution {
public:
    void solve(vector<vector<int>> &ans , vector<int> &nums ,int index)
    {
        if(index==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[i],nums[index]);
            solve(ans,nums,index+1);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index=0;
        solve(ans,nums,index);
        return ans;
    }
};
