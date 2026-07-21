class Solution {
public:
    double dfs(string node,string dest,unordered_map<string,vector<pair<string,double>>> &adj,
               unordered_map<string,int> &vis,double val)
    {
        if(node==dest)
        {
            return val;
        }

        vis[node]=1;

        for(auto it : adj[node])
        {
            if(!vis[it.first])
            {
                double ans = dfs(it.first,dest,adj,vis,val*it.second);

                if(ans!=-1.0)
                {
                    return ans;
                }
            }
        }

        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& value, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> adj;
        for(int i=0;i<equations.size();i++)
        {
            string u = equations[i][0];
            string v = equations[i][1];
            adj[u].push_back({v,value[i]});
            adj[v].push_back({u,1.0/value[i]});
        }
        vector<double> ans;
        for(auto it : queries)
        {
            string u = it[0];
            string v = it[1];
            if(adj.find(u)==adj.end() || adj.find(v)==adj.end())
            {
                ans.push_back(-1.0);
                continue;
            }
            unordered_map<string,int> vis;
            ans.push_back(dfs(u,v,adj,vis,1.0));
        }
        return ans;
    }
};