/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).

Ex.
  Input: nums1 = [1,3], nums2 = [2]
  Output: 2.00000
  Explanation: merged array = [1,2,3] and median is 2.

*/

/* Approach 1: Complexity: O(log(m + n)) */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const auto len1 = nums1.size();
        const auto len2 = nums2.size();

        nums1.reserve(len1+len2);
        for(auto num : nums2) nums1.push_back(num);
        //sort(nums1.begin(), nums1.end());  <<----------- Original code did O(n logn) sort here
        nums2.resize(len1+len2);
        merge(nums1.begin(), nums1.begin() + len1, nums1.begin() + len1, nums1.end(), nums2.begin());

        const int n = nums2.size() / 2;
        if(nums2.size() % 2 == 0){
            return (double)(nums2[n] + nums2[n - 1]) / 2;
        }

        return (double)nums2[n];
    }
};

/* Approach 2: Complexity: O(n*log(m)) */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result;
        int sz = nums2.size();
        for(int i=0, j=sz-1; i<sz/2 || j>=sz/2; i++, j--){
            if(i<j) nums1.push_back(nums2[i]);
            nums1.push_back(nums2[j]);
        }
        sort(nums1.begin(), nums1.end());
        int n=nums1.size();
        if(n % 2 == 0) 
            return (nums1[n/2-1] + nums1[n/2]) / 2.0;
        else
            return (nums1[(n-1)/2]);  
    }
};

