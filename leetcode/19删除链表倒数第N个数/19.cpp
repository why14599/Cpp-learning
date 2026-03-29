class Solution {
public:
    ListNode* removeNthFromEnd1(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // 计算长度
        ListNode* temp = head;
        int length = 0;
        while(temp != nullptr) {
            temp = temp->next;
            length++;
        }
        
        ListNode* cur = dummy;
        int steps = length - n;
        
        while(steps--) {
            cur = cur->next;
        }
        
        ListNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }

ListNode* removeNthFromEnd2(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        // fast 先走 n+1 步
        // 注意这里是 n+1，因为我们要让 slow 停在待删除节点的前一个
        for(int i = 0; i <= n; i++) {
            fast = fast->next;
        }
        
        // fast 和 slow 同时走，直到 fast 为空
        while(fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // 此时 slow 指向待删除节点的前一个节点
        ListNode* tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
        
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};