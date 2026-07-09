class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {

        int n = s.size();

        queue<int> q;
        q.push(0);

        int far = 0;

        while(!q.empty())
        {
            int i = q.front();
            q.pop();

            int l = max(i + minJump, far);
            int r = min(i + maxJump, n - 1);

            for(int j = l; j <= r; j++)
            {
                if(s[j] == '0')
                {
                    if(j == n - 1)
                        return true;

                    q.push(j);
                }
            }

            far = max(far, r + 1);
        }

        return n == 1;
    }
};