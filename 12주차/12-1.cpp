/*
 *  2020.6.3.
 *  INHA_problem_solving 12-1
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <climits>

using namespace std;

const int UNVISITED = 0;
const int VISIT = 1;

int board_size, input_amount;
vector<vector<int>> board;
// { 카드번호, x축, y축 }

vector<int> visit;

struct TwoCards;
vector<TwoCards> result;
//  카드쌍을 저장하여 정렬하는 공

void input_resize();

bool is_already_visit(int &index);

void update_visit(int &a, int &b);

int get_distance(vector<int> &a, vector<int> &b);

int is_same_number(int &left, int &right);

bool is_closer(TwoCards &cur, TwoCards &next);

bool cmp_input(vector<int> &a, vector<int> &b);

bool cmp_res(TwoCards &a, TwoCards &b);

bool cmp_res2(TwoCards &a, TwoCards &b);

void print_answer();

void solution();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case-- != 0) {
        cin >> board_size >> input_amount;
        input_resize();
        for (int index = 0; index < input_amount; ++index) {
            char temp;
            cin >> temp >> board[index][1] >> board[index][2];
            board[index][0] = temp - 'A';
        }
        solution();
    }
    return 0;
}


struct TwoCards {
    int distance;
    char number;
    vector<int> card1;
    vector<int> card2;

    TwoCards(vector<int> &a, vector<int> &b) {
        distance = get_distance(a, b);
        number = a[0];
        if (a[2] == b[2]) {
            if (a[1] < b[1]) {
                card1 = a;
                card2 = b;
            } else {
                card1 = b;
                card2 = a;
            }
        } else if (a[2] < b[2]) {
            card1 = a;
            card2 = b;
        } else {
            card1 = b;
            card2 = a;
        }
    }

    TwoCards() {
        distance = 2000000;
        number = 'Z';
        card1 = {0, 0, 0};
        card2 = {0, 1000, 1000};
    }
};

void input_resize() {
    board.clear();
    board.resize(input_amount, vector<int>(3));
    visit.clear();
    visit.resize(input_amount, UNVISITED);
    result.clear();
}

bool is_already_visit(int &index) {
    return visit[index] == VISIT;
}

void update_visit(int &a, int &b) {
    visit[a] = VISIT;
    visit[b] = VISIT;
}

int get_distance(vector<int> &a, vector<int> &b) {
    const int temp_x = a[1] - b[1];
    const int temp_y = a[2] - b[2];
    return temp_x * temp_x + temp_y * temp_y;
}

int is_same_number(int &left, int &right) {
    return board[left][0] == board[right][0];
}

bool is_closer(TwoCards &cur, TwoCards &next) {
    if (cur.distance != next.distance) return cur.distance > next.distance;
    if (cur.card2[2] == next.card2[2]) return cur.card2[1] > next.card2[1];
    return cur.card2[2] > next.card2[2];
}

bool cmp_input(vector<int> &a, vector<int> &b) {
    vector<int> origin = {0, 0, 0};
    int a_dist = get_distance(origin, a);
    int b_dist = get_distance(origin, b);

    if (a_dist == b_dist) return a[2] < b[2];
    return a_dist < b_dist;
}

void print_result(TwoCards &cur) {
    cout << static_cast<char>(cur.number + 'A') << " " << cur.card1[1] << " " << cur.card1[2]
         << " " << cur.card2[1] << " " << cur.card2[2] << '\n';
}

bool cmp_res(TwoCards &a, TwoCards &b) {
    if ((a.card1[2] + a.card2[2]) == (b.card1[2] + b.card2[2]))
        return (a.card1[1] + a.card2[1]) < (b.card1[1] + b.card2[1]);
    return (a.card1[2] + a.card2[2]) < (b.card1[2] + b.card2[2]);
}

bool cmp_res2(TwoCards &a, TwoCards &b) {
    return a.number < b.number;
}

void print_answer() {
    sort(result.begin(), result.end(), cmp_res);
    sort(result.begin(), result.end(), cmp_res2);
    for (auto it : result) {
        print_result(it);
    }
}

void solution() {
    sort(board.begin(), board.end(), cmp_input);
    int repeat = input_amount / 2;

    while (repeat-- != 0) {
        auto *cur = new TwoCards();
        int left_index = 0, right_index = 0;
        for (int left = 0; left < input_amount - 1; ++left) {
            if (is_already_visit(left)) continue;

            for (int right = left + 1; right < input_amount; ++right) {
                if (is_already_visit(right)) continue;
                if (!is_same_number(left, right)) continue;
                auto *next = new TwoCards(board[left], board[right]);
                if (!is_closer(*cur, *next)) continue;

                left_index = left;
                right_index = right;
                cur = next;
            }
        }
        update_visit(left_index, right_index);
        result.push_back(*cur);
    }
    print_answer();
}

/*
3
6 8
A 3 1
B 1 4
B 1 5
A 3 3
A 2 2
B 5 4
A 1 1
B 2 4
2 4
A 0 0
A 1 1
A 1 0
A 0 1
6 6
A 3 1
B 1 4
B 4 4
A 5 2
B 5 4
B 4 5

1
25 202
W 3 10
W 4 7
B 10 0
B 16 12
D 6 20
D 16 6
W 14 6
W 21 1
M 24 19
M 22 17
U 3 22
U 8 0
N 16 2
N 7 8
I 10 21
I 8 12
C 8 4
C 15 17
A 19 22
A 6 13
K 22 4
K 19 15
C 21 18
C 24 0
O 10 3
O 11 13
O 12 12
O 2 6
S 23 5
S 19 1
V 20 22
V 11 22
N 0 0
N 0 19
W 0 14
W 9 2
M 14 17
M 18 2
C 13 10
C 19 16
M 20 10
M 24 10
J 5 4
J 0 24
V 22 8
V 22 22
R 8 14
R 16 5
Z 10 16
Z 7 4
Z 1 15
Z 9 1
P 19 18
P 6 21
S 9 23
S 6 1
Z 5 6
Z 5 7
A 7 7
A 2 14
F 9 14
F 20 9
F 24 2
F 2 3
S 0 3
S 3 16
X 13 19
X 2 2
Z 21 5
Z 17 4
B 20 23
B 9 20
Q 23 7
Q 4 16
E 20 5
E 6 0
D 8 24
D 23 24
Z 7 21
Z 19 7
M 1 9
M 6 18
L 17 14
L 24 5
J 20 13
J 9 22
J 13 5
J 16 16
T 0 21
T 4 13
L 0 20
L 20 11
K 3 3
K 4 23
R 16 21
R 13 8
E 4 18
E 9 5
W 9 13
W 19 0
U 11 23
U 12 0
E 15 24
E 22 9
B 22 11
B 24 12
S 20 7
S 14 2
G 17 8
G 4 10
W 7 18
W 14 1
W 23 21
W 9 24
B 1 11
B 19 6
R 11 3
R 13 14
G 23 19
G 18 23
V 10 9
V 20 1
J 7 12
J 11 0
G 0 15
G 17 2
R 1 3
R 2 8
K 11 14
K 21 11
P 24 1
P 9 10
R 8 15
R 9 16
N 16 1
N 19 20
X 16 14
X 0 8
P 3 5
P 11 19
K 1 0
K 19 12
W 13 6
W 0 16
S 20 24
S 12 24
O 4 5
O 20 15
U 2 23
U 6 7
M 20 4
M 18 1
Q 15 20
Q 0 9
B 4 1
B 19 10
H 10 13
H 10 1
B 13 13
B 22 7
U 24 23
U 17 12
A 14 5
A 15 23
F 3 21
F 6 3
Q 2 11
Q 16 10
L 9 21
L 8 13
M 16 24
M 0 22
P 11 24
P 11 9
G 6 14
G 2 21
O 5 14
O 21 12
J 2 7
J 19 9
F 19 19
F 13 21
F 19 2
F 17 21
X 16 17
X 1 7
T 0 10
T 3 6
C 15 13
C 24 21
M 14 10
M 19 8
T 13 12
T 8 9
K 24 4
K 1 6
L 18 16
L 22 15
C 23 12
C 18 8
R 6 6
R 8 11
 */