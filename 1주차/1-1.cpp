/*
 *  2020.3.18.
 *  INHA_problem_solving 1-1
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int input_amount, input_size;
vector<string> input;
unordered_map<char, int> um;
string answer;
int hamming_distance;
vector<char> dna_array = {'A', 'C', 'G', 'T'};

void input_resize() {
    answer = "";
    hamming_distance = 0;
    input.clear();
    input.resize(input_amount);
}

void print_answer() {
    cout << answer << '\n' << hamming_distance << '\n';
}

void update_hamming_distance(int plus) {
    hamming_distance += (input_amount - plus);
}

void update_representative(char &alpha) {
    answer += alpha;
}

void initialize_map() {
    for (auto it : dna_array) {
        um[it] = 0;
    }
}

pair<int, char> count_map() {
    pair<int, char> res = {0, '#'};
    for (auto it : dna_array) {
        if (um[it] <= res.first)continue;
        res.first = um[it];
        res.second = it;
    }
    return res;
}

void calculate_representative() {
    for (int index = 0; index < input_size; ++index) {
        initialize_map();
        for (int innerIndex = 0; innerIndex < input_amount; ++innerIndex) {
            um[input[innerIndex][index]]++;
        }
        pair<int, char> sub_answer = count_map();
        update_hamming_distance(sub_answer.first);
        update_representative(sub_answer.second);
    }
}

void solution() {
    calculate_representative();
    print_answer();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;

    while (test_case-- != 0) {
        cin >> input_amount >> input_size;
        input_resize();
        for (int idx = 0; idx < input_amount; ++idx) {
            cin >> input[idx];
        }
        solution();
    }
    return 0;
}
/*
 * input
 3
 5 8
 TATGATAC
 TAAGCTAC
 AAAGATCC
 TGAGATAC
 TAAGATGT
 4 10
 ACGTACGTAC
 CCGTACGTAG
 GCGTACGTAT
 TCGTACGTAA
 6 10
 ATGTTACCAT
 AAGTTACGAT
 AACAAAGCAA
 AAGTTACCTT
 AAGTTACCAA
 TACTTACCAA

 output
 TAAGATAC
7
ACGTACGTAA
6
AAGTTACCAA
12
 */