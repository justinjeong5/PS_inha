/*
 *  2020.4.29.
 *  INHA_problem_solving 8-1
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>
#include <climits>

using namespace std;

int input_size, answer;
vector<int> input;
vector<int> criteria(3);

void print_result() {
    cout << answer << '\n';
}

void resize_input() {
    answer = 0;
    input.clear();
    input.resize(input_size);
}

int sub_power(int &idx) {
    return (int) (((long long int) pow(criteria[2], idx) * input[idx]) % (long long int) 1013);
}

bool is_in_boundary(int &num) {
    return num >= criteria[0] && num <= criteria[1];
}

void solution() {
    sort(input.begin(), input.end());
    do {
        int res = 0;
        for (int idx = 0; idx < input_size; ++idx) {
            res += sub_power(idx);
        }
        res %= 1013;
        if (!is_in_boundary(res)) continue;
        answer++;
    } while (next_permutation(input.begin(), input.end()));
    print_result();
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
        for (int index = 0; index < input_size; ++index) {
            cin >> input[index];
        }
        for (int index = 0; index < 3; ++index) {
            cin >> criteria[index];
        }
        solution();
    }


    return 0;
}

/*
2
3
2 3 4
50 60 4
4
17 5 11 201
450 670 3
 */