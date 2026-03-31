class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* cur = headA;
        int aLen = 0;
        while(cur != NULL){
            cur = cur->next;
            aLen++;
        }
        int bLen = 0;
        cur = headB;
        while(cur != NULL){
            cur = cur->next;
            bLen++;
        }
        int dLen = (aLen>bLen)?aLen-bLen:bLen-aLen;
        cur = (aLen>bLen)?headA:headB;
        while(dLen--){
            cur= cur->next;
        }
        ListNode* cur1 = (aLen>bLen)?headB:headA;
        while(cur1 != NULL){
            if(cur == cur1){
                return cur;
            }
            cur = cur->next;
            cur1 = cur1->next;
        }
        return NULL;
    }
};