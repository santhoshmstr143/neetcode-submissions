class Solution {
public:
    bool iscommand(string &s)
    {
        if(s=="+" || s=="-" || s=="*" || s=="/") return true;
        return false;
    }
    int solve(int a,int b,string &s)
    {
        if(s=="+") return a+b;
        else if(s=="-") return a-b;
        else if(s=="*") return a*b;
        else return a/b;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto s : tokens)
        {
            if(iscommand(s))
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(solve(b,a,s));
            }
            else
            {
                int t = stoi(s);
                st.push(t);
            }
        }
        return st.top();
    }
};
