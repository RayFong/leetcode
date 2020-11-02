#include "util.h"

class Solution {
public:
	string Demo() {
		return "demo";
	}

	ListNode* swapPairs(ListNode* head) {
		ListNode* superHead = new ListNode(0, head);
		auto prev = superHead;
		while(prev->next != nullptr && prev->next->next != nullptr) {
			auto p1 = prev->next;
			auto p2 = p1->next;

			prev->next = p2;
			p1->next = p2->next;
			p2->next = p1;
			prev = p1;
		}
		auto ret = superHead->next;
		superHead->next = nullptr;
		delete superHead;
		return ret;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	auto res1 = solution.swapPairs(makeLinkList({}));
	println(res1);
	
	auto res2 = solution.swapPairs(makeLinkList({1}));
	println(res2);
	
	auto res3 = solution.swapPairs(makeLinkList({1, 2, 3, 4, 5}));
	println(res3);
	
	return 0;
}
