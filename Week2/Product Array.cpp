/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:
  Input: nums = [1,2,3,4]
  Output: [24,12,8,6]
*/

/* Approach 1: Complexity - Time: O(N), Space: O(N) - Without using Division */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int n = a.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        vector<int> ans(n);

        //Building prefix array
        prefix[0] = a[0];
        for(int i = 1; i < n; i++) 
            prefix[i] = prefix[i-1] * a[i];

        //Building suffix array
        suffix[n-1] = a[n-1];
        for(int i = n-2; i >= 0; i--)
            suffix[i] = suffix[i+1] * a[i];

        //Corner values
        ans[0] = suffix[1];    //As we can't call prefix[-1].
        ans[n-1] = prefix[n-2];  //As we can't call suffix[N].

        for(int i = 1; i < n-1; i++)
            ans[i] = prefix[i-1] * suffix[i+1];

        return ans;
    }
};

=======================
 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> leftProd(n);
        vector<int> rightProd(n);
        
        leftProd[0] = 1;
        for(int i = 1; i < nums.size(); i++){
            leftProd[i] = leftProd[i - 1] * nums[i - 1];
        }
        
        rightProd[n - 1] = 1;
        for (int j = n - 2; j >= 0; j--) {
            rightProd[j] = rightProd[j + 1] * nums[j + 1];
        }
        
        for (int k = 0; k < n; k++) {
            ans[k]= leftProd[k] * rightProd[k];
        }
        
        return ans;
    }
};

/* Approach 2: Complexity - O(N^2) */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j){
                    continue;
                }
                ans[i] = ans[i] * nums[j]; 
            }
        }

        return ans;
    }
};

/* Approach 3: Complexity - O(N) */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        
        int zero = 0;
        int product = 1;
        for(auto x : nums){
            if(x == 0)
                zero = zero + 1;
            else
                product = product * x;
        }
        for(auto x : nums){
            if(x == 0){
                if(zero != 1)
                    ans.push_back(0);
                else
                    ans.push_back(product);
            }else{
                if(zero == 0)
                    ans.push_back(product/x);
                else
                     ans.push_back(0);
            }
        }
        return ans;
    }
};

