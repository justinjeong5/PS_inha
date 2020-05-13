/*
 *  2020.4.8.
 *  INHA_problem_solving 5-2
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <climits>

using namespace std;

const int UNVISITED = false;
const int VISITED = true;

vector<int> src(2);
vector<int> dst(2);

int board_size;
int answer;
vector<vector<bool>> visit;

struct Dir {
    int y, x;
};
Dir dir[8] = {
        {2,  1},
        {1,  2},
        {2,  -1},
        {1,  -2},
        {-2, 1},
        {-1, 2},
        {-2, -1},
        {-1, -2}
};

void print_answer() {
    cout << answer << '\n';
}

bool is_in_boundary(int &y, int &x) {
    return y >= 0 && x >= 0 && y < board_size && x < board_size;
}

void update_visit(int &y, int &x) {
    visit[y][x] = VISITED;
}

void bfs() {
    visit.clear();
    visit.resize(board_size, vector<bool>(board_size, UNVISITED));
    answer = INT_MAX;

    queue<vector<int>> q;
    //y, x, cnt
    q.push({src[0], src[1], 0});
    update_visit(src[0], src[1]);

    while (!q.empty()) {
        int cur_y = q.front()[0];
        int cur_x = q.front()[1];
        int cur_cnt = q.front()[2];
        q.pop();
        update_visit(cur_y, cur_x);

        if (cur_y == dst[0] && cur_x == dst[1]) {
            answer = min(answer, cur_cnt);
        }
        for (auto &way : dir) {
            int next_y = cur_y + way.y;
            int next_x = cur_x + way.x;
            if (!is_in_boundary(next_y, next_x)) continue;
            if (visit[next_y][next_x]) continue;
            update_visit(next_y, next_x);
            q.push({next_y, next_x, cur_cnt + 1});
        }
    }
}

void solution() {

    bfs();
    print_answer();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case-- != 0) {
        cin >> board_size >> src[0] >> src[1] >> dst[0] >> dst[1];
        solution();
    }

    return 0;
}

/*
 *
4
5
1 0
4 4
8
0 0
7 0
100
0 0
30 50
10
1 1
1 1
 */