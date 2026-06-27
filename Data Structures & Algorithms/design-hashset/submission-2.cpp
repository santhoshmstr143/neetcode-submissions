class MyHashSet {
public:
    vector<vector<int>> table;
    MyHashSet() {
        table.resize(1001);
    }
    
    void add(int key) {
        int k = key%1000;
        if(find(table[k].begin(),table[k].end(),key)==table[k].end())
        {
            table[k].push_back(key);
        }
    }
    
    void remove(int key) {
        int k = key%1000;
        if(find(table[k].begin(),table[k].end(),key)!=table[k].end())
        {
            table[k].erase(table[k].begin()+key);
        }
    }
    
    bool contains(int key) {
        int k = key%1000;
        if(find(table[k].begin(),table[k].end(),key)!=table[k].end())
        {
            return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */