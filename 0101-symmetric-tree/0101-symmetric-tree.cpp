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
    bool isSym(TreeNode* n1,TreeNode* n2){
        if(!n1 and !n2)return true;
        if((!n1 and n2)or(!n2 and n1))return false;
        if(n1->val==n2->val){
            return isSym(n1->left,n2->right)&isSym(n1->right,n2->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root)return isSym(root->left,root->right);
        else return true;
    }
};