#include <iostream>
#include <stack>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

template<class T>
void printVector(vector<T> v) {
    cout << "[";
	for (const auto& i : v) {
        cout << i << ", ";
    }   
    cout << "]" << endl;
}

// ============  链表相关 =============

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* head) {
    if (head == nullptr) {
        std::cout << "list is null";
    }   
    while(head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }   
    std::cout << std::endl;
}

ListNode* makeLinkList(vector<int> vals) {
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    for(auto v : vals) {
        if (head == nullptr) {
            head = new ListNode(v);
            tail = head;
        } else {
            tail->next = new ListNode(v);
            tail = tail->next;
        }   
    }   
    return head;
}

// ======================================
