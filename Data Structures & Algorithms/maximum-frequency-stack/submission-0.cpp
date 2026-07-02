class FreqStack {
public:
    unordered_map<int,int> fre;
    unordered_map<int,stack<int>> group;
    int mfreq;
    FreqStack() {
        mfreq = 0;
    }
    
    void push(int val) {
        fre[val]++;
        int f = fre[val];
        mfreq = max(f,mfreq);

        group[f].push(val);
    }
    
    int pop() {
        int val = group[mfreq].top();
        group[mfreq].pop();
        fre[val]--;
        if(group[mfreq].empty()) mfreq--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */