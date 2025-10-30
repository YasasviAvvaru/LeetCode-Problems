/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int sz = q.size(); // Get the size of the *current* level
            
            for (int i = 0; i < sz; i++) {
                Node* temp = q.front();
                q.pop();
                
                // Link to the next node *in the queue* (which is on the same level)
                // If it's the last node of the level, q.front() will be from the *next* level,
                // so we only link if i < sz - 1.
                if (i == sz - 1) {
                    temp->next = NULL;
                } else {
                    temp->next = q.front();
                }
                
                // Add children to the *back* of the same queue for the *next* level
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        }
        return root;
    }
};