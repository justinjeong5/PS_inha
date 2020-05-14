# PS_inha
Problem Solving Inha Univ. 2020 spring  

collaborator: [ellyheetov](https://github.com/ellyheetov)

## <1주차>
### 1.1  [DNA 대표서열](https://github.com/justinjeong5/PS_inha/blob/master/1%EC%A3%BC%EC%B0%A8/prob-DNA1-1.pdf)

최소편집거리 알고리즘 (minimum edit distance algorithm)  
주어진 문자열의 최소편집거리의 합을 구하고, 모든 문자열의 편집거리가 최소인 문자열을 구하는 문제  

	입력된 두 문자열의 길이를 각각 N, M이라고 할때
	시간복잡도: O(NM)
	공간복잡도: O(NM)

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
### 2.1 [오류정정](https://github.com/justinjeong5/PS_inha/blob/master/2%EC%A3%BC%EC%B0%A8/prob-Error.pdf)(solved)

최소편집거리 알고리즘 (minimum edit distance algorithm)  
주어진 문자열의 최소편집거리를 이용하여, 원래 문자열이 무엇이었는지 알아내는 문제  

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
### 3.1 [게임개발계획](https://github.com/justinjeong5/PS_inha/blob/master/3%EC%A3%BC%EC%B0%A8/prob-Game.pdf)(solved)

그리디 알고리즘 (Greedy algorithm)  
그리디 알고리즘의 대표문제로 유명한 회의실 배정문제와 상당히 유사한 문제  

	입력의 크기를 N이라 할때  
	시간복잡도: O(N logN)
	공간복잡도: O(N)

* [백준 - 1931. 회의실 (동일문제)](https://www.acmicpc.net/problem/1931)

### 3.2 [최소문자열 탐색](https://github.com/justinjeong5/PS_inha/blob/master/3%EC%A3%BC%EC%B0%A8/prob-String.pdf)

슬라이딩 윈도우 알고리즘 (sliding window)  
슬라이딩 윈도우 방식을 이용하여 최소 길이 부분 문자열을 구하는 문제  

	입력된 크기를 각각 N: 긴 문자열의 길이, M: 짧은 문자열의 길이라고 할때
	시간복잡도: O(N)
	공간복잡도: O(N+M)

* [Leetcode - 76. Minimum Window Substring (동일문제)](https://leetcode.com/problems/minimum-window-substring/)


## <4주차>
### 4.1 [움직이는 하노이탑](https://github.com/justinjeong5/PS_inha/blob/master/4%EC%A3%BC%EC%B0%A8/prob-W3_P1.pdf)(solved)
 
원형 배열(circular qrray)  
원형 배열의 개념이 포함된 문제  

	입력의 크기를 N이라 할때
	시간복잡도: O(N^2)
	공간복잡도: O(N)

* [프로그래머스 - 42891. 무지의 먹방 라이브 (유사문제)](https://programmers.co.kr/learn/courses/30/lessons/42891)

### 4.2 [움직이는 하노이탑](https://github.com/justinjeong5/PS_inha/blob/master/4%EC%A3%BC%EC%B0%A8/prob-W3_P2.pdf)(solved)

앞선 4.1번의 문제에서 입력의 크기가 매우 커진 형태이다.  
따라서 O(N^2)의 속도로는 풀리지 않는다
해시맵을 사용하여 탐색 단계에서의 속도를 O(1)으로 하여 속도를 빠르게 하였다.  

	입력의 크기를 N이라 할때
	시간복잡도: O(N)
	공간복잡도: O(N)

* [프로그래머스 - 42891. 무지의 먹방 라이브 (유사문제)](https://programmers.co.kr/learn/courses/30/lessons/42891)

## <5주차>

### 5.1 [팀원 구하기](https://github.com/justinjeong5/PS_inha/blob/master/5%EC%A3%BC%EC%B0%A8/prob-W4_P1.pdf)(solved)

그래프 사이클 탐색 알고리즘: Hare and tortoises  
그래프가 주어질때 싸이클을 갖는 서브그래프의 개수는 찾는 문제  

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

	입력된 장기판(정사각형)의 크기를 N이라고 하면
	시간복잡도: O(N^2)
	공간복잡도: O(N^2)

* [백준 - 7562. 나이트의 이동 (동일문제)](https://www.acmicpc.net/problem/7562)
	
## <6주차>

### 6.1 [회문 판별](https://github.com/justinjeong5/PS_inha/blob/master/6%EC%A3%BC%EC%B0%A8/prob-W5_P1.pdf)(solved)

two pointers  
주어진 문자열이 숫자, 특수문자를 제외하고 회문인지 확인하는 문제

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

### 8.1 [수열 조합하기](https://github.com/justinjeong5/PS_inha/blob/master/8%EC%A3%BC%EC%B0%A8/prob-W7_P1.pdf)(solved)

순열 permutation  
주어진 배열의 순열 조합을 통해 주어진 범위 안에 있는 경우를 세는 문제  

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

	입력된 배열의 길이를 N이라 할때
	시간복잡도: O(N)
	공간복잡도: O(1)

* [Leetcode - 121. Best Time to Buy and Sell Stock (유사문제)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

### 9.2 [LCS](https://github.com/justinjeong5/PS_inha/blob/master/9%EC%A3%BC%EC%B0%A8/prob-Week8_P2.pdf) (solved)

동적계획법 Dynamic programming  
cache정보를 이용하여 미리 계산해둔 문자열간의 유사도를 기반으로  
다음 문자열에 대한 유사도를 구하는 문제이다.

	입력된 두 문자열의 길이를 각각 N, M이라 할때  
	시간복잡도: O(NM)
	공간복잡도: O(NM)

* [직접 찍은 해설 영상 - LCS](https://www.youtube.com/watch?v=7mpi-VAfFIw&t=335s)
* [Leetcode - 1143. Longest Common Subsequence (동일문제)](https://leetcode.com/problems/longest-common-subsequence/)
  
## <10주차>

### 10.1 [배낭싸기](https://github.com/justinjeong5/PS_inha/blob/master/10%EC%A3%BC%EC%B0%A8/prob-W9_P1.pdf) (solved)

탐욕법 greedy algorithm  
NP-complete 분야에서 매우 유명한 문제중 하나인 knapsack을 변형한 문제  

	입력된 내용중 물건의 종류를 T라고 할때
	시간복잡도: O(T logT)
	공간복잡도: O(1)

* [백준 - 12865. 평범한 배낭 (유사문제)](https://www.acmicpc.net/problem/12865)

### 10.2 [배낭싸기](https://github.com/justinjeong5/PS_inha/blob/master/10%EC%A3%BC%EC%B0%A8/prob-W9_P2.pdf) (solved)

동적계획법 Dynamic programming  
NP-complete 분야에서 매우 유명한 문제중 하나인 knapsack을 변형한 문제  
cache정보를 이용하여 미리 계산해둔 값을 기반으로 다음 값을 추적한다  

	입력된 내용중 물건의 종류를 T, 무게의 최대치를 W라고 할때
	시간복잡도: O(TW)
	공간복잡도: O(W)
	
* [백준 - 12865. 평범한 배낭 (동일문제)](https://www.acmicpc.net/problem/12865)

-EOF-