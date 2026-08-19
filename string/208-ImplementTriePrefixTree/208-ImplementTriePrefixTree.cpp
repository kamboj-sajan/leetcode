// Last updated: 19/08/2026, 16:05:00
struct Node{
    Node* links[26];
    bool flag = false;
    bool containKey(char ch){
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    Node* get(char ch){
        return links[ch - 'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie {
private: Node* root;
public:
    Trie() {
       root = new Node(); 
    }
    //tc = O(len)
    void insert(string word) {
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->containKey(word[i])){
                node->put(word[i],new Node());
            }
            // move to reference trie
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    // tc = O(len)
    bool search(string word) {
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->containKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    //O(len)
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0; i<prefix.length(); i++){
            if(!node->containKey(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
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