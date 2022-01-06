#include <bits/stdc++.h>
using namespace std;

//Greedy method is used first divide trips into
// arrival and destination vectors then use sort to check
//whether how many passengers passed arrived and departed
//Simillar to question Meeting Room
class Solution {
public:

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // sort(trips.begin(),trips.end(),comp);
        vector<pair<int,int>> arrival,destination;
        int n = trips.size();
        for(int i = 0;i<n;i++) {
            arrival.push_back({trips[i][1],i});
            destination.push_back({trips[i][2],i});
        }
        sort(arrival.begin(),arrival.end());
        sort(destination.begin(),destination.end());
        
        int first = 0,second = 0,currCap = 0;
        while(first < n && second < n) {
            if(arrival[first].first < destination[second].first){
                currCap+=trips[arrival[first].second][0];
                first++;
            } else {
                currCap-=trips[destination[second].second][0];
                second++;
            }
            // cout << currCap << " ";
            if(currCap > capacity) {
                return false;
            }
        }
        return currCap <= capacity;
    }
};