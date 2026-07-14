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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp = new TreeNode(val);
        if(root==nullptr) return temp;
        TreeNode *c = root;
        while(c)
        {
            if(val < c->val)
            {
                if(c->left == nullptr)
                {
                    c->left = temp;
                    break;
                }
                else
                {
                    c = c->left;
                }
            }
            else
            {
                if(!c->right)
                {
                    c->right = temp;
                    break;
                }
                else
                {
                    c = c->right;
                }
            }
        }
        return root;
    }
};