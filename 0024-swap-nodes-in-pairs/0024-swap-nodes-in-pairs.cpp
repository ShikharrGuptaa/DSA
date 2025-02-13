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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* curr = head;
        ListNode* nxt = head->next;
        ListNode* prev = NULL;

        while(curr && nxt){
            
            curr->next = nxt->next;
            nxt->next = curr;
            if(prev) prev->next = nxt;
            
            if(curr == head) head = nxt;
            prev = curr;

            curr = curr->next;
            if(!curr) return head;
            nxt = curr->next;
        }

        return head;
    }
};