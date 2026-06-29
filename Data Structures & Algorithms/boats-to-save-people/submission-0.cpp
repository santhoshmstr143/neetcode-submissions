class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int l = 0,r= people.size()-1;
        int cnt = 0;
        while(l<=r)
        {
            
            int w =(l<r)? people[l]+people[r] : people[l];
            if(w<=limit)
            {
                l++;
                r--;
                cnt++;
            }
            else
            {
                r--;
                cnt++;
            }
        }
        return cnt;
    }
};