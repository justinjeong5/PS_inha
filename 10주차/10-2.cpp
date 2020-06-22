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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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