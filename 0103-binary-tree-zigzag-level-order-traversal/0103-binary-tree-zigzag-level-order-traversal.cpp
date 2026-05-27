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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        bool state=true;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>v;
            for(int i=0;i<n;i++){
                auto x=q.front();
                q.pop();
                v.push_back(x->val);
                if(x->left)q.push(x->left);
                if(x->right)q.push(x->right);
            }
            if(state){
                state=false;
            }
            else{
                reverse(v.begin(),v.end());
                state=true;
            }
            ans.push_back(v);
        }
        return ans;
    }
};