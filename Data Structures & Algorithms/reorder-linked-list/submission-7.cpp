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

class Solution {
public:
    void reorderList(ListNode* head) {
        int n = 0;
        ListNode* nodePointer = head;
        std::vector<ListNode*> nodeList;

        while (nodePointer != nullptr) {
            ++n;
            nodeList.push_back(nodePointer);
            nodePointer = nodePointer->next;
        }
        
        nodePointer = head;
        int i = 0;
        for (int i = 1; i <= n / 2; ++i) {
            nodePointer->next = nodeList[n - i];
            nodePointer = nodePointer->next;
            if (n - i == i) {
                break;
            }
            nodePointer->next = nodeList[i];
            nodePointer = nodePointer->next;
        }
        nodePointer->next = nullptr;
        
    }
};
