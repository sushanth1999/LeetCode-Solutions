#include <bits/stdc++.h>
using namespace std;

//here while taking out i made number
class Solution {
public:
    int bitwiseComplement(int n) {
        int ans = 0;
        int curr = 1;
        if(n == 0) {
            return 1;
        }
        while(n) {
            int k = n%2;
            if(!k){
                ans+=curr;
            }
            curr = curr*2;
            n = n/2;
        }
        return ans;
    }
};