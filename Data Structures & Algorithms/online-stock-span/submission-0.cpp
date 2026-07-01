class StockSpanner {
public:
    vector<int> ans;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cnt = 1;
        int n = ans.size();
        for(int i=n-1;i>=0;i--)
        {
            if(ans[i]<=price) cnt++;
            else break;
        }
        ans.push_back(price);
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */