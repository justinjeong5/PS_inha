/*
 *  2020.3.25.
 *  INHA_problem_solving 2-2_omok
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

const int STONE_AMOUNT = 225;
const int BLACK = 0;
const int WHITE = 1;
const int EMPTY = -1;

int dirRow[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dirCol[8] = {0, 1, 0, -1, 1, -1, -1, 1};

vector<vector<pair<int, int>>> board;

bool finished = false;

void resize_board() {
    board.resize(15);
    for (int i = 0; i < 15; ++i) {
        board[i].resize(15, {EMPTY, EMPTY});
    }
    finished = false;
}

bool is_inboundary(int &row, int &col) {
    return row >= 0 && col >= 0 && row < 15 && col < 15;
}

void check_answer(int &row, int &col) {
    int target = board[row][col].second;
    for (int dir = 0; dir < 8; ++dir) {
        int curRow = row;
        int curCol = col;
        for (int up = 0; up < 6; ++up) {
            curRow = curRow + dirRow[dir];
            curCol = curCol + dirCol[dir];
            if (!is_inboundary(curRow, curCol)) break;
            if (up != 5 && board[curRow][curCol].second != target) break;
            if (up == 5 && board[curRow][curCol].second != target) {
                char ans = 'W';
                if (board[curRow][curCol].second == BLACK) {
                    ans = 'B';
                }
                cout << board[curRow][curCol].first << " " << ans << '\n';
                finished = true;
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    for (int test = 0; test < test_case; ++test) {
        resize_board();
        int turn = BLACK;
        for (int stone = 1; stone <= STONE_AMOUNT; ++stone) {
            int row, col;
            cin >> row >> col;
            if (finished) continue;
            board[row][col] = {stone, turn};
            turn = 1 - turn;
            check_answer(row, col);
        }
    }
    return 0;
}

/*
1
3 3
4 3
4 4
4 5
5 5
5 6
6 6
6 7
7 7
8 5

 1
 1 1
 1 2
1 3
 1 4
 1 5
 1 6
 */
