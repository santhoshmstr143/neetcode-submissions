class Solution {
public:
    bool dfs(int node,vector<vector<int>>&adj,vector<int> &vis,vector<int>&pvis)
    {
        vis[node]=1;
        pvis[node]=1;
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,adj,vis,pvis)) return true;
            }
            else if(pvis[it])
            {
                return true;
            }
        }
        pvis[node]=0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& a) {
        vector<vector<int>> adj(n);
        for(auto it : a)
        {
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        vector<int> pvis(n,0);

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,adj,vis,pvis)) return false;
            }
        }
        return true;
    }
};
