/*
 *  2020.4.17.
 *  INHA_problem_solving 6-1
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <climits>

using namespace std;

string target;
bool isPalandrome = true;

void preprocess() {
    isPalandrome = true;
    for (int i = 0; i < target.length(); ++i) {
        if(isupper(target[i])){
            target[i] = tolower(target[i]);
        }
    }
}

void print_answer() {
    if (isPalandrome) {
        cout << "YES" << '\n';
        return;
    }
    cout << "NO" << '\n';
}

bool is_alpha(char &it) {
    return islower(it);
}

void solution() {
    preprocess();
    int left = 0;
    int right = target.length() - 1;

    while (left < right) {
        if (!is_alpha(target[left])) {
            left++;
            continue;
        }
        if (!is_alpha(target[right])) {
            right--;
            continue;
        }
        if (target[left++] != target[right--]) {
            isPalandrome = false;
            break;
        }
    }
    print_answer();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case = 0;
    cin >> test_case;
    while (test_case-- != 0) {
        cin >> target;
        solution();
    }


    return 0;
}
/*
4
Eye!
Adam
Inha_University!
race!car?
 */