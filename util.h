#include <iostream>
#include <stack>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

template<class T>
void print(T t) {
	std::cout << t;
}

void print(string t) {
	std::cout << t;
}

template<typename KeyType, typename ValueType>
void print(std::pair<KeyType, ValueType> kv)
{
	print(kv.first);
	print("=");
	print(kv.second);
}

template<typename T, typename AllocT, template<typename, typename...> typename SequenceT>
void print(SequenceT<T, AllocT> seq)
{
	print("{");
	for (auto iter = std::begin(seq); iter != std::end(seq); iter = std::next(iter)) {
		print(*iter);
		print(", ");
	}
	print("\b\b}");
}

template<typename T>
void println(T t) {
	print(t);
	std::cout << std::endl;
}

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


// ====================== 树相关 ======================

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

int countTreeHeight(TreeNode* root) {
	if (root == nullptr) {
		return 0;
	}

	return max(countTreeHeight(root->left), countTreeHeight(root->right)) + 1;
}

int countTreeNodeNum(TreeNode* root) {
	if (root == nullptr) {
		return 0;
	}

	return countTreeNodeNum(root->left) + countTreeNodeNum(root->right) + 1;
}

vector<TreeNode*> flatTreeNode(TreeNode* root) {
	vector<TreeNode*> res;
	res.push_back(root);
	size_t s = 0;
	while(s < res.size()) {
		size_t e = res.size();
		while(s < e) {
			if (res[s] == nullptr) continue;
			res.push_back(res[s]->left);
			res.push_back(res[s]->right);
			s++;
		}
	}
	return res;
}

void printTree(TreeNode* root) {
	auto nodes = flatTreeNode(root);
	cout << "[";
	for (auto node : nodes) {
		if (node == nullptr) {
			cout << "null, ";
		} else {
			cout << node->val << ", ";
		}
	}
	cout << "]";
}

// ====================================================
