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
    vector<int> preorderTraversal(TreeNode* root) {
        //This is RECURSIVE
        // if(root==NULL)return {};
        // vector<int> v={root->val},v1=preorderTraversal(root->left),v2=preorderTraversal(root->right);
        // for(auto& x:v1)v.push_back(x);
        // for(auto& x:v2)v.push_back(x);
        // return v;

        //ITERATIVE version
        if(!root)return {};
        vector<int>v;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            auto x=st.top();
            v.push_back(x->val);
            st.pop();
            if(x->right)st.push(x->right);
            if(x->left)st.push(x->left);
        }
        return v;
    }
};