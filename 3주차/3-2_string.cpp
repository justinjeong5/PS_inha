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

string minWindow(string s, string t) {
    unordered_map<char, int> um;
    for (auto it : t) {
        if (!um.count(it)) um[it] = 0;
        um[it]++;
    }

    int start = 0, end = 0;
    int count = um.size(), len = INT_MAX;
    int ans_start = 0;

    while (end < s.length()) {

        char end_char = s[end++];
        if (um.count(end_char)) {
            if (--um[end_char] == 0) count--;
        }

        while (count == 0) {
            if (len > end - start) {
                len = end - start;
                ans_start = start;
            }

            char start_char = s[start++];
            if (um.count(start_char)) {
                if (++um[start_char] > 0) count++;
            }
        }
    }
    return len == INT_MAX ? "" : s.substr(ans_start, len);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    for (int test = 0; test < test_case; ++test) {
        string text, pattern;
        cin >> text >> pattern;
        cout << minWindow(text, pattern).length() << '\n';
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