#include <bits/stdc++.h>
using namespace std;

// Only thing required is cnt of 1's
// so itereate and think of cases individually
class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i = 0,j = 0,carry = 0;
        
        while(i < a.size() || j < b.size() || carry == 1){
            int cnt = 0;
            cnt+=(i < a.size() ? a[i] == '1': 0);
            cnt+=(j < b.size() ? b[j] == '1': 0);
            cnt+=(carry == 1);
            
            ans+=(to_string(cnt%2));
            carry = (cnt > 1);
            i++;
            j++;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};