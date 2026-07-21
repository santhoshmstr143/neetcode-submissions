class disjointset {
public:
    vector<int> parent,size;
    disjointset(int n)
    {
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int find(int node)
    {
        if(parent[node]==node)
        {
            return node;
        }
        return parent[node]=find(parent[node]);
    }
    void unite(int u,int v)
    {
        int pu = find(u);
        int pv = find(v);
        if(pu==pv) return;
        if(size[pu]<size[pv])
        {
            parent[pu] = pv;
            size[pv]+= size[pu];
        }
        else
        {
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        disjointset d(n);
        unordered_map<string,int> mp;

        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                if(mp.find(accounts[i][j])==mp.end())
                {
                    mp[accounts[i][j]] = i;
                }
                else
                {
                    d.unite(i,mp[accounts[i][j]]);
                }
            }
        }

        vector<vector<string>> merge(n);
        for(auto it : mp)
        {
            string mail = it.first;
            int acc = it.second;
            int leader = d.find(acc);
            merge[leader].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++)
        {
            if(merge[i].size()==0) continue;

            sort(merge[i].begin(),merge[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : merge[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};