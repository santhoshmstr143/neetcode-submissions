class Solution {
public:
    vector<int> partitionLabels(string s) {\
        vector<int> ans;
        vector<pair<int,int>> interval(26,{-1,-1});
        for(int i=0;i<s.size();i++)
        {
            int idx = s[i]-'a';
            if(interval[idx].first==-1)
            {
                interval[idx].first = i;
            }
            interval[idx].second = i;
        }        
        vector<pair<int,int>> a;
        for(int i=0;i<26;i++)
        {
            if(interval[i].first!= -1)
            {
                a.push_back(interval[i]);
            }
        }
        sort(a.begin(),a.end());
        int st = a[0].first;
        int end = a[0].second;
        for(int i=1;i<a.size();i++)
        {
            if(a[i].first <=end)
            {
                end = max(end,a[i].second);
            }
            else
            {
                ans.push_back(end-st+1);
                st = a[i].first;
                end = a[i].second;
            }
        }
        ans.push_back(end-st+1);
        return ans;
    }
};
