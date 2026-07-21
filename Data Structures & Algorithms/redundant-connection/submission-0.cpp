class Disjointset {
public:
    vector<int> parent,size;
    Disjointset(int n)
    {
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=1;i<=n;i++) parent[i]=i;
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        Disjointset d(n);

        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            if(d.find(u)==d.find(v)) return it;
            d.unite(u,v);
        }
        return {};
    }
};