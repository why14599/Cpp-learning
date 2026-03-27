#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextTemp = curr->next; // 保存下一个节点
            curr->next = prev;               // 反转指针
            prev = curr;                     // 移动prev指针
            curr = nextTemp;                 // 移动到下一个节点
        }

        return prev; // prev指向新链表的头节点
    }
};


void printLinkedList(ListNode* head) {
    ListNode* cur = head;
    while (cur != nullptr) {
        cout << cur->val << " -> ";
        cur = cur->next;
    }
    cout << endl;
}

int main()
{
    ListNode* n3 = new ListNode(3);
    ListNode* n2b = new ListNode(2, n3);
    ListNode* n2a = new ListNode(2, n2b);
    ListNode* head = new ListNode(1, n2a);

    Solution sol;
    ListNode* result = sol.reverseList(head);
    return 0;
}