#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> cnt;
        
        int n = time.size();
        int ans = 0;
        for(int i = 0;i<n;i++) {
            int get = 60 - time[i]%60;
            if(get == 60) get = 0;       //One of the Corner Case because we are storing 0 but get will                                            //    fetch60!!
            
            if(cnt.count(get) > 0) {
                ans+=cnt[get];
            }
            cnt[time[i]%60]++;
        }
        return ans;
    }
};