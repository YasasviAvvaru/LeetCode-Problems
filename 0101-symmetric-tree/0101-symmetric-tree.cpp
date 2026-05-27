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
    bool fxn(TreeNode* l,TreeNode* r){
        if(!l and !r)return true;
        if((!l and r)or(!r and l))return false;
        return fxn(l->left,r->right)&&fxn(l->right,r->left)&&(l->val==r->val);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        auto l=root->left,r=root->right;
        return fxn(l,r);
    }
};