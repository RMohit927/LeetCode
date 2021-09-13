/*
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

Example 1:
  Input: nums = [1,1,2]
  Output: [[1,1,2], [1,2,1], [2,1,1]]

Example 2:
  Input: nums = [1,2,3]
  Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

/* Approach: Complexity - O(N) - Next_Permutation Function */

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> solution;
        sort(nums.begin(), nums.end());
        do 
        {
            solution.push_back(nums);    
        }while(next_permutation(nums.begin(),nums.end()));
        return solution;
    }
};

/* Approach: Complexity - BackTracking Algorithm */

class Solution {
public:
    void choose_one(vector<int>& nums, int j, vector<vector<int>> &solution, int n)
    {
        if (j == n-1)
        {
            solution.push_back(nums);
            return;
        }
        set<int> s;
        s.insert(nums[j]);
        choose_one(nums, j+1, solution, n);
        for (int i=j+1; i<n; i++)
        {
            if (s.find(nums[i]) != s.end())
                continue;
            s.insert(nums[i]);
            swap(nums[j], nums[i]);
            choose_one(nums, j+1, solution, n);
            swap(nums[j], nums[i]);
        }        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> solution;
        choose_one(nums, 0, solution, n);
        return solution;
    }
};
