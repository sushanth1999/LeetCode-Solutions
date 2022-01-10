#include <bits/stdc++.h>
using namespace std;

// try to visualise two cases
// when after given instructions where does robot point to
// After given restrictions does displacemet = 0
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int l = 0,r = 0;
        int x = 0,y = 0,point = 0;
         for(auto it: instructions){
            
             if(it == 'L') {
                 l++;
                 point++;
                 continue;
             }  if(it == 'R'){
                 r++;
                 point--;
                 continue;
             }
             
             if(point%4 == 0){
                 y++;
             }
             else if(abs(point%4) == 2){
                 y--;
             }
             else if(point%4 == 1 || point%4 == -3){
                 x++;
             } else {
                 x--;
             }
             
         }
  
        if(abs(l-r)%4 != 0 || (x==0&&y==0))  {
            return true;
        }
        
        return false;
        
    }
};