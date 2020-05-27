/*
 *  2020.5.6.
 *  INHA_problem_solving 9-2
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <climits>
#include <cstring>

using namespace std;

string text1, text2;
int TXT1_SIZ;
int TXT2_SIZ;

vector<vector<int>> cache;

void preprocess() {
    TXT1_SIZ = text1.size();
    TXT2_SIZ = text2.size();

    cache.clear();
    cache.resize(TXT1_SIZ + 1, vector<int>(TXT2_SIZ + 1, 0));
}

void print_answer() {
    cout << cache[0][0] << '\n';
}

void update_cache(int &row, int &col) {
    if (text1[row] == text2[col]) {
        cache[row][col] = cache[row + 1][col + 1] + 1;
        return;
    }
    cache[row][col] = max(cache[row + 1][col], cache[row][col + 1]);
}

void longestCommonSubsequence() {
    preprocess();
    for (int row = TXT1_SIZ - 1; row >= 0; row--) {
        for (int col = TXT2_SIZ - 1; col >= 0; col--) {
            update_cache(row, col);
        }
    }
    print_answer();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case-- != 0) {
        cin >> text1 >> text2;
        longestCommonSubsequence();
    }

    return 0;
}

/*
2
acbabk
acakbb
acaykpzzk
capcakkzz
 */