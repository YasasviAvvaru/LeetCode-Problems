struct Node {
    Node* links[26] = {nullptr}; 
    bool flag = false; 
    
    // Encapsulate raw array accesses
    bool containsKey(char ch) { return links[ch - 'a'] != nullptr; }
    void put(char ch, Node* node) { links[ch - 'a'] = node; }
    Node* get(char ch) { return links[ch - 'a']; }
    void setEnd() { flag = true; }
    bool isEnd() { return flag; }
};
class Trie {
public:
    Node* root;
    Trie() {
        root =new Node();
    }
    
    void insert(string word) {
        Node* ptr=root;
        for(auto& x:word){
            if(!ptr->containsKey(x)){
                ptr->put(x,new Node());
            }
            ptr=ptr->get(x);
        }
        ptr->setEnd();
    }
    
    bool search(string word) {
        Node* ptr=root;
        for(auto& x:word){
            if(!ptr->containsKey(x))return false;
            ptr=ptr->get(x);
        }
        return (ptr->isEnd());
    }
    
    bool startsWith(string prefix) {
        Node* ptr=root;
        for(auto& x:prefix){
            if(!ptr->containsKey(x))return false;
            ptr=ptr->get(x);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */