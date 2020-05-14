/*
 *  2020.3.25.
 *  INHA_problem_solving 2-1_error
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>

using namespace std;

int amount_origin, length_origin;
int length_problem;
int min_distance, target_idx;
string target;
vector<string> origin;

void resize_input(int amount_origin){
	origin.resize(amount_origin, "");
}

void print_letter(int target_idx) {
    char ans = 'A' + target_idx;
    cout << ans << '\n';
}

void update_distance(int distance, int pattern){
	if (min_distance > distance) {
        min_distance = distance;
        target_idx = pattern;
    }
}

int get_hamming_distance(string &text, string &target) {
    int distance = 0;
    for (int index = 0; index < length_origin; ++index) {
        if (text[index] == target[index]) continue;
        distance++;
    }
    return distance;
}

void solution() {
    const int len = length_problem / length_origin;
    for (int index = 0; index < len; index++) {
        min_distance = INT_MAX, target_idx = 0;
        for (int pattern = 0; pattern < amount_origin; ++pattern) {
            string tar = target.substr(index * length_origin, length_origin);
            int temp = get_hamming_distance(origin[pattern], tar);
            update_distance(temp, pattern);
        }
        print_letter(target_idx);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while(test_case-- != 0) {
        cin >> amount_origin >> length_origin;
        resize_input(amount_origin);
        for (int input = 0; input < amount_origin; ++input) {
            cin >> origin[input];
        }
        cin >> length_problem >> target;
        solution();
    }
    return 0;
}
/*
2
3 8
00000000
11111111
01010101
24 010000001111110101011101
4 8
00000011
00001100
00110000
11000000
16 1000000000000001
 */