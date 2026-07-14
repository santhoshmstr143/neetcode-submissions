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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr) return true;
        if(p==nullptr || q==nullptr) return false;

        if(p->val==q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right))
        {
            return true;
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* sub) {
        if(root==nullptr && sub==nullptr) return true;
        if(root==nullptr && sub!=nullptr) return false;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* temp = st.top();
            st.pop();

            if(temp->val == sub->val && isSameTree(temp,sub))
            {
                return true;                
            }
            if(temp->right) st.push(temp->right);
            if(temp->left) st.push(temp->left);
        }
        return false;
    }
};
