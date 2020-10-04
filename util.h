#include <iostream>
#include <stack>
#include <utility>
#include <string>
#include <vector>
#include <queue>

using namespace std;

template<class T>
void printVector(vector<T> v) {
    cout << "[";
	for (const auto& i : v) {
        cout << i << ", ";
    }   
    cout << "]" << endl;
}

