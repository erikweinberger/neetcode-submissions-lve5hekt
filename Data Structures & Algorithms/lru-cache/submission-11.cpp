
struct ListNode {
    int key;
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode(int x, int y) : val(x), key(y), next(nullptr), prev(nullptr) {}
};

class LRUCache {
    std::unordered_map<int, ListNode *> keyMap;
    ListNode *head;
    ListNode *tail;
    int size;
    int capacity;
public:
    LRUCache(int cap) : keyMap(), head(nullptr), tail(nullptr), size(0), capacity(cap) {
        keyMap.reserve(static_cast<size_t>(capacity));
    }
    
    int get(int key) {
        auto keyNode = keyMap.find(key);
        if (keyNode == keyMap.end()) return -1;
        rePrioritiseKey(keyNode->second);
        return keyNode->second->val;
    }
    
    void put(int key, int value) {
        auto keyNode = keyMap.find(key);
        if (keyNode != keyMap.end()) {
            keyNode->second->val = value;
            rePrioritiseKey(keyNode->second);
        }
        else {
            ListNode *newNode = new ListNode(value, key);
            keyMap[key] = newNode;
            if (tail == nullptr) {
                tail = newNode;
                head = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            size++;
        }

        if (size > capacity) {
            deleteLeastRelevant();
        }
    }

    void deleteLeastRelevant() {
        ListNode *nodeToDelete = head;
        if (head->next != nullptr) {
            head = head->next;
            head->prev = nullptr;
        }
        else {
            head = nullptr;
        }
        keyMap.erase(nodeToDelete->key);
        delete nodeToDelete;
        size--;
    }

    void rePrioritiseKey(ListNode *update) {
        if (update->next == nullptr) {
            return;
        }
        if (update->prev == nullptr) {
            head = update->next;
            update->next->prev = nullptr;
            tail->next = update;
            update->prev = tail;
            tail = update;
            update->next = nullptr;
        } 
        else {
            ListNode *prev = update->prev;
            ListNode *next = update->next;
            prev->next = next;
            next->prev = prev;
            tail->next = update;
            update->prev = tail;
            tail = update;
            update->next = nullptr;
        }
        if (head == nullptr) return;
        ListNode *p1 = head;
    }
};
