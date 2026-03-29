#include <iostream>
#include <vector>

using namespace std;

// 定义链表结构
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// --- 解决方案类 ---
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode* cur = dummyhead;
        
        while(cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* tmp = cur->next;              // 暂存节点1
            ListNode* tmp1 = cur->next->next->next; // 暂存节点3

            cur->next = cur->next->next;            // 指向节点2
            cur->next->next = tmp;                  // 节点2指向节点1
            cur->next->next->next = tmp1;           // 节点1指向节点3

            cur = cur->next->next; // 移动指针
        }
        
        ListNode* res = dummyhead->next;
        delete dummyhead; // 释放虚拟头节点
        return res;
    }
};

// --- 辅助函数：打印链表 ---
void printList(ListNode* head) {
    ListNode* cur = head;
    while (cur != nullptr) {
        cout << cur->val;
        if (cur->next != nullptr) cout << " -> ";
        cur = cur->next;
    }
    cout << endl;
}

// --- 辅助函数：构建链表 ---
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* cur = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        cur->next = new ListNode(vals[i]);
        cur = cur->next;
    }
    return head;
}

// --- 辅助函数：释放链表内存 ---
void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// --- 主函数：测试入口 ---
int main() {
    Solution sol;
    
    // 测试用例 1: 偶数个节点 [1, 2, 3, 4] -> [2, 1, 4, 3]
    cout << "Test Case 1: [1, 2, 3, 4]" << endl;
    ListNode* head1 = createList({1, 2, 3, 4});
    cout << "Original: ";
    printList(head1);
    ListNode* res1 = sol.swapPairs(head1);
    cout << "Swapped:  ";
    printList(res1);
    deleteList(res1); // 释放内存
    cout << "------------------------" << endl;

    // 测试用例 2: 奇数个节点 [1, 2, 3] -> [2, 1, 3]
    cout << "Test Case 2: [1, 2, 3]" << endl;
    ListNode* head2 = createList({1, 2, 3});
    cout << "Original: ";
    printList(head2);
    ListNode* res2 = sol.swapPairs(head2);
    cout << "Swapped:  ";
    printList(res2);
    deleteList(res2);
    cout << "------------------------" << endl;

    // 测试用例 3: 单个节点 [1] -> [1]
    cout << "Test Case 3: [1]" << endl;
    ListNode* head3 = createList({1});
    cout << "Original: ";
    printList(head3);
    ListNode* res3 = sol.swapPairs(head3);
    cout << "Swapped:  ";
    printList(res3);
    deleteList(res3);
    cout << "------------------------" << endl;

    // 测试用例 4: 空链表 [] -> []
    cout << "Test Case 4: []" << endl;
    ListNode* head4 = createList({});
    cout << "Original: ";
    printList(head4);
    ListNode* res4 = sol.swapPairs(head4);
    cout << "Swapped:  ";
    printList(res4);
    deleteList(res4);
    
    return 0;
}