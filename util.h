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

