/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListCompare {
    bool operator()(ListNode* a, ListNode* b) const {
        return a->val > b->val; // min-heap: smallest val has highest priority
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        ListNode* newHead = nullptr;
        ListNode* p1 = nullptr;
        
        std::priority_queue<ListNode*, std::vector<ListNode*>, ListCompare> minHeap;

        for (auto list : lists) {
            if (list == nullptr) continue;
            minHeap.push(list);
        }

        while (minHeap.size() > 0) {
            ListNode* currNode = minHeap.top();
            minHeap.pop();
            if (newHead == nullptr) {
                newHead = currNode;
                p1 = currNode;
                currNode = currNode->next;
            }
            else {
                p1->next = currNode;
                currNode = currNode->next;
                p1 = p1->next;
            }
            if (currNode != nullptr) minHeap.push(currNode);

        }

        return newHead;
    }
};
