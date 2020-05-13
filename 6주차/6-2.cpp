/*
 *  2020.4.17.
 *  INHA_problem_solving 6-2
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <climits>
#include <unordered_map>

using namespace std;

const bool VISIT = true;
const bool UNVISITED = false;

unordered_map<char, pair<bool, bool>> um;
// character, key, lock
int cnt_matched = 0;
vector<vector<char>> board;
vector<vector<bool>> visit;
int max_row, max_col, max_matched;
vector<int> src(2);

int answer = 0;

struct Dir {
    int row, col;
};
Dir dir[4] = {{1,  0},
              {0,  1},
              {-1, 0},
              {0,  -1}};

void preprocess() {
    answer = 0;
    cnt_matched = 0;
    max_matched = 0;
    um.clear();

    board.clear();
    board.resize(max_row, vector<char>(max_col));

    visit.clear();
    visit.resize(max_row, vector<bool>(max_col, UNVISITED));
    for (int idx = 0; idx < 6; ++idx) {
        um[idx + 'a'] = {UNVISITED, UNVISITED};
    }
    um['*'] = {VISIT, VISIT};
}

void print_answer() {
    if (cnt_matched == max_matched) {
        cout << answer << '\n';
        return;
    }
    cout << -1 << '\n';
}

void update_visit(int &row, int &col) {
    visit[row][col] = !visit[row][col];
}

bool is_in_boundary(int &row, int &col) {
    return row >= 0 && col >= 0 && row < max_row && col < max_col;
}

void dfs(int &row, int &col) {
    if (cnt_matched == max_matched) return;

    for (int idx = 0; idx < 4; ++idx) {
        int next_row = row + dir[idx].row;
        int next_col = col + dir[idx].col;

        if (!is_in_boundary(next_row, next_col)) continue;
        char next_char = board[next_row][next_col];
        if (next_char == '#' || visit[next_row][next_col]) continue;
        if (islower(next_char)) um[next_char].first = VISIT;

        if (um.count(next_char)) {
            if ((isupper(next_char) && um[next_char].first)) {
                update_visit(next_row, next_col);
                cnt_matched++;
                dfs(next_row, next_col);
                update_visit(next_row, next_col);
                cnt_matched--;
                continue;
            }
            if(next_char == '*'){
                update_visit(next_row, next_col);
                dfs(next_row, next_col);
                update_visit(next_row, next_col);
                continue;
            }
        }
    }
}

void solution() {
    update_visit(src[0], src[1]);
    dfs(src[0], src[1]);
    print_answer();
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;

    while (test_case-- != 0) {
        cin >> max_row >> max_col;
        preprocess();
        for (int row = 0; row < max_row; ++row) {
            for (int col = 0; col < max_col; ++col) {
                cin >> board[row][col];
                if (board[row][col] == '@') src[0] = row, src[1] = col;
                if (islower(board[row][col])) max_matched++;
            }
        }
        solution();
    }
    return 0;
}

/*
4
3 5
@ * a * #
# B # * #
b * A * *
3 5
@ * * a A
* * B # *
* * * * b
2 4
@ A * a
* * # *
3 5
@ * * a B
* * A # *
* * * * b
 */