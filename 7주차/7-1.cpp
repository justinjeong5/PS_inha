/*
 *  2020.4.22.
 *  INHA_problem_solving 7-1
 */

#include <iostream>
#include <string>
#include <utility>

using namespace std;

string num1, num2;

void print_result(int &substring) {
    substring == 0 ? cout << 1 : cout << 0;
    cout << '\n';
}

bool is_lager(int &a, int b) {
    return a >= b;
}

int get_residue(int &a, string &b) {
    return a % stoi(b);
}

void add_next_digit(int &num, int index) {
    num = num * 10 + (index - '0');
}

void solution() {
    int substring = 0;
    for (char digit : num1) {
        add_next_digit(substring, digit);
        if (!is_lager(substring, stoi(num2))) continue;
        substring = get_residue(substring, num2);
    }
    print_result(substring);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case-- != 0) {
        cin >> num1 >> num2;
        solution();
    }
    return 0;
}

/*
 *
2
306580397317560752981 23171
2852841814435297692 23171
 */