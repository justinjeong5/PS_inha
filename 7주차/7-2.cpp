/*
 *  2020.6.17.
 *  INHA_problem_solving 7-2
 */
#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

int input_amount, input_length;
bool result;
vector<vector<int>> input;

void preprocess() {
    input.clear();
    input.resize(input_amount, vector<int>(input_length + 1));
}

char int_to_char(int &a) {
    return (char) ('0' + a);
}

int char_to_int(char &a) {
    return (int) (a - '0');
}

int eval(deque<char> temp) {
    stack<int> s;
    s.push(temp.front());
    temp.pop_front();

    while (!temp.empty()) {
        char operation = temp.front();
        temp.pop_front();

        if (operation == '+') {
            s.push(char_to_int(temp.front()));
        }

        if (operation == '*') {
            int top_from_stack = s.top();
            s.pop();
            top_from_stack *= char_to_int(temp.front());
            s.push(top_from_stack);
        }
        temp.pop_front();
    }

    int sum = 0;
    while (!s.empty()) {
        sum += s.top();
        s.pop();
    }
    return sum;
}

void dfs(deque<char> &expression, int idx1, int idx2) {
    if (result) return;
    if (idx2 == input_length) {
        if (eval(expression) == input[idx1][idx2 + 1]) {
            result = true;
        }
        return;
    }
    expression.push_back(int_to_char(input[idx1][idx2]));
    expression.push_back('+');
    dfs(expression, idx1, idx2 + 1);
    expression.pop_back();
    expression.push_back('*');
    dfs(expression, idx1, idx2 + 1);
}

void print_answer() {
    cout << result << ' ';
}

void solution() {
    for (int index = 0; index < input_amount; ++index) {
        result = false;
        deque<char> expression;

        expression.push_back(int_to_char(input[index][0]));
        expression.push_back('+');
        dfs(expression, index, 0);
        expression.pop_back();
        expression.push_back('*');
        dfs(expression, index, 0);

        print_answer();
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case-- != 0) {
        cin >> input_amount >> input_length;
        preprocess();
        for (int index = 0; index < input_amount; ++index) {
            for (int idx = 0; idx < input_length + 1; ++idx) {
                cin >> input[index][idx];
            }
        }
        solution();
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
3 8 95
2 9 18
 */