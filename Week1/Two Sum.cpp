/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
Ex.
  Input: nums = [2,7,11,15], target = 9
  Output: [0,1]
  Output: Because nums[0] + nums[1] == 9, we return [0, 1].
  
Solution Complexity: O(N)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        vector<int> result;
        for(int i=0; i<nums.size(); i++){
            int rem = target - nums[i];
            if(umap.find(rem) != umap.end()){
                result.push_back(i);
                result.push_back(umap[rem]);
                return result;
            }
            umap[nums[i]] = i;
        }
        return result;
    }
};
