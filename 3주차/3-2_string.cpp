/*
 *  2020.3.26.
 *  INHA_problem_solving 3-2_string
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <climits>
#include <unordered_map>

using namespace std;

string text, pattern;
unordered_map<char, int> um_p;
unordered_map<char, int> um_t;

void preprocess_text() {
    um_t.clear();
    for (auto it  : text) {
        if (!um_t.count(it)) um_t[it] = 0;
        um_t[it]++;
    }
}

void preprocess_pattern() {
    um_p.clear();
    for (auto it : pattern) {
        if (!um_p.count(it)) um_p[it] = 0;
        um_p[it]++;
    }
}

bool find_character(char &it) {
    if (um_p.count(it)) {
        if (--um_p[it] == -1) {
            um_p.erase(it);
        }
        return true;
    }
    return false;
}

bool is_possible() {
    for (auto it : pattern) {
        if (!um_t.count(it)) return false;
    }
    return true;
}

void solution() {
    preprocess_text();
    preprocess_pattern();

    if (!is_possible()) {
        cout << 0 << '\n';
        return;
    }
    
    int answer = INT_MAX;
    int left = 0, right = 0;
    int count = 1, cur_length;
    while (left != (int) text.length()) {
        preprocess_pattern();
        if (!find_character(text[left])) {
            left++;
            right++;
            continue;
        }

        count = (int) pattern.length();
        cur_length = 0;
        while (count != 0 && right != (int) text.length()) {
            if (find_character(text[right])) count--;
            right++;
            cur_length++;
        }
        answer = min(answer, cur_length);
        left++;
        right = left;

    }
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    for (int test = 0; test < test_case; ++test) {
        cin >> text >> pattern;
        solution();
    }
    return 0;
}

/*
 4
INHACODEBANC
ABC
MERRYCHRIsTMAS
sHE
Abracadabra
Magic
cacAba
Aaab

 13
INHACODEBANC
ABC
MERRYCHRIsTMAS
sHE
Abracadabra
Magic
cacAba
Aaab
ABBAACDBCAB
CBA
ABBAACDBCAB
ABCB
ConfessionsOfAShopahollic
eAssp
SurRogates
uRs
HarryPotter
rot
ThePhilosophersStone
shoe
ChamberOfSecrets
Sers
ThePrisonerOfAzkaban
Tn
TheOrderofThePhoneix
xPea
 */