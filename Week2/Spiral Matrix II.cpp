/*
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Example 1:
  Input: n = 3
  Output: [[1,2,3],[8,9,4],[7,6,5]]

Example 2:
  Input: n = 1
  Output: [[1]]
*/

/* Approach: Complexity - O(N) -4 Pointer */

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int p=1;
        int i=0,j=0,r=n,c=n;
        vector<vector<int>> v(n,vector<int>(n));
        while(i<r && j<c){
            for(int k=j;k<c;k++) v[i][k]=p++;
            i++;
            for(int k=i;k<r;k++) v[k][c-1]=p++;
            c--;
            if(j<c){
                for(int k=c-1;k>=j;k--) v[r-1][k]=p++;
                r--;
            }
            if(i<r){
                for(int k=r-1;k>=i;k--) v[k][j]=p++;
                j++;
            }
        }
        return v;
    }
};

/*
[1,2,3, 4,5,6, 7,8,9]
[1,2,3, 9,8,4, 7,6,5]

[1,2,3,4, 5,6,7,8, 9,10,11,12, 13,14,15,16]
[1,2,3,4,
 12,13,14,5,
 11,16,15,6,
 10,9,8,7]
*/
