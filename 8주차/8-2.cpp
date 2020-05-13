/*
 *  2020.4.29.
 *  INHA_problem_solving 8-2
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <climits>

using namespace std;

int input_size, answer;
vector<pair<int, int>> input;

void resize_input() {
    answer = 0;
    input.clear();
    input.resize(input_size);
}

void print_answer() {
    cout << answer << '\n';
}

int sub_price(int &idx) {
    return input[idx].first + input[input_size - idx - 1].second +
           min(input[idx].first, input[input_size - idx - 1].first) +
           min(input[idx].second, input[input_size - idx - 1].second);
    //a값 + b값 + 수수료 + 포장료
}

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.second;
}


void solution() {
    sort(input.begin(), input.end(), cmp);
    if (input_size % 2) answer = input[input_size / 2].first * 2;

    for (int idx = 0; idx < input_size / 2; ++idx) {
        answer += sub_price(idx);
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
        cin >> input_size;
        resize_input();
        for (int idx = 0; idx < input_size; ++idx) {
            cin >> input[idx].first >> input[idx].second;
        }
        solution();
    }
    return 0;
}

/*
4
5
7 10
50 30
3 25
5 9
29 14
3
20 5
10 3
30 12
2
10 30
15 20
1
100 50
 */