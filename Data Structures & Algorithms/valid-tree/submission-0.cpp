class Solution {
public:
    bool dfs(int node,vector<vector<int>> & adj, vector<int> &vis,int p)
    {
        vis[node]=1;
        for(auto it : adj[node])
        {
            if(!vis[it]) 
            {
                if(dfs(it,adj,vis,node)) return true;
            }
            else if(it!=p)
            {
                return true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                cnt++;
                if(dfs(i,adj,vis,-1)) return false;
            }
        }
        return cnt==1;        
    }
};
