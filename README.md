# Programmers

## 양과 늑대 92343 (카카오 기출) 

- [ ] 1회차
- [ ] 2회차
- [ ] 3회차

#### https://school.programmers.co.kr/learn/courses/30/lessons/92343

#### https://github.com/HongYouBin/Programmers/blob/main/92343.cpp

- 비트마스크를 이용한 완전 탐색문제이다. DP처럼 메모이제이션을 이용하여 풀 수도 있다. 비트마스크 개념이 앞으로 자주 쓰일 것 같으니 익혀둬야 한다.
  - https://velog.io/@qwe910205/%EB%B9%84%ED%8A%B8%EB%A7%88%EC%8A%A4%ED%81%AC
- 현재 노드에서 다음 노드로 조건을 따져야 한다. 조건을 만족하면 num 변수에 해당 노드를 방문했다는 비트를 찍고 넘겨야 한다.
- 매번 재귀 단계에서 방문한 비트를 참고하여 양과 늑대의 수를 세주고 양의 최대 값을 갱신하는 방법으로 해당 문제를 풀 수 있다.

## 피로도 87946

#### https://school.programmers.co.kr/learn/courses/30/lessons/87946

#### https://github.com/HongYouBin/Programmers/blob/main/87946.cpp

- 완전탐색 문제이다. K의 수가 8밖에 되지 않아 완전탐색으로 풀 수 있다. 처음에 그리디 문제인가 고민했다. K의 수가 8인 것을 확인한 순간 그리디 고민을 멈추고 완전탐색으로 넘어가야 했다. 최대한 빨리 풀이 방안을 고민하고, 명백한 방법이 보이면 애매한 방법을 버리고 넘어가서 풀자.
- 순열 사용을 위해 bin vector를 생성했는데, 그럴 필요 없이 dungeons vector를 오름차순 정렬한 후 바로 사용하면 간단하게 풀 수 있었다.
- dungeons vector에서 방문하지 않은 vector를 다시 생성하여 재귀로 넘겨주는 방법으로 푼 사람도 있고, dfs를 사용해서 푼 사람도 눈에 띄었다.

## 섬 연결하기

#### https://school.programmers.co.kr/learn/courses/30/lessons/42861

#### https://github.com/HongYouBin/Programmers/blob/main/42861.cpp

- 크루스칼로 해결했다.(그리디)

## 연속 부분 수열 합의 개수

#### https://school.programmers.co.kr/learn/courses/30/lessons/131701

#### https://github.com/HongYouBin/Programmers/blob/main/131701.cpp

- map을 사용해서 완전 탐색으로 해결했다.
- 길이가 1인 연속 합부터, 길이가 elements의 크기인 연속 합까지 for문으로 차례대로 구했다.
- 다른 사람의 풀이를 보니 기준 인덱스를 정한 후, 정한 인덱스부터 다른 인덱스를 차례로 방문하여 합을 구해 set에 넣어주고, 기준 인덱스를 옮기는 방식으로 해결했다.

## 숫자 타자 대회

#### https://school.programmers.co.kr/learn/courses/30/lessons/136797

#### https://github.com/HongYouBin/Programmers/blob/main/136797.cpp

- dfs를 사용한 완전 탐색으로 풀면 시간 초과가 발생한다. 매 number마다 왼손으로 누를지, 오른손으로 누를지 2개의 경우의 수가 발생하기 때문에 2^(100000) 시간 복잡도가 발생한다. 따라서 메오이제이션을 사용하는 dp개념을 활용해야 한다. 즉 dfs+dp 활용
- 매 단계(level) 왼손 위치, 오른손 위치에 따라 나오는 결과값을 dp 배열에 저장한다. 그 후 단계, 왼손 위치, 오른손 위치가 dp에 저장된 값이면 계산을 하지 않고 dp 배열 값을 참조하면서, 시간복잡도를 줄일 수 있다.
- 완전 탐색으로 설계한 후, 시간 복잡도를 줄여야 하면 dp의 메모이제이션 개념을 떠올려 봐야 한다.

## 입국심사

#### https://school.programmers.co.kr/learn/courses/30/lessons/43238

#### https://github.com/HongYouBin/Programmers/blob/main/43238.cpp

- 이분탐색으로 구현했다.
- 시간을 정한 후 해당 각 시간안에 심사관이 몇 명을 심사하는지 계산한 후 n보다 작으면 시간을 늘려주고, n보다 크거나 같으면 시간을 줄여줬다.

## 두 큐 합 같게 만들기

#### https://school.programmers.co.kr/learn/courses/30/lessons/118667

#### https://github.com/HongYouBin/Programmers/blob/main/118667.cpp

- 그리디로 구현했다.
- 합이 큰 큐를 pop한 후 합이 작은 큐에 push 했다.
- 언제 -1을 return 해야 하는지 기준을 설정하는 부분이 까다로웠다. 계산을 해보니 각각 queue 길이 합의 2배를 하면 처음 큐의 상태로 돌아왔다. 따라서 2\*(큐1의 길이+큐2의 길이)가 답이 된다.

## 교점에 별 만들기

#### https://school.programmers.co.kr/learn/courses/30/lessons/87377

#### https://github.com/HongYouBin/Programmers/blob/main/87377.cpp

- 구현하면서 까다로운 부분이 3가지 있었다. 첫 번째로는 정수판단 여부이다. 생각보다 간단하게 했는데 나눈 값을 mod연산하여 0인지 아닌지로 판단하는 방법과 구한 값과 int로 캐스팅한 값을 빼서 0인지 아닌지 판단하는 방법이 있다. 비슷한 문제가 나오면 잊지 말고 활용해야 한다.
- 최대한 작은 배열을 생성해 return해야 하는 조건이 까다로웠다. 최대 Y값을 구한 y값에서 뺀다. 구한 x값을 최소 x값에 빼는 방법으로 구현했다.
- core dumped가 발생해서, 그 이유를 알고 처리하는 과정이 까다로웠다. 알고보니 두 직선의 교점을 구하는 방법에서 각각의 A, B, C를 곱해줘야 하는데, 그 과정에서 최대값이 10^10 이 된다. int의 최대 값이 10^9이기 때문에 long long 타입을 사용해야한다. core dumped가 메모리에 잘못되게 접근했기 때문에 발생하는데, 지금은 오버플로우 때문에 발생한듯 싶다. 변수의 최대값을 미리 구한 후 데이터 타입을 고려해줘야 하고, 문제 없이 풀었는데도 메모리에 오류가 발생하면 데이터 타입을 적절히 설정했나 검토해야 한다.

## k진수에서 소수 만들기 (카카오 기출, 다시 풀 것)

- [ ] 1회차
- [ ] 2회차
- [ ] 3회차

#### https://school.programmers.co.kr/learn/courses/30/lessons/92335

#### https://github.com/HongYouBin/Programmers/blob/main/92335.cpp

- 정수 n의 소수 판별을 위해 2부터 n의 제곱근까지 나누어 떨어지는지 확인하면 된다는 아이디어를 떠올렸고 시간을 줄일 수 있었다.
- P가 0이 아닌 소수라는 점을 이용해 k 진수로 바꿨을 때 0을 기준으로 끊으면 된다는 아이디어도 문제를 풀면서 떠올렸다.
- 핵심적인 두 개의 아이디어를 떠올렸는데도 문제를 푸는데 애를 먹었다. 우선 k 진수를 만드는 방법에서 애를 먹었다. n을 k로 나눈 나머지를 거꾸로 저장하는 방법을 고민했다. 나머지가 2자리 수가 넘어가면 구현이 복잡해지기 때문이다. 방법은 생각보다 간단했는데, k가 10이기 때문에 나머지의 최대수는 9이다. 1부터 9이기 때문에 한 자리 숫자이고 따라서 string 으로 저장한 후 reverse()로 돌리면 된다. reverse()를 까먹지 않고 활용해야 한다.
- k 진수 생성 후, 0으로 끊은 후 에라토스테네스 체를 만들어 소수를 판별했는데 오류가 발생했다. 에라토스테네스 체를 만들면 최대 수를 고려하여 메로리를 할당해야 하는데, 메모리 초과가 발생한다. 따라서 에라토스테네스의 체를 생성하지 말고, 0으로 끊긴 정수마다 2부터 구한 정수의 제곱근까지 for 문을 써서 나누어 떨어지나 따져줘야 했다.
- 1번 test case가 풀리지 않아 답을 참고해줬는데, k 진수로 생성된 수가 int 형을 벗어날 수 있다. n의 최대 수인 1,000,000을 2진수로 구현해야 하면 약 2를 20번 나눠야 하고, 이는 2진수가 20자리까지 나온다는 사실을 의미한다. int일 때 10자리 까지 연산이 가능하기 때문에 int로 구현하면 오류가 발생한다. 따라서 long long 을 써줘야 한다. 미리 변수 할당 전 메모리를 계산하여 변수 타입을 결정해줘야 한다.

## 전력망을 둘로 나누기

#### https://school.programmers.co.kr/learn/courses/30/lessons/86971

#### https://github.com/HongYouBin/Programmers/blob/main/86971.cpp

- 완전탐색으로 구현했다. 그래프 이론까지 추가된 문제이다.
- 전력망을 하나씩 끊은 후, bfs를 통해 2개의 전력망의 개수를 구하는 방법으로 구현했다.
- bfs를 사용하지 않고, bfs를 사용하는 방법도 있었다. 총 몇번의 노드를 지나왔는지 기록하는 배열(기록 배열)을 할당한 후 dfs를 써서 순차적으로 조회한다. 매 단계마다 다음 조회할 노드의 기록 배열 + 1 을 현재 노드의 기록 배열에 저장한다. 그 후 전력망을 차단 했을 때 차단한 노드의 기록 배열과, 전체 노드의 개수-차단한 노드의 기록 배열을 비교한다. 해당 방법을 사용하면 내가 푼 방법보다 쉽게 풀 수 있다. 우선 경로(edge)의 개수가 n-1개이기 때문에 사이클이 발생하지 않는다. 따라서 각 노드마다 다른 노드와 1개밖에 연결되지 않기 때문에 해당 문제를 풀 수 있다.

  - https://school.programmers.co.kr/learn/courses/30/lessons/86971/solution_groups?language=cpp

## 거리두기 확인하기 (카카오 인턴 기출)

#### https://school.programmers.co.kr/learn/courses/30/lessons/81302

#### https://github.com/HongYouBin/Programmers/blob/main/81302.cpp

- bfs를 사용하여 응시자가 있는 좌표로부터 테이블 거리 2 이내를 완전 탐색하여 다른 사람이 있는 확인하는 방법으로 구현했다.
- 다른 사람들의 풀이를 보니 더 좋은 방법이 있었다. 배열을 생성해 응시자가 있는 좌표로부터 한 칸 떨어진 거리에 true로 선언한다. 응시자가 각각 한 칸 떨어진 좌표에 true를 선언하는 과정에서 이미 true가 선언됐다면 두 칸 이내에 다른 응시자가 있다는 의미이고, false를 return하면 된다. bfs처럼 복잡한 과정을 쓰지 않아 내가 풀은 방법보다 간단하고, 시간도 절약하면서 해결했다.
- https://school.programmers.co.kr/learn/courses/30/lessons/81302/solution_groups?language=cpp

## 풍선 터트리기

#### https://school.programmers.co.kr/learn/courses/30/lessons/68646

#### https://github.com/HongYouBin/Programmers/blob/main/68646.cpp

- 각 번호를 조회한다. 한 번호를 기준으로 왼쪽 방향에서 가장 작은 수와 오른쪽 방향에서 가장 작은 수를 비교한다. 번호가 작은 풍선을 1번만 터트릴 수 있기 때문에 기준 번호가 구한 두 수 중 한 개보다 크기만 하면 남길 수 있다.

## 점 찍기

#### https://school.programmers.co.kr/learn/courses/30/lessons/140107

#### https://github.com/HongYouBin/Programmers/blob/main/140107.cpp

- b의 수를 정한다고 가정할 때 a의 최대 값은
  > $$ \sqrt{d^2-(bk)^2/k^2} $$
  > 이다. 따라서 b에 따른 최대 a를 구한 후 답을 더해주면 된다.
- 잘 구현했는데도 오답이 발행했다. 알고보니 long long 타입과, int 타입을 연산해줘서 오류가 발생했다. long long 타입을 쓸 때 형 변환에 신경 쓰도록 하자.
- C++ 제곱근 공식 cmath 헤더 추가하자.
  - https://manniz.tistory.com/entry/C%EC%96%B8%EC%96%B4-%EB%A3%A8%ED%8A%B8%EC%A0%9C%EA%B3%B1%EA%B7%BC-%EC%9D%84-%EA%B5%AC%ED%95%98%EB%8A%94-2%EA%B0%80%EC%A7%80-%EB%B0%A9%EB%B2%95sqrt-pow-%EC%86%8C%EC%8A%A4-%EC%BD%94%EB%93%9C

## 스타 수열(다시 풀 것)

- [ ] 1회차
- [ ] 2회차
- [ ] 3회차

#### https://school.programmers.co.kr/learn/courses/30/lessons/70130

#### https://github.com/HongYouBin/Programmers/blob/main/70130.cpp

- 처음에 완전탐색을 고민했다. 경우의 수가 2^500000 가 나오기 때문에 적용할 수 없다. dp의 메모이제이션을 고민해봤는데, 도저히 사용할 방법이 떠오르지 않았다.
- 처음에 교집합을 정한 후 a 배열을 모두 돌면서 교집합과 겹치는 부분을 체크하면서 답을 갱신해줬다. 문제점은 최악의 경우 시간복잡도가 O(500000^2)가 된다는 것이다. 시간 복잡도를 줄일 필요가 있었다.
- 시간 복잡도를 어떻게 줄일까 고민하다 다른 사람의 풀이를 보니 명확해졌다. 정수 x를 교집합으로 정한다고 가정하면 스타 수열 최대값은 x가 배열 a에 등장하는 회수보다 작거나 같다. 따라서 이미 구한 스타 수열의 최대 길이가 정수 x의 등장 횟수보다 작으면 셀 필요가 없고, 해당 방법으로 문제를 해결했다.

## 합승 택시 요금

#### https://school.programmers.co.kr/learn/courses/30/lessons/72413

#### https://github.com/HongYouBin/Programmers/blob/main/72413.cpp

- 플로이드 와샬 알고리즘으로 한 점에서 다른 점까지의 최소 경로를 기록한 표를 만들었다. 그 후 기준점을 만들어 (시작 지점에서 기준점까지 최소 경로 + 기준점에서 A 까지 최소 경로, 기준점에서 B 까지 최소 경로)를 구해 가장 작은 값을 리턴하도록 했다.
- n이 최대 200이기 때문에 플로이드 알고리즘을 사용한다면 시간복잡도가 O(10^7)이 된다. 따라서 시간 안에 해결 가능하다.
- 다른 사람의 풀이를 보니 다익스트라 알고리즘을 사용하여 a와 다른 지점의 최단 경로, b와 다른 지점의 최단 경로, s와 다른 지점의 최단 경로를 기록한 표를 만들어 정답을 갱신했다.

## 경주로 건설 (카카오 기출)

#### https://school.programmers.co.kr/learn/courses/30/lessons/67259

#### https://github.com/HongYouBin/Programmers/blob/main/67259.cpp

- 배열의 최대 크기가 25\*25이기 때문에 완전탐색을 구현할 수 있었다. 최단 경로를 구할 때 완전탐색보다 다익스트라가 편해보여서 다익스트라로 구현했다.
- 한 배열에서 다른 배열로 갈 때 방향을 유지하면 경로를 기존 거리에 100을 더한 값을 우선순위 큐에 넣어줬고, 방향을 바꿀때 기존 거리에 600을 더한 값(방향 바꾸는 비용 500, 바꾼 방향으로 진행하는 비용 100)을 우선순위 큐에 넣어 구현했다.
- 다른 사람들의 풀이를 보니 대부분 bfs, dfs를 사용해서 구현했다. 큐, 스택에 방향을 유지할 때 100을 넣고, 방향을 바꿀 때 600을 넣었다.
- 우선순위 큐를 비교연산자 구현해야 했다.
  - https://hydroponicglass.tistory.com/169

## 경주로 건설 (카카오 기출)

#### https://school.programmers.co.kr/learn/courses/30/lessons/67259

#### https://github.com/HongYouBin/Programmers/blob/main/67259.cpp

- 투 포인터로 구현했다.
- 앞 뒤 포인터로 모든 보석이 모인 연속한 집합을 구한 후 거리를 계산해준다. 가장 적은 거리를 가진 연속 집합이 정답이 된다.

## 양궁 (카카오 기출)

#### https://school.programmers.co.kr/learn/courses/30/lessons/92342

#### https://github.com/HongYouBin/Programmers/blob/main/92342.cpp

- 완전탐색으로 구현했다.
- 라이언이 피치보다 1개 더 쏘면 이기기 때문에 이겨야 하는 라운드를 정한 후 해당 라운드의 라이언의 화살의 수를 피치보다 1개 더 많이 쏘도록 만들었다.
- dfs로도 구현 가능하다. 단계가 총 11개고 화살의 최대 수가 10개 이기 때문에 모든 경우의 수를 dfs로 구현 가능하다.

## 멀쩡한 사각형

#### https://school.programmers.co.kr/learn/courses/30/lessons/62048

#### https://github.com/HongYouBin/Programmers/blob/main/62048.cpp

- 대각선이 지나치는 총 개수가 가로, 새로 길이의 최대 공약수라는 사실을 알게되면 쉽게 구현 가능하다.
  - https://kim519620.tistory.com/entry/%EB%A9%80%EC%A9%A1%ED%95%9C-%EC%82%AC%EA%B0%81%ED%98%95-feat-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-62048%EB%B2%88

## 불량 사용자(카카오 기출)

- [ ] 1회차
- [ ] 2회차
- [ ] 3회차

#### https://school.programmers.co.kr/learn/courses/30/lessons/64064

#### https://github.com/HongYouBin/Programmers/blob/main/64064_1.cpp

#### https://github.com/HongYouBin/Programmers/blob/main/64064_2.cpp

#### https://github.com/HongYouBin/Programmers/blob/main/64064_3.cpp

- 처음에 이진 탐색으로 풀어야 하나 고민했다. 하지만 배열의 최대 크기가 8이기 때문에 굳이 이진 탐색으로 풀 필요가 없다는 사실을 깨달았고, 완전 탐색으로 방향을 바꾸었다.
- 첫 번째 방법은 틀린 접근이었다. banned_id 크기만큼 user_id에서 스트링을 뽑는다. 뽑은 스트링에서 '*'를 붙여 만들 수 있는 모든 스트링을 만들어 맵에 저장한 후 banned_id에 map을 조회하도록 했다. 문제는 하나의 user_id에서 2개 이상의 banned_id를 만족하는 *을 붙인 스트링을 생성할 수 있다는 것이다. 예를 들어 banned_id가 \*rodo만 갖고 있고 user_id가 prodo, crodo라고 하면 1개의 banned_id에 2개의 user_id가 만족하게 된다는 문제점이 있다. 따라서 해당 접근 방법은 틀렸다.
  - https://github.com/HongYouBin/Programmers/blob/main/64064_1.cpp
- 두 번째 접근도 잘못됐다. 마찬가지로 user_id에서 banned_id 크기만큼 문자열을 뽑았다. 그 후 for문으로 모든 user 문자열과, banned 문자열을 비교하는 방법으로 구현했다. 문제점은 한 개의 banned_id가 user_id를 선점하면, 다른 banned_id가 선점된 user_id를 선택하지 못한다는 것이다. 예를 들어보겠다. user_id가 frodo, crodo이고 banned_id가 fr*d*, *rodo이라고 가정하자. frodo가 *rodo, fr*d* 둘 다 적용 가능하고 crodo는 *rodo만 적용 가능하다. 이때 frodo가 *rodo를 선점한다고 할 때 crodo는 아무 것도 선점하지 못하게 된다. 따라서 답인 frodo와 crodo가 나오지 못하고, frodo만 나오게 된다.
  - https://github.com/HongYouBin/Programmers/blob/main/64064_2.cpp
- 따라서 dfs를 사용한 조합으로 구현해야 한다. dfs를 사용해서 모든 경우의 수를 따져줘야 하고, 제재 아이디가 생성되면 생성된 값을 조합으로(순서에 상관 없이) 저장해야 한다. 따라서 dfs로 user_id가 banned_id를 기준으로 일치하는지 확인한 후 다른 user_id와도 일치하는지 확인하는 방법으로 구현했다. 두 문자열이 일치하면 bitmap 마스킹으로 넘겨 조합으로 순서에 상관 없이 map에 저장되도록 만들었다.
  - https://github.com/HongYouBin/Programmers/blob/main/64064_3.cpp

## 구명보트

#### https://school.programmers.co.kr/learn/courses/30/lessons/42885

#### https://github.com/HongYouBin/Programmers/blob/main/42885.cpp

- 구명보트에 최대 2명이라는 조건을 보지 못해 오름차순 정렬 후 작은 수부터 구명보트를 채우려고 했다. 물론 오답이 발생했다.
- 최대 2명이라는 조건 때문에 몸무게가 제일 작은 사람과 제일 큰 사람을 태워야 한다. 2명을 몸무게가 작은 순부터 채우면 순서가 뒤로 갈수록 큰 사람끼리 2명을 채워야 하기 때문에 무게 제한을 넘게 된다. 따라서 작은 사람과, 큰 사람을 태워야 최소가 된다.
- 문제의 조건을 꼼꼼하게 따져봐야 한다.

## 테이블 해시 함수

#### https://school.programmers.co.kr/learn/courses/30/lessons/147354

#### https://github.com/HongYouBin/Programmers/blob/main/147354.cpp

- bit 연산이 필요한 문제이다. XOR 연산자는 ^ 이다.
  - https://m.blog.naver.com/rthis_dev/221627197529

## 택배 배달과 수거하기(카카오 기출, 다시 풀 것)

- [ ] 1회차
- [ ] 2회차
- [ ] 3회차

#### https://school.programmers.co.kr/learn/courses/30/lessons/150369

#### https://github.com/HongYouBin/Programmers/blob/main/150369.cpp

- 그리디 문제이다.
- 처음 문제를 보고 배달하는 집과, 수거하는 집 중 가장 멀리 있는 집을 선택하여 처리해야 한다는 사실을 알았다. 모든 집에서 배달과 수거를 해야하고, 멀리 있는 집을 들를 때 배달과 수거가 동시에 가능하기 때문에 가장 멀리 있는 집을 선택해야 한다. 가까운 집 먼저 처리하면 뒤에 있는 집에서 배달과 수거가 불가능하기 때문에 멀리 있는 집부터 처리해야 한다. ex) cap = 4, d = {2, 0, 2, 0}, p = {0, 2, 0, 2}면 멀리있는 집부터 처리하면 4*2 안어 처리가 가능하지만 가까운 집부터 처리하면 3*2+4\*2의 거리가 소모된다. 따라서 가장 멀리 있는 집부터 처리해야 하는 그리디한 문제이다.
- 아이디어를 떠올렸지만 구현에서 막혔다. 배달과 수거 동시에 일어나기 때문에 어떻게 처리해야 하는지 어려웠다. 다른 사람의 풀이를 보니 쉬운 아이디어로 해결했다. 배달과 수거를 처리해야 하는 집 중 가장 멀리 있는 집을 선택하고 그 집을 기준으로 cap의 개수만큼 배달 사장 개수와 수거 상자 개수를 줄이면 된다. 줄인 개수가 cap보다 작으면 다음 상자도 처리하고 반대로 cap보다 크면 cap을 초과한 수만큼 줄이는 방법으로 구현했다.
