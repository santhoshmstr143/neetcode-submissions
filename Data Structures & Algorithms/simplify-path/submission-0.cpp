class Solution {
public:
    string simplifyPath(string s) {
        int n = s.size();
        stack<string> st;
        for(int i=0;i<n;)
        {
            while(i<n && s[i]=='/') i++;
            string cur;
            while(i<n && s[i]!='/')
            {
                cur +=s[i];
                i++;
            }
            if(cur=="" || cur==".") continue;
            if(cur=="..")
            {
                if(!st.empty()) st.pop();
            }
            else
            {
                st.push(cur);
            }
            
        }
        vector<string> temp;

        while(!st.empty())
        {
            temp.push_back(st.top());
            st.pop();
        }

        reverse(temp.begin(), temp.end());

        string ans;

        for(auto s : temp)
        {
            ans += "/";
            ans += s;
        }

        if(ans=="")
            return "/";

        return ans;
    }
};