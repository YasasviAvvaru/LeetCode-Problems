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
    void dfs1(TreeNode* root,unordered_map<TreeNode*,bool>& mp1,unordered_map<TreeNode*,int>& mp2,unordered_map<TreeNode*,int>& mp3){
        if(!root){mp1[root]=true;return;}
        dfs1(root->left,mp1,mp2,mp3);
        dfs1(root->right,mp1,mp2,mp3);

        mp1[root]=mp1[root->left] and mp1[root->right] and (root->val>mp2[root->left]) and(root->val<mp3[root->right]);
    }
    
    void dfs(TreeNode* root,unordered_map<TreeNode*,int>& mp,unordered_map<TreeNode*,bool>& mp1,int& ans){
        if(!root){mp[root]=0;return ;}
        dfs(root->left,mp,mp1,ans);
        dfs(root->right,mp,mp1,ans);
        mp[root]=root->val;
        mp[root]+=mp[root->left];
        mp[root]+=mp[root->right];
        if(mp1[root->left])ans=max(mp[root->left],ans);
        if(mp1[root->right])ans=max(ans,mp[root->right]);
        if(mp1[root])ans=max(ans,mp[root]);
    }
    void dfs_max(TreeNode* root,unordered_map<TreeNode*,int>& mp2){
        if(!root){mp2[root]=INT_MIN;return;}
        dfs_max(root->left,mp2);
        dfs_max(root->right,mp2);
        mp2[root]=max(root->val,mp2[root->left]);
        mp2[root]=max(mp2[root],mp2[root->right]);
    }
    void dfs_min(TreeNode* root,unordered_map<TreeNode*,int>& mp2){
        if(!root){mp2[root]=INT_MAX;return;}
        dfs_min(root->left,mp2);
        dfs_min(root->right,mp2);
        mp2[root]=min(root->val,mp2[root->left]);
        mp2[root]=min(mp2[root],mp2[root->right]);
    }
    int maxSumBST(TreeNode* root) {
        int ans=0;
        unordered_map<TreeNode*,int>mp;
        unordered_map<TreeNode*,int>mp2;
        unordered_map<TreeNode*,int>mp3;
        unordered_map<TreeNode*,bool>mp1;
        dfs_max(root,mp2);
        dfs_min(root,mp3);
        dfs1(root,mp1,mp2,mp3);
        dfs(root,mp,mp1,ans);
        
        return ans;
    }
};