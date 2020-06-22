# PS_inha
Problem Solving Inha Univ. 2020 spring 

collaborator: [ellyheetov](https://github.com/ellyheetov)  

## <1주차>
### 1.1  [DNA 대표서열](https://github.com/justinjeong5/PS_inha/blob/master/1%EC%A3%BC%EC%B0%A8/prob-DNA1-1.pdf)(solved) 

최소편집거리 알고리즘 (minimum edit distance algorithm)  
주어진 문자열의 최소편집거리의 합을 구하고, 모든 문자열의 편집거리가 최소인 문자열을 구하는 문제  


<details>
    <summary>클릭하여 코드보기</summary>

```c++
/*
 *  2020.3.18.
 *  INHA_problem_solving 1-1
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>

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
```

</details>

	입력된 문자열의 개수를 T, 길이를 N이라고 할때
	시간복잡도: O(TN)
	공간복잡도: O(T)

* [Leetcode - 72. Edit Distance  (유사문제)](https://leetcode.com/problems/edit-distance/)
* [백준 - 3449. 해밍 거리 (유사문제)](https://www.acmicpc.net/problem/3449)  
* [백준 - 7620. 편집 거리 (유사문제)](https://www.acmicpc.net/problem/7620)  
  
### 1.2 [과소비 알림 서비스](https://github.com/justinjeong5/PS_inha/blob/master/1%EC%A3%BC%EC%B0%A8/prob-Alarm-1-2.pdf)

슬라이딩 윈도우 알고리즘 (sliding window)  
슬라이딩 윈도우 방식을 이용하여 k개의 연속된 구간에서의 중간값을 구하는 문제  

	입력된 배열의 길이를 N, 슬라이딩 윈도우의 크기를 K라고 할떄  
	시간복잡도: O(N logK)
	공간복잡도: O(K)
 
* [Leetcode - 480. Sliding Window Median (유사문제)](https://leetcode.com/problems/sliding-window-median/)
* [백준 - 1572. 중앙값 (유사문제)](https://www.acmicpc.net/problem/1572)

## <2주차>
### 2.1 [오류정정](https://github.com/justinjeong5/PS_inha/blob/master/2%EC%A3%BC%EC%B0%A8/prob-Error.pdf)(solved)☆

최소편집거리 알고리즘 (minimum edit distance algorithm)  
주어진 문자열의 최소편집거리를 이용하여, 원래 문자열이 무엇이었는지 알아내는 문제  

<details>
    <summary>클릭하여 코드보기</summary>

```c++
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
```

</details>

	입력된 문자열의 개수를 T, 문자열의 길이를 N이라고 할때
	시간복잡도: O(TN)
	공간복잡도: O(N)

* [Leetcode - 72. Edit Distance  (유사문제)](https://leetcode.com/problems/edit-distance/)
* [백준 - 3449. 해밍 거리 (유사문제)](https://www.acmicpc.net/problem/3449)
* [백준 - 7620. 편집 거리 (유사문제)](https://www.acmicpc.net/problem/7620)

### 2.2 [오목](https://github.com/justinjeong5/PS_inha/blob/master/2%EC%A3%BC%EC%B0%A8/prob-Omok.pdf)

탐색 BFS, DFS  
탐색을 이용하여 5개의 연속된 돌이 놓이는지를 확인하는 문제  

* [백준 - 2615. 오목 (유사문제)](https://www.acmicpc.net/problem/2615)

## <3주차>
### 3.1 [게임개발계획](https://github.com/justinjeong5/PS_inha/blob/master/3%EC%A3%BC%EC%B0%A8/prob-Game.pdf)(solved)☆

그리디 알고리즘 (Greedy algorithm)  
그리디 알고리즘의 대표문제로 유명한 회의실 배정문제와 상당히 유사한 문제  

<details>
    <summary>클릭하여 코드보기</summary>

```c++
/*
 *  2020.3.26.
 *  INHA_problem_solving 3-2_game
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

vector<pair<string, pair<int, int>>> board;
// board = {name, {start, end}};
int input_length = 0;
int answer = 0;

void resize_input() {
    answer = 1;
    board.resize(input_length, {"", {0, 0}});
}

bool cmp(pair<string, pair<int, int>> &a, pair<string, pair<int, int>> &b) {
    if (a.second.second < b.second.second) return true;
    else if (a.second.second > b.second.second) return false;
    else if (a.second.second == b.second.second) {
        return a.second.first < b.second.first;
    }
}

void update_answer(int cur, int index){
    if (cur > board[index].second.first) return;
    cur = board[index].second.second;
    answer++;
}

void print_answer() {
    cout << answer << '\n';
}

void solution() {
    sort(board.begin(), board.end(), cmp);

    int cur = board[0].second.second;
    for (int index = 1; index < input_length; ++index) {
        update_answer(cur, index);
    }
    print_answer();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    for (int test = 0; test < test_case; ++test) {
        cin >> input_length;
        resize_input();
        for (int input = 0; input < input_length; ++input) {
            cin >> board[input].first >> board[input].second.first >> board[input].second.second;
        }
        solution();
    }

    return 0;
}

/*
 2
11
item1 5 7
 item2 8 12
 item3 0 6
 item4 1 4
 item5 6 10
 item6 5 9
 item7 3 9
 item8 8 11
 item9 2 14
 item10 3 5
 item11 12 16
 5
apple 47 49
 banana 35 47
 grape 2 46
 melon 7 19
 orange 19 40
 */
```

</details>


	입력의 크기를 N이라 할때  
	시간복잡도: O(N logN)
	공간복잡도: O(N)

* [백준 - 1931. 회의실 (동일문제)](https://www.acmicpc.net/problem/1931)

### 3.2 [최소문자열 탐색](https://github.com/justinjeong5/PS_inha/blob/master/3%EC%A3%BC%EC%B0%A8/prob-String.pdf)(solved)☆

슬라이딩 윈도우 알고리즘 (sliding window)  
슬라이딩 윈도우 방식을 이용하여 최소 길이 부분 문자열을 구하는 문제  

<details>
    <summary>클릭하여 코드보기</summary>

```c++
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
```

</details>  

	입력된 크기를 각각 N: 긴 문자열의 길이, M: 짧은 문자열의 길이라고 할때
	시간복잡도: O(N)
	공간복잡도: O(N+M)

* [Leetcode - 76. Minimum Window Substring (동일문제)](https://leetcode.com/problems/minimum-window-substring/)


## <4주차>
### 4.1 [움직이는 하노이탑](https://github.com/justinjeong5/PS_inha/blob/master/4%EC%A3%BC%EC%B0%A8/prob-W3_P1.pdf)(solved)
 
원형 배열(circular qrray)  
원형 배열의 개념이 포함된 문제  

<details>
    <summary>클릭하여 코드보기</summary>

```c++
/*
 *  2020.4.1.
 *  INHA_problem_solving 4-1
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <climits>

using namespace std;
int test_case_amount, input_siz = 0;
int answer = 0;

vector<int> input;

void print_answer() {
    cout << answer << '\n';
}

void solution() {
    for (int out = 0; out < input_siz; ++out) {
        int target = input[out];
        for (int in = out + 1; in < input_siz; ++in) {
            if (target != input[in] + 1) continue;
            target--;
        }
        answer++;
    }
    print_answer();
}

void preprocess() {
    input.resize(input_siz, 0);
    answer = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> test_case_amount;
    while (test_case_amount-- != 0) {
        cin >> input_siz;
        preprocess();
        for (int input_index = 0; input_index < input_siz; ++input_index) {
            cin >> input[input_index];
        }
        solution();
    }
    return 0;
}

/*
 *
2
6
3 4 2 6 5 1
5
1 2 3 4 5
 */
```

</details>  

	입력의 크기를 N이라 할때
	시간복잡도: O(N^2)
	공간복잡도: O(N)

* [프로그래머스 - 42891. 무지의 먹방 라이브 (유사문제)](https://programmers.co.kr/learn/courses/30/lessons/42891)

### 4.2 [움직이는 하노이탑](https://github.com/justinjeong5/PS_inha/blob/master/4%EC%A3%BC%EC%B0%A8/prob-W3_P2.pdf)(solved)☆

앞선 4.1번의 문제에서 입력의 크기가 매우 커진 형태이다.  
따라서 O(N^2)의 속도로는 풀리지 않는다
해시맵을 사용하여 탐색 단계에서의 속도를 O(1)으로 하여 속도를 빠르게 하였다.  

<details>
    <summary>클릭하여 코드보기</summary>

```c++
/*
 *  2020.4.1.
 *  INHA_problem_solving 4-2
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <utility>

using namespace std;
int test_case_amount, input_siz = 0;
int answer = 0, temp;
const int VISITED = -1;
const int UNDISCOVERED = 1;

vector<int> input;
unordered_map<int, int> um;

void print_answer() {
    cout << answer << '\n';
}

void solution() {
    for (int idx = 0; idx < input_siz; ++idx) {
        if (!um.count(input[idx] + 1)) {
            um[input[idx]] = UNDISCOVERED;
            answer++;
            continue;
        }
        um[input[idx]] = VISITED;
    }
    print_answer();
}

void preprocess() {
    input.resize(input_siz, 0);
    answer = 0;
    um.clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> test_case_amount;
    while (test_case_amount-- != 0) {
        cin >> input_siz;
        preprocess();

        for (int input_index = 0; input_index < input_siz; ++input_index) {
            cin >> input[input_index];
        }
        solution();
    }
    return 0;
}

/*
 *
2
6
3 4 2 6 5 1
5
1 2 3 4 5
 */
```

</details>  


	입력의 크기를 N이라 할때
	시간복잡도: O(N)
	공간복잡도: O(N)

* [프로그래머스 - 42891. 무지의 먹방 라이브 (유사문제)](https://programmers.co.kr/learn/courses/30/lessons/42891)

## <5주차>

### 5.1 [팀원 구하기](https://github.com/justinjeong5/PS_inha/blob/master/5%EC%A3%BC%EC%B0%A8/prob-W4_P1.pdf)(solved)

그래프 사이클 탐색 알고리즘: Hare and tortoises  
그래프가 주어질때 싸이클을 갖는 서브그래프의 개수는 찾는 문제  

<details>
    <summary>클릭하여 코드보기</summary>

```c++
/*
 *  2020.4.8.
 *  INHA_problem_solving 5-1
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <utility>
#include <climits>

using namespace std;

unordered_map<int, int> um;

const bool VISIT = true;
const bool UNVISITED = false;
int input_size;
int answer = 0;

void solution() {
    answer = input_size;

    for (int idx = 1; idx <= input_size; ++idx) {
        vector<bool> visit(input_size + 1, UNVISITED);
        int cnt = 0;
        visit[idx] = VISIT;
        int pre = idx, cur = um[idx];
        while (true) {
            if (visit[cur]) {
                if (idx == cur) {
                    answer--;
                    break;
                }
                break;
            }
            visit[pre] = VISIT;
            visit[cur] = VISIT;
            pre = cur;
            cur = um[pre];
        }
    }
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case, dst;
    cin >> test_case;
    while (test_case-- != 0) {
        cin >> input_size;
        for (int input_idx = 1; input_idx <= input_size; ++input_idx) {
            cin >> um[input_idx];
        }
        solution();
    }

    return 0;
}

/*
3
7
3 1 3 7 3 4 6
10
4 10 1 4 6 2 8 9 7 5
8
1 2 3 4 5 6 7 8
 */
```

</details>  


	입력의 크기를 N이라 할때 
	시간복잡도: O(N^2)
	하나의 노드에 대하여 O(N)의 시간을 들여 사이클을 탐지하며,
	N개의 노드에 대해 탐색해야하므로 총 O(N^2)이다.

	공간복잡도: O(1)

* [백준 - 9466. 텀 프로젝트 (동일문제)](https://www.acmicpc.net/problem/9466)

### 5.2 [말의 이동](https://github.com/justinjeong5/PS_inha/blob/master/5%EC%A3%BC%EC%B0%A8/prob-W4_P2.pdf)(solved)

BFS를 이용한 최단 경로 탐색문제  
최단경로를 찾는 문제이다. 따라서 깊이우선탐색을 이용하면 탈출조건에 따라서  
필요없는 연산이 많아지므로 너비우선 탐색을 하는것이 논리적으로 간결하다고 생각했다.  

<details>
    <summary>클릭하여 코드보기</summary>

```c++
/*
 *  2020.4.8.
 *  INHA_problem_solving 5-2
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <climits>

using namespace std;

const int UNVISITED = false;
const int VISITED = true;

vector<int> src(2);
vector<int> dst(2);

int board_size;
int answer;
vector<vector<bool>> visit;

struct Dir {
    int y, x;
};
Dir dir[8] = {
        {2,  1},
        {1,  2},
        {2,  -1},
        {1,  -2},
        {-2, 1},
        {-1, 2},
        {-2, -1},
        {-1, -2}
};

void print_answer() {
    cout << answer << '\n';
}

bool is_in_boundary(int &y, int &x) {
    return y >= 0 && x >= 0 && y < board_size && x < board_size;
}

void update_visit(int &y, int &x) {
    visit[y][x] = VISITED;
}

void bfs() {
    visit.clear();
    visit.resize(board_size, vector<bool>(board_size, UNVISITED));
    answer = INT_MAX;

    queue<vector<int>> q;
    //y, x, cnt
    q.push({src[0], src[1], 0});
    update_visit(src[0], src[1]);

    while (!q.empty()) {
        int cur_y = q.front()[0];
        int cur_x = q.front()[1];
        int cur_cnt = q.front()[2];
        q.pop();
        update_visit(cur_y, cur_x);

        if (cur_y == dst[0] && cur_x == dst[1]) {
            answer = min(answer, cur_cnt);
        }
        for (auto &way : dir) {
            int next_y = cur_y + way.y;
            int next_x = cur_x + way.x;
            if (!is_in_boundary(next_y, next_x)) continue;
            if (visit[next_y][next_x]) continue;
            update_visit(next_y, next_x);
            q.push({next_y, next_x, cur_cnt + 1});
        }
    }
}

void solution() {

    bfs();
    print_answer();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case-- != 0) {
        cin >> board_size >> src[0] >> src[1] >> dst[0] >> dst[1];
        solution();
    }

    return 0;
}

/*
 *
4
5
1 0
4 4
8
0 0
7 0
100
0 0
30 50
10
1 1
1 1
 */
```

</details>  


	입력된 장기판(정사각형)의 크기를 N이라고 하면
	시간복잡도: O(N^2)
	공간복잡도: O(N^2)

* [백준 - 7562. 나이트의 이동 (동일문제)](https://www.acmicpc.net/problem/7562)
	
## <6주차>

### 6.1 [회문 판별](https://github.com/justinjeong5/PS_inha/blob/master/6%EC%A3%BC%EC%B0%A8/prob-W5_P1.pdf)(solved)

two pointers  
주어진 문자열이 숫자, 특수문자를 제외하고 회문인지 확인하는 문제

<details>
    <summary>클릭하여 코드보기</summary>

```c++
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
```

</details>  


	입력의 크기를 N이라 할때
	시간복잡도: O(N)
	공간복잡도: O(1)
 
* [Leetcode - 125. Valid Palindrome (동일문제)](https://leetcode.com/problems/valid-palindrome/)

### 6.2 [미로 저택](https://github.com/justinjeong5/PS_inha/blob/master/6%EC%A3%BC%EC%B0%A8/prob-W5_P2.pdf)</a>

BFS와 해시맵을 이용한 최단 경로 탐색문제
최단경로를 찾는 문제이다.  

	입력의 크기를 각각 N: 가로, M: 세로라고 하면
	시간복잡도: O(NM)
	공간복잡도: O(NM)

## <7주차>

### 7.1 [배수](https://github.com/justinjeong5/PS_inha/blob/master/7%EC%A3%BC%EC%B0%A8/prob-Week6_P1.pdf)(solved)

Implementation to string division  
두 수가 정수형의 크기를 넘는 문자열 자료형의 숫자일때 두 수가 배수관계인지 구하는 문제  

<details>
    <summary>클릭하여 코드보기</summary>

```c++
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
```

</details>  


	입력된 두 문자열의 길이를 각각 N, M이라 할때
	시간복잡도: O(max(N, M))
	공간복잡도: O(N + M)

* [직접 찍은 해설 영상 - 배수](https://www.youtube.com/watch?v=8x3SKQr-O9k&t=266s)
* [Leetcode - 415. Add Strings (유사문제)](https://leetcode.com/problems/add-strings/) 
* [Leetcode - 43. Multiply Strings (유사문제)](https://leetcode.com/problems/multiply-strings/)


### 7.2 [연산자](https://github.com/justinjeong5/PS_inha/blob/master/7%EC%A3%BC%EC%B0%A8/prob-Week6_P2.pdf)

문자열로 주어진 수식을 계산하는 문제  
이론적으로는 tree를 이용하여 식을 표현하고  
코드로는 stack을 이용하여 중위표기식을 후위표기식으로 바꾸어 푸는 문제로 유명하다.  

* [백준 - 14888. 연산자 끼워넣기 (유사문제)](https://www.acmicpc.net/problem/14888)
* [백준 - 1918. 중위표기식 (유사문제)](https://www.acmicpc.net/problem/1918)
* [백준 - 1935. 중위표기식2 (유사문제)](https://www.acmicpc.net/problem/1935)

## <8주차>

### 8.1 [수열 조합하기](https://github.com/justinjeong5/PS_inha/blob/master/8%EC%A3%BC%EC%B0%A8/prob-W7_P1.pdf)(solved)☆

순열 permutation  
주어진 배열의 순열 조합을 통해 주어진 범위 안에 있는 경우를 세는 문제  

<details>
    <summary>클릭하여 코드보기</summary>

```c++
/*
 *  2020.4.29.
 *  INHA_problem_solving 8-1
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>
#include <climits>

using namespace std;

int input_size, answer;
vector<int> input;
vector<int> criteria(3);

void print_result() {
    cout << answer << '\n';
}

void resize_input() {
    answer = 0;
    input.clear();
    input.resize(input_size);
}

int sub_power(int &idx) {
    return (int) (((long long int) pow(criteria[2], idx) * input[idx]) % (long long int) 1013);
}

bool is_in_boundary(int &num) {
    return num >= criteria[0] && num <= criteria[1];
}

void solution() {
    sort(input.begin(), input.end());
    do {
        int res = 0;
        for (int idx = 0; idx < input_size; ++idx) {
            res += sub_power(idx);
        }
        res %= 1013;
        if (!is_in_boundary(res)) continue;
        answer++;
    } while (next_permutation(input.begin(), input.end()));
    print_result();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case-- != 0) {
        cin >> input_size;
        resize_input();
        for (int index = 0; index < input_size; ++index) {
            cin >> input[index];
        }
        for (int index = 0; index < 3; ++index) {
            cin >> criteria[index];
        }
        solution();
    }


    return 0;
}

/*
2
3
2 3 4
50 60 4
4
17 5 11 201
450 670 3
 */
```

</details>  


	입력된 배열의 길이를 N이라 할때
	시간복잡도: O(N!)
	공간복잡도: O(N)

* [백준 - 10974. 다음 순열 (유사문제)](https://www.acmicpc.net/problem/10974)

### 8.2 [계획 쇼핑의 제왕](https://github.com/justinjeong5/PS_inha/blob/master/8%EC%A3%BC%EC%B0%A8/prob-W7_P2.pdf)

탐욕법 greedy algorithm  
우선순위 큐를 이용하여 그리디 알고리즘을 사용하는 문제이다.

## <9주차>

### 9.1 [온라인 정렬](https://github.com/justinjeong5/PS_inha/blob/master/9%EC%A3%BC%EC%B0%A8/prob-Week8_P1.pdf)(solved) 

우선순위 큐 priority queue  
주어진 배열 내에서 증가하는 구간을 찾아 값을 누적하는 문제

<details>
    <summary>클릭하여 코드보기</summary>

```c++
/*
 *  2020.5.6.
 *  INHA_problem_solving 9-1
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <climits>

using namespace std;

int input_size, input_boundary;
vector<int> score;
vector<pair<int, int>> input;
int answer, counter = 0;

void resize_input() {
    answer = 0;
    counter = 0;
    score.clear();
    score.resize(input_size);
    input.clear();
    input.resize(input_size);
}

void print_answer() {
    cout << answer << "\n";
}

bool comparator(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}

void solution() {
    sort(input.begin(), input.end(), comparator);
    for (int idx = 1; idx < input_size; ++idx) {
        if(input[idx-1].first > input[idx].first){
            answer += score[counter];
            counter = 0;
            continue;
        }
        counter++;
    }
    answer += score[counter];
    print_answer();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case-- != 0) {
        cin >> input_size >> input_boundary;
        resize_input();
        for (int idx = 0; idx < input_size; ++idx) {
            cin >> score[idx];
        }
        for (int idx = 0; idx < input_size; ++idx) {
            cin >> input[idx].first >> input[idx].second;
        }
        solution();
    }


    return 0;
}

/*
2
5 30
1 4 8 16 32
1 1
30 5
28 4
29 3
15 2
6 100
1 2 3 100 200 300
95 6
8 1
98 5
77 4
31 3
2 2
 */
```

</details>  


	입력된 배열의 길이를 N이라 할때
	시간복잡도: O(N)
	공간복잡도: O(1)

* [Leetcode - 121. Best Time to Buy and Sell Stock (유사문제)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

### 9.2 [LCS](https://github.com/justinjeong5/PS_inha/blob/master/9%EC%A3%BC%EC%B0%A8/prob-Week8_P2.pdf) (solved)☆

동적계획법 Dynamic programming  
cache정보를 이용하여 미리 계산해둔 문자열간의 유사도를 기반으로  
다음 문자열에 대한 유사도를 구하는 문제이다.

<details>
    <summary>클릭하여 코드보기</summary>

```c++
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
const int TXT1_SIZ = text1.size();
const int TXT2_SIZ = text2.size();
vector<vector<int>> cache;

void preprocess() {
    cache.clear();
    cache.resize(TXT1_SIZ, vector<int>(TXT2_SIZ, 0));
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
```

</details>  


	입력된 두 문자열의 길이를 각각 N, M이라 할때  
	시간복잡도: O(NM)
	공간복잡도: O(NM)

* [직접 찍은 해설 영상 - LCS](https://www.youtube.com/watch?v=7mpi-VAfFIw&t=335s)
* [Leetcode - 1143. Longest Common Subsequence (동일문제)](https://leetcode.com/problems/longest-common-subsequence/)
  
## <10주차>

### 10.1 [배낭싸기](https://github.com/justinjeong5/PS_inha/blob/master/10%EC%A3%BC%EC%B0%A8/prob-W9_P1.pdf) (solved)

탐욕법 greedy algorithm  
NP-complete 분야에서 매우 유명한 문제중 하나인 knapsack을 변형한 문제  

<details>
    <summary>클릭하여 코드보기</summary>

```c++
/*
 *  2020.5.13.
 *  INHA_problem_solving 10-1
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <climits>

using namespace std;

int input_amount = 0;
int input_weight = 0;
int answer = 0;
vector<vector<int>> items;
// { amount, weight, value }

void preprocess() {
    items.clear();
    items.resize(input_amount, {0, 0, 0});
    answer = 0;
}

void find_item_value() {
    for (int index = 0; index < input_amount; ++index) {
        items[index][2] = items[index][1] / items[index][0];
    }
}

bool cmp(vector<int> &a, vector<int> &b) {
    return a[2] > b[2];
}

void print_answer() {
    cout << answer << '\n';
}

void solution() {
    find_item_value();
    sort(items.begin(), items.end(), cmp);

    for (int index = 0; index < input_amount; ++index) {
        if (input_weight <= 0) break;
        const int cnt = input_weight > items[index][0] ? items[index][0] : input_weight;
        input_weight -= cnt;
        answer += items[index][2] * cnt;
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
        cin >> input_amount >> input_weight;
        input_resize();
        for (int input = 0; input < input_amount; ++input) {
            cin >> items[input][0];
        }
        for (int input = 0; input < input_amount; ++input) {
            cin >> items[input][1];
        }
        solution();
    }

    return 0;
}

/*
2
7 95
36 14 48 32 61 43 29
36 56 240 320 61 43 290
6 73
26 71 6 37 12 15
234 639 54 111 96 150
 */
```

</details>  


	입력된 내용중 물건의 종류를 T라고 할때
	시간복잡도: O(T logT)
	공간복잡도: O(1)

* [백준 - 12865. 평범한 배낭 (유사문제)](https://www.acmicpc.net/problem/12865)

### 10.2 [배낭싸기](https://github.com/justinjeong5/PS_inha/blob/master/10%EC%A3%BC%EC%B0%A8/prob-W9_P2.pdf) (solved)

동적계획법 Dynamic programming  
NP-complete 분야에서 매우 유명한 문제중 하나인 knapsack을 변형한 문제  
cache정보를 이용하여 미리 계산해둔 값을 기반으로 다음 값을 추적한다  

<details>
    <summary>클릭하여 코드보기</summary>

```c++
/*
 *  2020.5.13.
 *  INHA_problem_solving 10-2
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int input_amount, input_weight;
vector<pair<int, int>> items;
vector<int> cache;

void resize_input() {
    items.clear();
    items.resize(input_amount, {0, 0});
    cache.clear();
    cache.resize(input_weight + 1, 0);
}

void update_cache(int left, int right) {
    cache[right] = max(cache[right], cache[right - items[left].first] + items[left].second);
}

void print_answer() {
    cout << cache[input_weight] << '\n';
}

void solution() {
    for (int left = 0; left < input_amount; left++) {
        for (int right = input_weight; right >= 1; right--) {
            if (items[left].first > right) continue;
            update_cache(left, right);
        }
    }
    print_answer();
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test_case;
    cin >> test_case;

    while (test_case-- != 0) {
        cin >> input_amount >> input_weight;
        resize_input();
        for (int i = 0; i < input_amount; i++) {
            cin >> items[i].first;
        }
        for (int i = 0; i < input_amount; i++) {
            cin >> items[i].second;
        }

        solution();
    }

    return 0;
}

/*
2
4 7
6 4 3 5
13 8 6 12
5 11
7 2 8 9 3
6 8 12 4 9
 */
```

</details>  


	입력된 내용중 물건의 종류를 T, 무게의 최대치를 W라고 할때
	시간복잡도: O(TW)
	공간복잡도: O(W)
	
* [백준 - 12865. 평범한 배낭 (동일문제)](https://www.acmicpc.net/problem/12865)


## <11주차>

### 11.1 [구슬의 작용과 반작용](https://github.com/justinjeong5/PS_inha/blob/master/11%EC%A3%BC%EC%B0%A8/prob-W10_New1.pdf) (solved)

sorting 정렬 알고리즘  
어려워 보이지만 문제를 모델링 해보면 간단한 정렬 문제이다.  
정렬의 기준은 현재의 위치를 기준으로 계속 진행했을때 떨어지는데 걸리는 시간으로 한다.  

<details>
    <summary>클릭하여 코드보기</summary>

```c++
/*
 *  2020.5.27.
 *  INHA_problem_solving 11-1
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int input_amount, input_length, target;
vector<vector<int>> input;
//입력받은 시작 위치, 떨어지는데 걸리는 시간

void input_resize() {
    input.clear();
    input.resize(input_amount, {0, 0});
}

void get_drop_time() {
    for (int index = 0; index < input_amount; ++index) {
        if (input[index][0] > 0) {
            input[index][1] = input_length - input[index][0];
            continue;
        }
        input[index][1] = -input[index][0];
    }
}

bool cmp(vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
}

void sorting() {
    sort(input.begin(), input.end(), cmp);
}

void print_answer() {
    cout << input[target - 1][1] << '\n';
}

void solution() {
    get_drop_time();
    sorting();
    print_answer();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;

    while (test_case-- != 0) {
        cin >> input_amount >> input_length >> target;
        input_resize();
        for (int index = 0; index < input_amount; ++index) {
            cin >> input[index][0];
        }
        solution();
    }
    return 0;
}

/*
 2
 7 40 4
 3 -30 14 -7 -21 33 24
 6 30 5
 5 -9 11 13 -18 25
 */

```

</details>  

	입력된 구슬의 개수를 N이라고 할때
	시간복잡도: O(N logN)
	공간복잡도: O(N)

* [직접 찍은 해설 영상 - 구슬의 작용반작용](https://youtu.be/FRl5jKBWe_Y)  
  


## <12주차>

### 12.1 [가까운 카드쌍 찾기](https://github.com/justinjeong5/PS_inha/blob/master/12%EC%A3%BC%EC%B0%A8/prob-W11_N.pdf) (solved)

greedy algorithm 그리디 알고리즘  
bruth force 완전 탐색  
거리가 가까운 카드의 쌍을 규칙에 따라 출력하는 문제  


<details>
    <summary>클릭하여 코드보기</summary>

```c++
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

int get_distance(vector<int> &a, vector<int> &b);

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

bool cmp_res(TwoCards &a, TwoCards &b) {
    if ((a.card1[2] + a.card2[2]) == (b.card1[2] + b.card2[2]))
        return (a.card1[1] + a.card2[1]) < (b.card1[1] + b.card2[1]);
    return (a.card1[2] + a.card2[2]) < (b.card1[2] + b.card2[2]);
}

bool cmp_res2(TwoCards &a, TwoCards &b) {
    return a.number < b.number;
}

void print_result(TwoCards &cur) {
    cout << static_cast<char>(cur.number + 'A') << " " << cur.card1[1] << " " << cur.card1[2]
         << " " << cur.card2[1] << " " << cur.card2[2] << '\n';
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

```

</details>  

	입력된 카드의 개수를 N이라고 할때
	시간복잡도: O(N^3)
	공간복잡도: O(N)

* [직접 찍은 해설 영상 - 가까운 카드 쌍 찾기](https://youtu.be/4r9054zK1n0)  
  
-EOF-