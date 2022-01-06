#include <bits/stdc++.h>
using namespace std;

//Recursion is used
//make partitions and if i reach end of string that means
//palindrome partition is done then take that ans into global vector
//finally dp can be used to store palindrome substrings
 
class Solution {
public:
    vector<vector<string>> global;
    bool isPalindrome(string s) {
        int n = s.size();
        for(int i = 0;i<s.size()/2;i++) {
            if(s[i] != s[n-i-1]){
                return false;
            }
        }
        return true;
    }
    void recurr(string s,vector<string> &temp) {
        if(s.size() == 0) {
            global.push_back(temp);
            return;
        }
        
        int n = s.size();
        for(int i = 0;i<n;i++) {
            
            string first = s.substr(0,i+1);
            if(isPalindrome(first)){
                temp.push_back(first);
                string second = s.substr(i+1,n-i-1);
                recurr(second,temp);
                temp.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
     
        int n = s.size();
        vector<string> temp;
        recurr(s,temp);
        return global;
    }
};