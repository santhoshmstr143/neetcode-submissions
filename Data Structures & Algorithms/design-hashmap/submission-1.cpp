class MyHashMap {
public:
    vector<vector<pair<int,int>>> mp;
    MyHashMap() {
        mp.resize(1000);
    }
    
    void put(int key, int value) {
        int k = key%1000;
        for(auto &p : mp[k])
        {
            if(p.first == key)
            {
                p.second = value;
                return;
            }
        }
        mp[k].push_back({key,value});
    }
    
    int get(int key) {
        int k = key%1000;
        for(auto &p : mp[k])
        {
            if(p.first == key)
                return p.second;
        }

        return -1;
    }
    
    void remove(int key) {
        int k = key % 1000;
        for(auto it = mp[k].begin(); it != mp[k].end(); it++)
        {
            if(it->first == key)
            {
                mp[k].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */