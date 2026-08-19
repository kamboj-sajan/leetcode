// Last updated: 19/08/2026, 16:01:15
struct Node{
    int key, value, cnt;
    Node* prev;
    Node* next;
    Node(int _key,int _value){
        key = _key;
        value = _value;
        cnt = 1;
    }
};
struct List{
    int size;
    Node* head;
    Node* tail;
    List(){
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void addFront(Node* node){
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        temp->prev = node;
        head->next = node;
        size++;
    }
    void removeNode(Node* delnode){
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};
class LFUCache {
    map<int,Node*> keynode;
    map<int,List*> freqListmap;
    int maxSizeCache;
    int minFreq;
    int curSize;
public:
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }
    void updateFreqListMap(Node* node){
        keynode.erase(node->key);
        freqListmap[node->cnt]->removeNode(node);
        if(node->cnt == minFreq && freqListmap[node->cnt]->size == 0){
            minFreq++;
        }
        List* nexthigherlist = new List();
        if(freqListmap.find(node->cnt+1) != freqListmap.end()){
            nexthigherlist = freqListmap[node->cnt+1];
        }
        node->cnt += 1;
        nexthigherlist->addFront(node);
        freqListmap[node->cnt] = nexthigherlist;
        keynode[node->key] = node;
    }
    
    int get(int key) {
        if(keynode.find(key) != keynode.end()){
            Node* node = keynode[key];
            int val = node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxSizeCache == 0){
            return;
        }
        if(keynode.find(key) != keynode.end()){
            Node* node = keynode[key];
            node->value = value;
            updateFreqListMap(node);
        }else{
            if(curSize == maxSizeCache){
                List* list = freqListmap[minFreq];
                keynode.erase(list->tail->prev->key);
                freqListmap[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }
            curSize++;
            //new value is to be added who is not there previously
            minFreq = 1;
            List* listfreq = new List();
            if(freqListmap.find(minFreq) != freqListmap.end()){
                listfreq = freqListmap[minFreq];
            }
            Node* node = new Node(key,value);
            listfreq->addFront(node);
            keynode[key] = node;
            freqListmap[minFreq] = listfreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */