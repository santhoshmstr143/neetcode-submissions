class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(auto ch : operations)
        {
            if(ch=="+")
            {
                int a = st.top();       
                st.pop();                 
                int b = st.top(); 
                st.push(a);
                st.push(a+b);
            }
            else if(ch=="D")
            {
                int t = st.top();
                st.push(2*t);
            }
            else if(ch=="C")
            {
                st.pop();
            }
            else
            {
                st.push(stoi(ch));
            }
        }
        int sum = 0;
        while(!st.empty())
        {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};