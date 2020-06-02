/*
 *  2020.5.27.
 *  INHA_problem_solving 11-1
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int input_amount, input_length, target;
vector<vector<int>> input;
//입력받은 시간, 떨어지는데 걸리는 시간

void input_resize() {
    input.clear();
    input.resize(input_amount, {0, 0});
}

void get_drop_time() {
    for (int index = 0; index < input_amount; ++index) {
        if (input[index][0] > 0) {
            input[index][1] = input_length - input[index][0];
            continue;
        }
        input[index][1] = -input[index][0];
    }
}

bool cmp(vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
}

void sorting() {
    sort(input.begin(), input.end(), cmp);
}

void print_answer() {
    cout << input[target - 1][1] << '\n';
}

void solution() {
    get_drop_time();
    sorting();
    print_answer();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;

    while (test_case-- != 0) {
        cin >> input_amount >> input_length >> target;
        input_resize();
        for (int index = 0; index < input_amount; ++index) {
            cin >> input[index][0];
        }
        solution();
    }
    return 0;
}

/*
 2
 7 40 4
 3 -30 14 -7 -21 33 24
 6 30 5
 5 -9 11 13 -18 25
 */