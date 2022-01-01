#include <bits/stdc++.h>
using namespace std;

// Dynamic Problem Question
// MCM variant
// Below is the Memoization technique
class Solution {
public:
    int dp[510][510];
    int solve(vector<int> &nums,int start,int end) {
        if(start > end) return 0;
        
        int n = nums.size();
        //to decide if there is one element
        if(start == end) {
            int temp = 0;
            int k = start;
            if(start == 0) {
                temp+=nums[start]*nums[k+1];
            }
            else if(k == n-1){
                temp+=nums[k]*nums[k-1];
            }
            else {
                temp+=(nums[k]*nums[k-1]*nums[k+1]);
            }
            return temp;
        }
        
        if(dp[start][end] != -1) return dp[start][end];
        
        int ans = INT_MIN;
        //For every value of k in the window (from start to end) 
        //check whether from start to k-1 + k+1 to end 
        // finally if that k lefts out what would be the ans.
        for(int k = start;k<=end;k++) {
            int temp = solve(nums,start,k-1) + solve(nums,k+1,end);
            int left,right;
             left = (start-1 == -1) ? 1 : nums[start-1];
             right = (end+1 == n) ? 1 : nums[end+1];
            
            temp+=nums[k]*left*right;
            
            ans = max(ans,temp);
        }
        return dp[start][end] = ans;
    }
    int maxCoins(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
        return solve(nums,0,n-1);
    }
};