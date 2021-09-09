/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Example 1:
  Input: nums = [1,0,-1,0,-2,2], target = 0
  Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
  
Example 2:
  Input: nums = [2,2,2,2,2], target = 8
  Output: [[2,2,2,2]]
*/

/* Approach 1: Complexity - O(N^3) - Two Pointer Algorithm */

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();  
        sort(nums.begin() , nums.end());  // sort the array to use the two pointers method
        
        vector<vector<int>> ans;  
        set<vector<int>> store;   // to store and remove the duplicate answers
		
        for(int i = 0 ; i < n; i++)
        {
            for(int j = i + 1; j < n ; j++)
            {
                int new_target  =  target - nums[i] - nums[j];
                int x = j+1 , y = n-1;
                while(x < y){
                    int sum = nums[x] + nums[y];
                    if(sum > new_target) y--;
                    else if(sum < new_target ) x++;
                    else  {
                        store.insert({nums[i] , nums[j] , nums[x] , nums[y]});
                        x++;
                        y--;
                    };
                }
            }
        }
        for(auto i : store){
            ans.push_back(i);  // store the answers in an array(ans)
        }
        return ans;
    }
};
