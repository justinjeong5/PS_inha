/*
 *  2020.4.1.
 *  INHA_problem_solving 4-1
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <climits>

using namespace std;
int test_case_amount, input_siz = 0;
int answer = 0;

vector<int> nums;

void print_answer() {
    cout << answer << '\n';
}

void solution() {
    for (int out = 0; out < input_siz; ++out) {
        int target = nums[out];
        for (int in = out + 1; in < input_siz; ++in) {
            if (target != nums[in] + 1) continue;
            target--;
        }
        answer++;
    }
    print_answer();
}

void preprocess() {
    nums.resize(input_siz, 0);
    answer = 0;
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