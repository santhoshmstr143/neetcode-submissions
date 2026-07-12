/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<int> start, end;
        for(auto it : intervals)
        {
            start.push_back(it.start);
            end.push_back(it.end);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int room = 0;
        int ans = 0;
        int i = 0, j=0;
        while(i< n)
        {
            if(start[i]<end[j])
            {
                room++;
                ans = max(room,ans);
                i++;
            }
            else
            {
                room--;
                j++;
            }
        }
        return ans;
    }
};
