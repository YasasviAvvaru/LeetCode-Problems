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
    int floorSearch(const vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= target) {
                ans = arr[mid];  // store value, not index
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    int ceilSearch(const vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= target) {
                ans = arr[mid];  // store value, not index
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    void inorder(TreeNode* node, vector<int>& v) {
        if (!node) return;
        inorder(node->left, v);
        v.push_back(node->val);
        inorder(node->right, v);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> v;
        inorder(root, v);
        vector<vector<int>> ans;
        for (int x : queries) {
            ans.push_back({floorSearch(v, x), ceilSearch(v, x)});
        }
        return ans;
    }
};
