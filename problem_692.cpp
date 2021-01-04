#include "util.h"

class Solution {
public:
	string Demo() {
		return "demo";
	}

	vector<string> topKFrequent(vector<string>& words, int k) {
		unordered_map<string, int> wordCntMap;
		for (auto& word : words) wordCntMap[word]++;
		vector<pair<string, int>> wordCntVec;
		wordCntVec.reserve(wordCntMap.size());
		for (auto& kv : wordCntMap) {
			wordCntVec.emplace_back(kv);
		}
		if (k > wordCntVec.size()) k = wordCntVec.size();

		partial_sort(wordCntVec.begin(), wordCntVec.begin()+k, wordCntVec.end(), [](const pair<string, int>& p1, const pair<string, int>& p2) {
			if (p1.second != p2.second) return p1.second > p2.second;
			return p1.first < p2.first;
		});

		vector<string> res;
		res.reserve(k);
		for (int i = 0; i < k; i++) {
			res.emplace_back(wordCntVec[i].first);
		}
		return res;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	{
		vector<string> words = {"a", "b", "a", "word"};
		auto res = solution.topKFrequent(words, 2);
		println(res);
	}
	return 0;
}
