/*
 *  2020.5.13.
 *  INHA_problem_solving 10-2
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
int sub_weight = 0, sub_value = 0;
vector<vector<int>> items;
// { amount, weight }

void preprocess() {
    items.clear();
    items.resize(input_amount, {0, 0});
    answer = 0;
}


void print_answer() {
    cout << answer << '\n';
}

void solution() {
    sort(items.begin(), items.end());

    do {
        sub_weight = input_weight, sub_value = 0;
        for (int index = input_amount - 1; index >= 0; --index) {
            if (items[index][0] > sub_weight) break;
            sub_weight -= items[index][0];
            sub_value += items[index][1];
        }
        answer = max(answer, sub_value);
    } while (next_permutation(items.begin(), items.end()));

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
4 7
6 4 3 5
13 8 6 12
5 11
7 2 8 9 3
6 8 12 4 9
 */