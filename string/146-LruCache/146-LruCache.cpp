// Last updated: 19/08/2026, 16:06:57
class LRUCache {
public:
     class node {
      public:
        int key;
      int val;
      node* next;
      node* prev;
      node(int _key, int _val) {
        key = _key;
        val = _val;
      }
    };
     node * head = new node(-1, -1);
  node * tail = new node(-1, -1);

  int cap;
  unordered_map <int, node*> m;
    void deleteNode(node* delnode){
        node* prevnode = delnode->prev;
        node* afternode = delnode->next;
        prevnode->next = afternode;
        afternode->prev = prevnode;
    }
    void insertafterhead(node* newnode){
        node* curAfterhead = head->next;
        head->next = newnode;
        newnode->next = curAfterhead;
        newnode->prev = head;
        curAfterhead->prev = newnode;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        m.clear();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key) == m.end())return -1;
        node* temp = m[key];
        deleteNode(temp);
        insertafterhead(temp);
        return temp->val;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            node* temp = m[key];
            temp->val = value;
            deleteNode(temp);
            insertafterhead(temp);
        }else{
            if(m.size() == cap){
                node* temp = tail->prev;
                m.erase(temp->key);
                deleteNode(temp);
                delete(temp);
            }
                node* temp = new node(key,value);
                m[key] = temp;
                insertafterhead(temp);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */