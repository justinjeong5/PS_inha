/*
 *  2020.3.26.
 *  INHA_problem_solving 3-2_game
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

vector<pair<string, pair<int, int>>> board;
// board = {name, {start, end}};
int input_length = 0;
int answer = 0;
int cur;

void resize_input() {
    answer = 1;
    board.resize(input_length, {"", {0, 0}});
}

bool cmp(pair<string, pair<int, int>> &a, pair<string, pair<int, int>> &b) {
    if (a.second.second == b.second.second)
        return a.second.first < b.second.first;
    return a.second.second < b.second.second;
}

void update_answer(int index) {
    if (cur > board[index].second.first) return;
    cur = board[index].second.second;
    answer++;
}

void print_answer() {
    cout << answer << '\n';
}

void solution() {
    sort(board.begin(), board.end(), cmp);

    cur = board[0].second.second;
    for (int index = 1; index < input_length; ++index) {
        update_answer(index);
    }
    print_answer();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    for (int test = 0; test < test_case; ++test) {
        cin >> input_length;
        resize_input();
        for (int input = 0; input < input_length; ++input) {
            cin >> board[input].first >> board[input].second.first >> board[input].second.second;
        }
        solution();
    }

    return 0;
}

/*
 2
11
item1 5 7
 item2 8 12
item3 0 6
 item4 1 4
 item5 6 10
 item6 5 9
 item7 3 9
 item8 8 11
 item9 2 14
 item10 3 5
 item11 12 16
 5
apple 47 49
 banana 35 47
 grape 2 46
 melon 7 19
 orange 19 40
 */