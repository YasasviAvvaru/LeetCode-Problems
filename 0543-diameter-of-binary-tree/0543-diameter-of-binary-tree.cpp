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
    int ht(TreeNode* root) {
        if(!root)return 0;
        int h1=ht(root->left),h2=ht(root->right);
        return 1+max(h1,h2);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        int ans=max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right));
        ans=max(ans,ht(root->left)+ht(root->right));
        return ans;
    }
};