#include <bits/stdc++.h>
using namespace std;

//Dyanmic Programming
// Think of each robot standing at a col and store corresponding states
// below is the memoaization code
// Bonus while passing grid to recurr
// try to submit with and without & in grid
class Solution {
public:
    int dp[71][71][71];
    bool valid(int i ,int j , int k, int n, int m) {
        return (i>=0 && i<n && j>=0 && j<m && k>=0 && k<m);
    }
    int recurr(vector<vector<int>>& grid,int i,int j,int k) {
        int n = grid.size();
        int m = grid[0].size();
        if(!valid(i,j,k,n,m))
            return 0;
        
        if(dp[i][j][k] != -1) {
            return dp[i][j][k];
        }

        int ans = 0;
        for(int c1 = -1;c1 <= 1;c1++) {
            for(int c2 = -1;c2<=1;c2++) {
                if(!valid(i+1,j+c1,k+c2,n,m))
                    continue;
                ans = max(ans,recurr(grid,i+1,c1+j,c2+k));
            }
        }
         dp[i][j][k] = ( j == k ? grid[i][j] : (grid[i][j]+grid[i][k]));
         dp[i][j][k]+=ans;
         return dp[i][j][k];
    }
    int cherryPickup(vector<vector<int>>& grid) {
     
        memset(dp,-1,sizeof(dp));
        
        int col = grid[0].size();
        int row = grid.size();
        
        return recurr(grid,0,0,col-1);
    }
};