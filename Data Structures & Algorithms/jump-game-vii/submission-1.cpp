class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        int far = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            int i = q.front();
            q.pop();
            
            int low = max(far,i+minJump);
            int high = min(i+maxJump,n-1);
            for(int j = low ;j<=high ;j++)
            {
                if(s[j]=='0')
                {
                    if(j==n-1) return true;
                    q.push(j);
                }
            }
            far = max(far,high+1);
        }
        return n==1;
    }
};