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
        if(!root)return NULL;
        queue<Node*>q;
        q.push(root);
        Node* temp;
        int sz=0;
        while(!q.empty()){
            sz=q.size();
            queue<Node*>q1;
            for(int i=0;i<sz;i++){
            temp=q.front();
            q.pop();
            q.empty()?temp->next=NULL:temp->next=q.front();
            if(temp->left)q1.push(temp->left);
            if(temp->right)q1.push(temp->right);
            }
            while(!q1.empty()){
                q.push(q1.front());
                q1.pop();
            }
        }
        return root;
    }
};