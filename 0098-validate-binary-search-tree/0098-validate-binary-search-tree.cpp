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
    bool dfs(TreeNode* root,long long low,long long high){
        if(!root)return true;
        if((long long)root->val<=low or (long long)root->val>=high)return false;
        return dfs(root->left,low,(long long)root->val) and dfs(root->right,root->val,(long long)high);
    }
    bool isValidBST(TreeNode* root) {
        
        return dfs(root,LLONG_MIN,LLONG_MAX);
    }
};