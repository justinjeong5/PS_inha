/*
 *  2020.4.1.
 *  INHA_problem_solving 4-2
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <utility>

using namespace std;
int test_case_amount, input_siz = 0;
int answer = 0, temp;
const int VISITED = -1;
const int UNDISCOVERED = 1;

vector<int> nums;
unordered_map<int, int> um;

void print_answer() {
    cout << answer << '\n';
}

void solution() {
    for (int idx = 0; idx < input_siz; ++idx) {
        if (!um.count(nums[idx] + 1)) {
            um[nums[idx]] = UNDISCOVERED;
            answer++;
            continue;
        }
        um[nums[idx]] = VISITED;
    }
    print_answer();
}

void preprocess() {
    nums.resize(input_siz, 0);
    answer = 0;
    um.clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> test_case_amount;
    while (test_case_amount-- != 0) {
        cin >> input_siz;
        preprocess();

        for (int input_index = 0; input_index < input_siz; ++input_index) {
            cin >> nums[input_index];
        }
        solution();
    }
    return 0;
}

/*
 *
2
6
3 4 2 6 5 1
5
1 2 3 4 5
 */