/*
 *  2020.5.13.
 *  INHA_problem_solving 10-1
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <climits>

using namespace std;

int input_amount = 0;
int input_weight = 0;
int answer = 0;
vector<vector<int>> items;
// { amount, weight, value }

void preprocess() {
    items.clear();
    items.resize(input_amount, {0, 0, 0});
    answer = 0;
}

void find_item_value() {
    for (int index = 0; index < input_amount; ++index) {
        items[index][2] = items[index][1] / items[index][0];
    }
}

bool cmp(vector<int> &a, vector<int> &b) {
    return a[2] > b[2];
}

void print_answer() {
    cout << answer << '\n';
}

void solution() {
    find_item_value();
    sort(items.begin(), items.end(), cmp);

    for (int index = 0; index < input_amount; ++index) {
        if (input_weight <= 0) break;
        const int cnt = input_weight > items[index][0] ? items[index][0] : input_weight;
        input_weight -= cnt;
        answer += items[index][2] * cnt;
    }
    print_answer();
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case-- != 0) {
        cin >> input_amount >> input_weight;
        preprocess();
        for (int input = 0; input < input_amount; ++input) {
            cin >> items[input][0];
        }
        for (int input = 0; input < input_amount; ++input) {
            cin >> items[input][1];
        }
        solution();
    }

    return 0;
}

/*
2
7 95
36 14 48 32 61 43 29
36 56 240 320 61 43 290
6 73
26 71 6 37 12 15
234 639 54 111 96 150
 */