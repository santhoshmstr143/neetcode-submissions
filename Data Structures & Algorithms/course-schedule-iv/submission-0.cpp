class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& a, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto it : a)
        {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<unordered_set<int>> pre(n);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto it : adj[node])
            {
                pre[it].insert(node);
                for(auto x : pre[node]) pre[it].insert(x);

                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        vector<bool> ans;
        for(auto it : queries)
        {
            if(pre[it[1]].count(it[0]))
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }
        return ans;

    }
};