/*


*/

/* Approach: Complexity - O(N) - Brute Force Algorithm  - 100% Faster*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int  n=nums.size();
        for(int i=0;i<n;++i){
            if(nums[i]==target) return i;
        }
        return -1;
    }
};

/* Approach: Complexity - O(log(N)) - Binary Search Algorithm - 75% Faster */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), low = 0, high = n-1;
        
        while(low <= high){
            int mid = ((low + high) >> 1);
            
            if(nums[mid] == target) return mid;
            else if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target < nums[mid]){
                    high = mid - 1;
                }
                else low = mid + 1;
            }
            else{
                if(nums[mid] < target && target <= nums[high]){
                    low = mid + 1;
                }
                else high = mid - 1;
            }
        }
        return -1;
    }
};
