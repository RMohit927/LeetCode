/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:
  Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
  Output: [[1,6],[8,10],[15,18]]
  Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
*/

/* Approach: Complexity - O(N * Log(N)) */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> temp = intervals[0];
        for(int i=1; i<n; i++){
            if(temp[1] >= intervals[i][0]){
                temp = {min(temp[0], intervals[i][0]), max(temp[1], intervals[i][1])};
            }else{
                ans.push_back(temp);
				temp = intervals[i];
            }
        }
        ans.push_back(temp);
		return ans;
    }
};

/* Approach: Complexity - O(N) - Map */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int,int> m;
        for(auto inter:intervals){
            m[inter[0]]++;
            m[inter[1]]--;
        }
        
		vector<vector<int>> ret;
        int start = 0;
        int count = 0;
        
        for (auto p : m) {
            
			//this handles the case of interval (n,n)
            if (p.second == 0 && count == 0){
                ret.push_back(vector<int>{p.first, p.first});
                continue;
            }
            
            if (count == 0 && p.second>0) {
                start=p.first;
            } 
            count += p.second;
            if(count==0) {
                ret.push_back(vector<int>{start, p.first});
            }
        }
		
        return ret;
    }
};
