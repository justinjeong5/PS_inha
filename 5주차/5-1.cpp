/*
 *  2020.4.8.
 *  INHA_problem_solving 5-1
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <utility>
#include <climits>

using namespace std;

unordered_map<int, int> um;

const bool VISIT = true;
const bool UNVISITED = false;
int input_size;
int answer = 0;

void solution() {
    answer = input_size;

    for (int idx = 1; idx <= input_size; ++idx) {
        vector<bool> visit(input_size + 1, UNVISITED);
        int cnt = 0;
        visit[idx] = VISIT;
        int pre = idx, cur = um[idx];
        while (true) {
            if (visit[cur]) {
                if (idx == cur) {
                    answer--;
                    break;
                }
                break;
            }
            visit[pre] = VISIT;
            visit[cur] = VISIT;
            pre = cur;
            cur = um[pre];
        }
    }
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case, dst;
    cin >> test_case;
    while (test_case-- != 0) {
        cin >> input_size;
        for (int input_idx = 1; input_idx <= input_size; ++input_idx) {
            cin >> um[input_idx];
        }
        solution();
    }

    return 0;
}


/*
3
7
3 1 3 7 3 4 6
10
4 10 1 4 6 2 8 9 7 5
8
1 2 3 4 5 6 7 8
 */