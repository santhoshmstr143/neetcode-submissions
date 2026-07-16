/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,root->val});
        while(!q.empty())
        {
            TreeNode * node = q.front().first;
            int mx = q.front().second;
            q.pop();
            if(mx <= node->val)
            {
                mx = node->val;
                cnt++;
            }
            if(node->right) q.push({node->right,mx});
            if(node->left) q.push({node->left,mx});
        }
        return cnt;
    }
};
