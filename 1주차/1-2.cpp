/*
 *  2020.3.18.
 *  INHA_problem_solving 1-2
 */

#include <iostream>
#include <vector>

using namespace std;

vector<double> expense;
int input_length, day_length;

double find_median(int index) {
    if (day_length % 2 == 1) return expense[index - (day_length / 2 + 1)];
    return (expense[index - day_length / 2] + expense[index - (day_length / 2 - 1)]) / 2;
}


bool over_expense(int index) {
    double target = find_median(index) * 2;
    return target <= expense[index];
}


void solution() {
    int answer = 0;
    for (int day = day_length; day < input_length; ++day) {
        if (over_expense(day)) answer++;
    }
    cout << answer << '\n';
}

/*
 *
2
9 5
2 3 4 2 3 6 8 4 5
5 4
1 2 3 4 4
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    for (int test = 0; test < test_case; ++test) {
        cin >> input_length >> day_length;
        expense.resize(input_length);
        for (int input = 0; input < input_length; ++input) {
            int data;
            cin >> data;
            expense[input] = data;
        }
        solution();
    }
    return 0;
}