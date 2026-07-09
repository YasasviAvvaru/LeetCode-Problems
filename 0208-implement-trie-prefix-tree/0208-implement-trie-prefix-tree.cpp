struct Node{
    Node* links[26]={nullptr};
    bool flag=false;
    //
};

class Trie {
public:
    Node* root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* ptr=root;
        for(auto& x:word){
            if(ptr->links[x-'a']==nullptr){
                ptr->links[x-'a']= new Node();
            }
            ptr=ptr->links[x-'a'];
        }
        ptr->flag=true;
    }
    
    bool search(string word) {
        Node* ptr=root;
        for(auto& x:word){
            if(ptr->links[x-'a']==nullptr){
                return false;
            }
            ptr=ptr->links[x-'a'];
        }
        return ptr->flag;
    }
    
    bool startsWith(string word) {
        Node* ptr=root;
        for(auto& x:word){
            if(ptr->links[x-'a']==nullptr){
                return false;
            }
            ptr=ptr->links[x-'a'];
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