class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(),deadends.end());
        if(dead.find("0000")!=dead.end()) return -1;
        queue<string> q;
        unordered_set<string> vis;
        q.push("0000");
        vis.insert("0000");
        int dis = 0;

        while(!q.empty())
        {
            int l = q.size();
            while(l--)
            {
                string c = q.front();
                q.pop();

                if(c==target) return dis;

                for(int i=0;i<4;i++)
                {
                    string nxt = c;
                    nxt[i] = (c[i]=='9')? '0' : c[i]+1;
                    if(dead.find(nxt)==dead.end() && vis.find(nxt)==vis.end())
                    {
                        vis.insert(nxt);
                        q.push(nxt);
                    }

                    nxt = c;
                    nxt[i] = (c[i]=='0')? '9' : c[i]-1;
                    if(dead.find(nxt)==dead.end() && vis.find(nxt)==vis.end())
                    {
                        vis.insert(nxt);
                        q.push(nxt);
                    }
                }
            }
            dis++;
        }
        return -1;

    }
};