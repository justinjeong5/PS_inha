/*
 *  2020.4.22.
 *  INHA_problem_solving 7-2
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <climits>

using namespace std;

vector<int> grid;
int input_amount, test_amount;
int result = 0;

void resize_grid() {
    grid.clear();
    grid.resize(input_amount + 1, 0);
    result = 0;
}

void print_result() {
    cout << result << " ";
}

void print_interval() {
    cout << '\n';
}

bool no_more_step(int &val, int &cnt) {
    return result == 1 || cnt > input_amount || val > grid[input_amount];
}

void depthFirstSearch(int &current_value, int &current_count) {
    if (no_more_step(current_value, current_count)) return;

    if (current_value == grid[input_amount] && current_count == input_amount) {
        result = 1;
        return;
    }

    int next_cnt = current_count + 1;
    int next_val = current_value + grid[current_count];
    depthFirstSearch(next_val, next_cnt);

    next_val = current_value * grid[current_count];
    depthFirstSearch(next_val, next_cnt);

}

void solution() {
    int val = grid[0], cnt = 1;
    depthFirstSearch(val, cnt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case-- != 0) {
        cin >> test_amount >> input_amount;
        for (int test = 0; test < test_amount; ++test) {
            resize_grid();
            for (int input = 0; input < input_amount + 1; ++input) {
                cin >> grid[input];
            }
            solution();
            print_result();
        }
        print_interval();
    }


    return 0;
}

/*
2
5 4
6 4 2 9 42
1 3 2 4 10
1 3 2 3 48
2 4 6 8 384
1 2 8 2 2356
3 2
1 1 2
3 8 95
2 9 18
 */