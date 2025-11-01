/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<TreeNode*> Search(TreeNode* root, int v){
        TreeNode* temp=root;
        vector<TreeNode*>x;
        while(temp){
            if(temp->val>v){
                x.push_back(temp);
                temp=temp->left;
            }
            else if(temp->val<v){
                x.push_back(temp);
                temp=temp->right;
            }
            else{
                x.push_back(temp);
                break;
            }
        }
        return x;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>v1=Search(root,p->val),v2=Search(root,q->val);
        if(v1.size()<=v2.size()){
            for(int i=v1.size()-1;i>-1;i--){
                if(v2[i]==v1[i]){
                    return v1[i];
                }
            }
        }
        else{
            for(int i=v2.size()-1;i>-1;i--){
                if(v2[i]==v1[i]){
                    return v1[i];
                }
            }
        }
        return nullptr;
    }
};