class MyLinkedList {
public:
struct linkednode{
    int val;
    linkednode* next;
    linkednode(int val):val(val), next(nullptr){}
};
    MyLinkedList() {
        _dummyhead = new linkednode(0);
        _size = 0;
    }
    
    int get(int index) {
        if(index<0 || index>(_size-1)){
            return -1;
        }
        linkednode* cur = _dummyhead->next;
        while(index--){
            cur = cur->next;
        }
        return cur->val;

    }
    
    void addAtHead(int val) {
        linkednode* cur = new linkednode(val);
        cur->next = _dummyhead->next;
        _dummyhead->next = cur;
        _size++;
    }
    
    void addAtTail(int val) {
        linkednode* newNode = new linkednode(val);
        linkednode* cur = _dummyhead;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>_size)return;
        if(index<0){
            addAtHead(val);
            return;
        }
        linkednode* newNode = new linkednode(val);
        linkednode* cur = _dummyhead;
        while(index--){
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>(_size-1))return;
        linkednode* cur = _dummyhead;
        while(index--){
            cur = cur->next;
        }
        linkednode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        _size--;
    }
    private:
    int _size;
    linkednode* _dummyhead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */