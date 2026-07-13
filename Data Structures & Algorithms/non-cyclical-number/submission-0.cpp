class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> vis;
        while(true)
        {
            if(vis.count(n)) return false;
            vis.insert(n);
            int sum = 0;
            while(n)
            {
                int r = n%10;
                n /=10;
                sum += r*r;
            }
            if(sum==1) return true;
            n = sum;
        }
        return true;
    }
};
