class LRUCache {
public:
    int cap;
    int count = 0;
    int dict[10005]={-1};
    struct Node{
        int id;
        Node* next = nullptr;
        Node* pre = nullptr;
    }nodes[10005];
    Node* head = new Node;
    Node* tail = new Node;
    void add(int key)
    {
        if(dict[key] != -1)
        {
            Node* cur = &nodes[key];
            cur->pre->next = cur->next;
            cur->next->pre = cur->pre;
        }
        Node* last = tail->pre;
        last->next = &nodes[key];
        tail->pre = &nodes[key];
        nodes[key].next = tail;
        nodes[key].pre = last;
    }

    void del()
    {
        Node* f = head->next;
        int del_id = f->id;
        head->next = f->next;
        f->next->pre = head;
        count -= 1;
        // cout<<"del: "<<del_id<<' '<<dict[del_id]<<endl;
        dict[del_id] = -1;
        // walk();
    }

    void walk()
    {
        Node* cur = tail->pre;
        while(cur->pre != nullptr)
        {
            cout<<cur->id<<' '<<dict[cur->id]<<endl;
            cur = cur->pre;
        }
    }

    LRUCache(int capacity) {
        cap = capacity;
        for(int i=0;i<10005;i++)
        {
            nodes[i].id = i;
            dict[i] = -1;
        }
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if(dict[key] != -1) add(key);
        return dict[key];
    }
    
    void put(int key, int value) {
        if(dict[key] == -1) count += 1;
        if(count > cap) del();
        add(key);
        dict[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */