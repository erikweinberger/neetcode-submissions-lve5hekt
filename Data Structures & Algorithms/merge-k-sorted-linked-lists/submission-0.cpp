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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        ListNode* newHead = lists[0];

        for (int i = 1; i < lists.size(); ++i) {
            ListNode* p1 = newHead;
            ListNode* p2 = lists[i];
            if (p1 == nullptr) {
                newHead == p2;
                continue;
            }
            if (p2 == nullptr) {
                continue;
            }
            ListNode* iterationResult = nullptr;
            ListNode* currNode = nullptr;
            while (p1 != nullptr && p2 != nullptr) {
                if (p1->val <= p2->val) {
                    if (currNode == nullptr) {
                        iterationResult = p1;
                        currNode = p1;
                        p1 = p1->next;
                    } 
                    else {
                        currNode->next = p1;
                        currNode = currNode->next;
                        p1 = p1->next;
                    }
                }
                else {
                    if (currNode == nullptr) {
                        iterationResult = p2;
                        currNode = p2;
                        p2 = p2->next;
                    } 
                    else {
                        currNode->next = p2;
                        currNode = currNode->next;
                        p2 = p2->next;
                    }
                }
            }
            std::cerr << "finished loop" << '\n';
            if (p1 != nullptr) {
                currNode->next = p1;
            }
            if (p2 != nullptr) {
                currNode->next = p2;
            }
            newHead = iterationResult;
        }

        return newHead;
    }
};
