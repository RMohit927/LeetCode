/*
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
Return intervals after the insertion.

Example 1:
  Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
  Output: [[1,5],[6,9]]

Example 2:
  Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
  Output: [[1,2],[3,10],[12,16]]
  Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
*/

/* Approach: Complexity - O(N) */

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size(), i = 0;
        vector<vector<int>> res;
        //case 1: no overlapping case before the merge intervals
		    //compare ending point of intervals to starting point of newInterval
        while(i < n && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i]);
            i++;
        }
		    //case 2: overlapping case and merging of intervals
        while(i < n && newInterval[1] >= intervals[i][0]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        // case 3: no overlapping of intervals after newinterval being merged
        while(i < n){
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};

/* Approach: Complexity - O(N*Log(N)) - Brute Force Algorithm */

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inv, vector<int>& n) {
        vector<vector<int>>v;
        bool flag=0;
        
        for(int i=0;i<inv.size();i++)
        {
            if(n[0]<=inv[i][1]&&flag==0)
            {
                int start=min(n[0],inv[i][0]);
                while(i<inv.size()&&n[1]>inv[i][1])
                {
                    i++;
                }
                int end=n[1];
                if(i<inv.size()&&n[1]<=inv[i][1]&&n[1]>=inv[i][0])
                {
                    end=inv[i][1];
                }
                else
                {
                    i--;
                }
                flag=1;
                v.push_back({start,end});
            }
            else
            {
                v.push_back(inv[i]);
            }
        }
        
        if(inv.size()==0||flag==0)
        {
            v.push_back(n);
        }
        sort(v.begin(),v.end());
        
        return v;
    }
};
