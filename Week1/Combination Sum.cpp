/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Example 1:
  Input: candidates = [2,3,6,7], target = 7
  Output: [[2,2,3],[7]]
  Explanation:
  2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
  7 is a candidate, and 7 = 7.
  These are the only two combinations.
*/

/* Approach: Complexity - O(N!) - BackTracking Algorithm - Bcz we need to explore every possible ways */

class Solution {
public:
    void solve(int i,int target,vector<vector<int>> &ans,vector<int> &ds,vector<int>& candidates)
    {
        if(i==candidates.size())
        {
            if(target==0)
            {
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[i]<=target)
        {
            ds.push_back(candidates[i]);
            solve(i,target-candidates[i],ans,ds,candidates);
            ds.pop_back();
        }
        solve(i+1,target,ans,ds,candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> empty;
        solve(0,target,ans,empty,candidates);
        return ans;
    }
};

/* Approach: BackTracking Algorithm - 100% Faster*/

class Solution {
public:
    vector<vector<int>>ans;
    
    void solve(vector<int>&v, vector<int>&tmp, int target, int ind){
        if(target<0) return;
        if(!target){
            ans.push_back(tmp);
            return;
        }
        for(int i=ind;i<v.size();i++){
            tmp.push_back(v[i]);
            solve(v,tmp,target-v[i],i);
            tmp.pop_back();
        }
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>tmp;
        sort(candidates.begin(), candidates.end());
        solve(candidates, tmp, target, 0);
        
        return ans;
    }
};
