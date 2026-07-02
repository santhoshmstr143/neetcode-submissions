class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> psi(n,-1);
        vector<int> nsi(n,n);
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                psi[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                nsi[i]=st.top();
            }
            st.push(i);
        }
        int ans = 0;
        for(int i =0;i<n;i++)
        {
            int wid = nsi[i]-psi[i]-1;
            ans = max(ans,wid*heights[i]);
        }
        return ans;
    }
};