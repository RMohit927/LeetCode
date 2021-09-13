/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:
  Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
  Output: 6
  Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
*/

/* Approach: Complexity - O(N) - Dynamic Programming */

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> pre(height.size(),0);
        vector<int> suf(height.size(),0);
        int maxi=-1;
        for(int i=0;i<height.size();i++)
        {
            maxi=max(maxi,height[i]);
            pre[i]=maxi;
        }
        maxi=-1;
        for(int i=height.size()-1;i>=0;i--)
        {
            maxi=max(maxi,height[i]);
            suf[i]=maxi;
        }
        int cnt=0;
        for(int i=0;i<height.size();i++)
        {
            cnt+= min(pre[i],suf[i])-height[i];
        }
        return cnt;
    }
};

/*
[0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3]
[3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 1]
*/

/* Approach: Complexity - O(N) - Two Pointer Approach */

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxleft = height[0], maxright = height[n-1];
        int sum = 0, l = 1, r = n-2;
        while(l<=r)
        {
            if(maxleft<maxright) // we know maxright wont effect our calculations
            {
                if(height[l]>maxleft) // is current height is > maxleft, no water can be trapped
                    maxleft = height[l]; // update the max left
                else
                    sum+=maxleft-height[l++]; //else increase the sum of trapped water
            }
            else // now we know maxleft wont effect our calculations
            {
                if(height[r]>maxright) //similar logic as described above
                    maxright = height[r];
                else
                    sum+=maxright-height[r--];
            }
        }
        return sum;
    }
};
