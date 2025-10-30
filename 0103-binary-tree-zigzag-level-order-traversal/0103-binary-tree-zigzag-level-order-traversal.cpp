#include <vector>
#include <queue>
#include <algorithm> // Needed for std::reverse

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        // This flag tracks which direction the *output* should be
        bool leftToRight = true; 

        while (!q.empty()) {
            int sz = q.size();
            vector<int> level;
            
            // This for-loop is standard BFS. It *always*
            // processes nodes left-to-right.
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                level.push_back(node->val);
                
                // And it *always* enqueues children left, then right.
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // --- This is the "zigzag" part ---
            // If the flag says we should be R-L, reverse the level vector.
            if (!leftToRight) {
                reverse(level.begin(), level.end());
            }

            // Add the (possibly reversed) level to the answer
            ans.push_back(level);
            
            // Flip the flag for the next level
            leftToRight = !leftToRight;
        }

        return ans;
    }
};