#include <unordered_map>

struct ListNode {
    int key;
    int val;
    ListNode *prev;
    ListNode *next;
    ListNode(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    std::unordered_map<int, ListNode*> mp;
    ListNode *head; // least recently used (LRU)
    ListNode *tail; // most recently used (MRU)
    int capacity;
    int sz;

    // Remove a node from the list (fix neighbours). Node must be non-null.
    void removeNode(ListNode *node) {
        if (!node) return;
        if (node->prev) node->prev->next = node->next;
        else head = node->next;            // node was head

        if (node->next) node->next->prev = node->prev;
        else tail = node->prev;           // node was tail

        node->prev = node->next = nullptr; // isolate
    }

    // Add node at tail (make it most recently used).
    void addToTail(ListNode *node) {
        node->next = nullptr;
        node->prev = tail;
        if (tail) tail->next = node;
        tail = node;
        if (!head) head = node;
    }

    // Move an existing node to tail (MRU).
    void moveToTail(ListNode *node) {
        if (node == tail) return; // already MRU
        removeNode(node);
        addToTail(node);
    }

    // Pop the head node (LRU) and return pointer (caller should delete and erase map).
    ListNode* popHead() {
        if (!head) return nullptr;
        ListNode *node = head;
        removeNode(node);
        return node;
    }

public:
    LRUCache(int cap) : mp(), head(nullptr), tail(nullptr), capacity(cap), sz(0) {
        if (capacity <= 0) capacity = 1;
        mp.reserve(static_cast<size_t>(capacity));
    }

    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) return -1;
        ListNode *node = it->second;
        moveToTail(node);
        return node->val;
    }

    void put(int key, int value) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            // update value and mark MRU
            ListNode *node = it->second;
            node->val = value;
            moveToTail(node);
            return;
        }

        // new node
        ListNode *node = new ListNode(key, value);
        mp[key] = node;
        addToTail(node);
        ++sz;

        if (sz > capacity) {
            ListNode *old = popHead();
            if (old) {
                mp.erase(old->key);
                delete old;
                --sz;
            }
        }
    }

    // destructor to free nodes
    ~LRUCache() {
        ListNode *cur = head;
        while (cur) {
            ListNode *n = cur->next;
            delete cur;
            cur = n;
        }
    }
};
