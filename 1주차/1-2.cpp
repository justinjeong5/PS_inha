/*
 *  2020.6.15.
 *  INHA_problem_solving 1-2.cpp
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <climits>

using namespace std;

int input_amount, input_window;
vector<int> input;
int answer;

void resize_input() {
    answer = 0;
    input.clear();
    input.resize(input_amount, 0);
}

void print_answer() {
    cout << answer << '\n';
}

double find_medium(vector<int> sub_array) {
    sort(sub_array.begin(), sub_array.end());
    if (sub_array.size() % 2) {
        return sub_array[(int) (sub_array.size() / 2)];
    }
    return (double) (sub_array[sub_array.size() / 2 - 1] + sub_array[sub_array.size() / 2]) / 2;
}

vector<int> sub_vector(int left, int right) {
    vector<int> res(right - left);
    int cnt = 0;
    for (int i = left; i < right; ++i) {
        res[cnt++] = input[i];
    }
    return res;
}

void solution() {
    int left = 0, right = 0;

    while (right++ < input_amount) {
        while (left + input_window <= right && right < input_amount) {
            double res = find_medium(sub_vector(left, right));
            if (res * 2 <= input[right]) answer++;
            left++, right++;
        }
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
        cin >> input_amount >> input_window;
        resize_input();
        for (int idx = 0; idx < input_amount; ++idx) {
            cin >> input[idx];
        }
        solution();
    }
    return 0;
}

/*
 *
input
2
9 5
2 3 4 2 3 6 8 4 5
5 4
1 2 3 4 4
output
2
0
 */