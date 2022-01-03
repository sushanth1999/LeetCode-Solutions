#include <bits/stdc++.h>
using namespace std;

//Implementation Question.
// below is O(N) solution
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int cnt[n+1],judge[n+1];
        memset(cnt,0,sizeof(cnt));
        memset(judge,0,sizeof(judge));

        int size = trust.size();
        for(int i = 0;i<size;i++) {
                cnt[trust[i][1]]++;
                judge[trust[i][0]] = 1;
        }
        for(int i = 1;i<=n;i++) {
            if(judge[i] == 0) {
                if(cnt[i] == n-1) {
                    return i;
                }
            }
        }
        return -1;
    }
};