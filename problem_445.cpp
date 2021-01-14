#include "util.h"

class Solution {
public:
	string Demo() {
		return "demo";
	}

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		stack<int> stk1;
		stack<int> stk2;
		for (auto head = l1; head != nullptr; head = head->next) stk1.push(head->val);
		for (auto head = l2; head != nullptr; head = head->next) stk2.push(head->val);

		ListNode *head = nullptr;
		int c = 0;
		while(!stk1.empty() || !stk2.empty() || c > 0) {
			if (!stk1.empty()) {
				c += stk1.top();
				stk1.pop();
			}
			if (!stk2.empty()) {
				c += stk2.top();
				stk2.pop();
			}
			ListNode *node = new ListNode(c%10);
			node->next = head;
			head = node;
			
			c = c/10;
		}

		return head;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	{
		ListNode* l1 = makeList({7, 2, 4, 3});
		ListNode* l2 = makeList({5, 6, 4});
		auto res = solution.addTwoNumbers(l1, l2);
		println(res);
	}

	return 0;
}
