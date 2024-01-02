#include <iostream>
using namespace std;
struct Node {
    Node(int v=0) : val(v), next(nullptr), pre(nullptr){}
    int val;
    Node *next, *pre;
};
class MyLinkedList {
private:
    Node *dummy;
public:
    int cnt;
    MyLinkedList() {
        dummy = new Node(-1);
        cnt = 0;
    }
    ~MyLinkedList() {
        Node *cur = dummy;
        while (cur) {
            Node *next =  cur->next;
            delete cur;
            cur = next;
        }
    }
    
    int get(int index) {
        if (index >= cnt || index < 0) return -1;
        Node *pre = dummy;
        Node *cur = pre->next;
        while (index--) {
            pre = cur;
            cur = cur->next;
        }
        return cur->val;

    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(cnt, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index > cnt || index < 0) return;
        Node *pre = dummy;
        Node *cur = pre->next;
        while(index--) {
            pre = cur;
            cur = cur->next;
        }

        // pre <-> newNode <--> cur 
        Node *newNode = new Node(val);
        pre->next = newNode;
        newNode->pre = pre;
        newNode->next = cur;
        if (cur) {
            cur->pre = newNode;
        }
        cnt++;
    }
    
    void deleteAtIndex(int index) {
        if (index >= cnt || index < 0) return;
        Node *pre = dummy;
        Node *cur = pre->next;
        while (index--) {
            pre = cur;
            cur = cur->next;
        }

        // pre <--> cur <--> nextNode
        Node *nextNode = cur->next;
        pre->next = nextNode;
        if (nextNode) {
            nextNode->pre = pre;
        }
        delete cur;
        cnt--;
    }
};

int main() {
    MyLinkedList list;
    int in, pos;
    while(cin >> pos >> in) {
        list.addAtIndex(pos, in);
        
        for(int i = 0; i < list.cnt; i++) {
            cout << list.get(i) << "\t";
        }
        cout << endl;
    }
    

}
