/*
 *  2020.5.6.
 *  INHA_problem_solving 9-1
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <climits>

using namespace std;

int input_size, input_boundary;
vector<int> score;
vector<pair<int, int>> input;
int answer, counter = 0;

void resize_input() {
    answer = 0;
    counter = 0;
    score.clear();
    score.resize(input_size);
    input.clear();
    input.resize(input_size);
}

void print_answer() {
    cout << answer << "\n";
}

bool comparator(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}

void solution() {
    sort(input.begin(), input.end(), comparator);
    for (int idx = 1; idx < input_size; ++idx) {
        if(input[idx-1].first > input[idx].first){
            answer += score[counter];
            counter = 0;
            continue;
        }
        counter++;
    }
    answer += score[counter];
    print_answer();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case-- != 0) {
        cin >> input_size >> input_boundary;
        resize_input();
        for (int idx = 0; idx < input_size; ++idx) {
            cin >> score[idx];
        }
        for (int idx = 0; idx < input_size; ++idx) {
            cin >> input[idx].first >> input[idx].second;
        }
        solution();
    }


    return 0;
}

/*
2
5 30
1 4 8 16 32
1 1
30 5
28 4
29 3
15 2
6 100
1 2 3 100 200 300
95 6
8 1
98 5
77 4
31 3
2 2
 */