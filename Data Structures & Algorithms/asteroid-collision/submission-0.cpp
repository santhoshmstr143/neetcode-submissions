class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto it : asteroids)
        {
            int d = 0;
            while(!st.empty() && st.top()>0 && it<0)
            {
                if(st.top()<abs(it))
                {
                    st.pop();
                }
                else if(st.top()==abs(it))
                {
                    st.pop();
                    d=1;
                    break;
                }
                else
                {
                    d=1;
                    break;
                }
            }
            if(d) continue;
            st.push(it);
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};