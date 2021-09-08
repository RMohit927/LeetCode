/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.
Notice that you may not slant the container.

Ex.
    Input: height = [1,8,6,2,5,4,8,3,7]
    Output: 49
    Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

*/

/* Approach 1: Complexity - O(N) - Two Pointer Approach */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int res = 0, ans = 0;
        while(i <= j){
            ans = (j-i)*(min(height[i], height[j]));
            res = max(res, ans);
            if(height[i] < height[j])
                i++;
            else
                j--;
        }
        return res; 
    }
};

/* Approach 2: Complexity - O(N^2) - Brute Force Approach - 53/60 Test Cases are Passed */

class Solution {
public:
    int maxArea(vector<int>& height) {
        // Brute Force Solution Time O(N^2) & Auxiliary Space O(1)
	    // Time Limit Exceed(TLE) 53/60 test cases passed
        int len=height.size(), max=0, area=0;
            for(int i=0;i<len;i++){
                for(int j=i+1;j<len;j++){
                    area=min(height[i],height[j])*(j-i);
                    if(area>max)
                        max=area;
                }
            }
        return max; 
    }
};



