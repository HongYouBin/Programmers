# Programmers

### 양과 늑대 92343 (카카오 기출)

- [ ] 1회차
- [ ] 2회차
- [ ] 3회차

https://school.programmers.co.kr/learn/courses/30/lessons/92343

https://github.com/HongYouBin/Programmers/blob/main/92343.cpp

- 비트마스크를 이용한 완전 탐색문제이다. DP처럼 메모이제이션을 이용하여 풀 수도 있다. 비트마스크 개념이 앞으로 자주 쓰일 것 같으니 익혀둬야 한다.
  - https://velog.io/@qwe910205/%EB%B9%84%ED%8A%B8%EB%A7%88%EC%8A%A4%ED%81%AC
- 현재 노드에서 다음 노드로 조건을 따져야 한다. 조건을 만족하면 num 변수에 해당 노드를 방문했다는 비트를 찍고 넘겨야 한다.
- 매번 재귀 단계에서 방문한 비트를 참고하여 양과 늑대의 수를 세주고 양의 최대 값을 갱신하는 방법으로 해당 문제를 풀 수 있다.

### 피로도 87946

https://school.programmers.co.kr/learn/courses/30/lessons/87946

https://github.com/HongYouBin/Programmers/blob/main/87946.cpp

- 완전탐색 문제이다. K의 수가 8밖에 되지 않아 완전탐색으로 풀 수 있다. 처음에 그리디 문제인가 고민했다. K의 수가 8인 것을 확인한 순간 그리디 고민을 멈추고 완전탐색으로 넘어가야 했다. 최대한 빨리 풀이 방안을 고민하고, 명백한 방법이 보이면 애매한 방법을 버리고 넘어가서 풀자.
- 순열 사용을 위해 bin vector를 생성했는데, 그럴 필요 없이 dungeons vector를 오름차순 정렬한 후 바로 사용하면 간단하게 풀 수 있었다.
- dungeons vector에서 방문하지 않은 vector를 다시 생성하여 재귀로 넘겨주는 방법으로 푼 사람도 있고, dfs를 사용해서 푼 사람도 눈에 띄었다.

### 섬 연결하기

https://school.programmers.co.kr/learn/courses/30/lessons/42861

https://github.com/HongYouBin/Programmers/blob/main/42861.cpp

- 크루스칼로 해결했다.(그리디)

### 연속 부분 수열 합의 개수

https://school.programmers.co.kr/learn/courses/30/lessons/131701

https://github.com/HongYouBin/Programmers/blob/main/131701.cpp

- map을 사용해서 완전 탐색으로 해결했다.
- 길이가 1인 연속 합부터, 길이가 elements의 크기인 연속 합까지 for문으로 차례대로 구했다.
- 다른 사람의 풀이를 보니 기준 인덱스를 정한 후, 정한 인덱스부터 다른 인덱스를 차례로 방문하여 합을 구해 set에 넣어주고, 기준 인덱스를 옮기는 방식으로 해결했다.

### 숫자 타자 대회

https://school.programmers.co.kr/learn/courses/30/lessons/136797

https://github.com/HongYouBin/Programmers/blob/main/136797.cpp

- dfs를 사용한 완전 탐색으로 풀면 시간 초과가 발생한다. 매 number마다 왼손으로 누를지, 오른손으로 누를지 2개의 경우의 수가 발생하기 때문에 2^(100000) 시간 복잡도가 발생한다. 따라서 메오이제이션을 사용하는 dp개념을 활용해야 한다. 즉 dfs+dp 활용
- 매 단계(level) 왼손 위치, 오른손 위치에 따라 나오는 결과값을 dp 배열에 저장한다. 그 후 단계, 왼손 위치, 오른손 위치가 dp에 저장된 값이면 계산을 하지 않고 dp 배열 값을 참조하면서, 시간복잡도를 줄일 수 있다.
- 완전 탐색으로 설계한 후, 시간 복잡도를 줄여야 하면 dp의 메모이제이션 개념을 떠올려 봐야 한다.

### 입국심사

https://school.programmers.co.kr/learn/courses/30/lessons/43238

https://github.com/HongYouBin/Programmers/blob/main/43238.cpp

- 이분탐색으로 구현했다.
- 시간을 정한 후 해당 각 시간안에 심사관이 몇 명을 심사하는지 계산한 후 n보다 작으면 시간을 늘려주고, n보다 크거나 같으면 시간을 줄여줬다.

### 두 큐 합 같게 만들기

https://school.programmers.co.kr/learn/courses/30/lessons/118667

https://github.com/HongYouBin/Programmers/blob/main/118667.cpp

- 그리디로 구현했다.
- 합이 큰 큐를 pop한 후 합이 작은 큐에 push 했다.
- 언제 -1을 return 해야 하는지 기준을 설정하는 부분이 까다로웠다. 계산을 해보니 각각 queue 길이 합의 2배를 하면 처음 큐의 상태로 돌아왔다. 따라서 2\*(큐1의 길이+큐2의 길이)가 답이 된다.

### 교점에 별 만들기

https://school.programmers.co.kr/learn/courses/30/lessons/87377

https://github.com/HongYouBin/Programmers/blob/main/87377.cpp

- 구현하면서 까다로운 부분이 3가지 있었다. 첫 번째로는 정수판단 여부이다. 생각보다 간단하게 했는데 나눈 값을 mod연산하여 0인지 아닌지로 판단하는 방법과 구한 값과 int로 캐스팅한 값을 빼서 0인지 아닌지 판단하는 방법이 있다. 비슷한 문제가 나오면 잊지 말고 활용해야 한다.
- 최대한 작은 배열을 생성해 return해야 하는 조건이 까다로웠다. 최대 Y값을 구한 y값에서 뺀다. 구한 x값을 최소 x값에 빼는 방법으로 구현했다.
- core dumped가 발생해서, 그 이유를 알고 처리하는 과정이 까다로웠다. 알고보니 두 직선의 교점을 구하는 방법에서 각각의 A, B, C를 곱해줘야 하는데, 그 과정에서 최대값이 10^10 이 된다. int의 최대 값이 10^9이기 때문에 long long 타입을 사용해야한다. core dumped가 메모리에 잘못되게 접근했기 때문에 발생하는데, 지금은 오버플로우 때문에 발생한듯 싶다. 변수의 최대값을 미리 구한 후 데이터 타입을 고려해줘야 하고, 문제 없이 풀었는데도 메모리에 오류가 발생하면 데이터 타입을 적절히 설정했나 검토해야 한다.

### k진수에서 소수 만들기 (카카오 기출, 다시 풀 것)

- [ ] 1회차
- [ ] 2회차
- [ ] 3회차

https://school.programmers.co.kr/learn/courses/30/lessons/92335

https://github.com/HongYouBin/Programmers/blob/main/92335.cpp

- 정수 n의 소수 판별을 위해 2부터 n의 제곱근까지 나누어 떨어지는지 확인하면 된다는 아이디어를 떠올렸고 시간을 줄일 수 있었다.
- P가 0이 아닌 소수라는 점을 이용해 k 진수로 바꿨을 때 0을 기준으로 끊으면 된다는 아이디어도 문제를 풀면서 떠올렸다.
- 핵심적인 두 개의 아이디어를 떠올렸는데도 문제를 푸는데 애를 먹었다. 우선 k 진수를 만드는 방법에서 애를 먹었다. n을 k로 나눈 나머지를 거꾸로 저장하는 방법을 고민했다. 나머지가 2자리 수가 넘어가면 구현이 복잡해지기 때문이다. 방법은 생각보다 간단했는데, k가 10이기 때문에 나머지의 최대수는 9이다. 1부터 9이기 때문에 한 자리 숫자이고 따라서 string 으로 저장한 후 reverse()로 돌리면 된다. reverse()를 까먹지 않고 활용해야 한다.
- k 진수 생성 후, 0으로 끊은 후 에라토스테네스 체를 만들어 소수를 판별했는데 오류가 발생했다. 에라토스테네스 체를 만들면 최대 수를 고려하여 메로리를 할당해야 하는데, 메모리 초과가 발생한다. 따라서 에라토스테네스의 체를 생성하지 말고, 0으로 끊긴 정수마다 2부터 구한 정수의 제곱근까지 for 문을 써서 나누어 떨어지나 따져줘야 했다.
- 1번 test case가 풀리지 않아 답을 참고해줬는데, k 진수로 생성된 수가 int 형을 벗어날 수 있다. n의 최대 수인 1,000,000을 2진수로 구현해야 하면 약 2를 20번 나눠야 하고, 이는 2진수가 20자리까지 나온다는 사실을 의미한다. int일 때 10자리 까지 연산이 가능하기 때문에 int로 구현하면 오류가 발생한다. 따라서 long long 을 써줘야 한다. 미리 변수 할당 전 메모리를 계산하여 변수 타입을 결정해줘야 한다.

### 전력망을 둘로 나누기

https://school.programmers.co.kr/learn/courses/30/lessons/86971

https://github.com/HongYouBin/Programmers/blob/main/86971.cpp

- 완전탐색으로 구현했다. 그래프 이론까지 추가된 문제이다.
- 전력망을 하나씩 끊은 후, bfs를 통해 2개의 전력망의 개수를 구하는 방법으로 구현했다.
- bfs를 사용하지 않고, bfs를 사용하는 방법도 있었다. 총 몇번의 노드를 지나왔는지 기록하는 배열(기록 배열)을 할당한 후 dfs를 써서 순차적으로 조회한다. 매 단계마다 다음 조회할 노드의 기록 배열 + 1 을 현재 노드의 기록 배열에 저장한다. 그 후 전력망을 차단 했을 때 차단한 노드의 기록 배열과, 전체 노드의 개수-차단한 노드의 기록 배열을 비교한다. 해당 방법을 사용하면 내가 푼 방법보다 쉽게 풀 수 있다. 우선 경로(edge)의 개수가 n-1개이기 때문에 사이클이 발생하지 않는다. 따라서 각 노드마다 다른 노드와 1개밖에 연결되지 않기 때문에 해당 문제를 풀 수 있다.

  - https://school.programmers.co.kr/learn/courses/30/lessons/86971/solution_groups?language=cpp

### 거리두기 확인하기 (카카오 인턴 기출)

https://school.programmers.co.kr/learn/courses/30/lessons/81302

https://github.com/HongYouBin/Programmers/blob/main/81302.cpp

- bfs를 사용하여 응시자가 있는 좌표로부터 테이블 거리 2 이내를 완전 탐색하여 다른 사람이 있는 확인하는 방법으로 구현했다.
- 다른 사람들의 풀이를 보니 더 좋은 방법이 있었다. 배열을 생성해 응시자가 있는 좌표로부터 한 칸 떨어진 거리에 true로 선언한다. 응시자가 각각 한 칸 떨어진 좌표에 true를 선언하는 과정에서 이미 true가 선언됐다면 두 칸 이내에 다른 응시자가 있다는 의미이고, false를 return하면 된다. bfs처럼 복잡한 과정을 쓰지 않아 내가 풀은 방법보다 간단하고, 시간도 절약하면서 해결했다.
- https://school.programmers.co.kr/learn/courses/30/lessons/81302/solution_groups?language=cpp

### 풍선 터트리기

https://school.programmers.co.kr/learn/courses/30/lessons/68646

https://github.com/HongYouBin/Programmers/blob/main/68646.cpp

- 각 번호를 조회한다. 한 번호를 기준으로 왼쪽 방향에서 가장 작은 수와 오른쪽 방향에서 가장 작은 수를 비교한다. 번호가 작은 풍선을 1번만 터트릴 수 있기 때문에 기준 번호가 구한 두 수 중 한 개보다 크기만 하면 남길 수 있다.

### 점 찍기

https://school.programmers.co.kr/learn/courses/30/lessons/140107

https://github.com/HongYouBin/Programmers/blob/main/140107.cpp

- b의 수를 정한다고 가정할 때 a의 최대 값은
  > $$ \sqrt{d^2-(bk)^2/k^2} $$
  > 이다. 따라서 b에 따른 최대 a를 구한 후 답을 더해주면 된다.
- 잘 구현했는데도 오답이 발행했다. 알고보니 long long 타입과, int 타입을 연산해줘서 오류가 발생했다. long long 타입을 쓸 때 형 변환에 신경 쓰도록 하자.
- C++ 제곱근 공식 cmath 헤더 추가하자.
  - https://manniz.tistory.com/entry/C%EC%96%B8%EC%96%B4-%EB%A3%A8%ED%8A%B8%EC%A0%9C%EA%B3%B1%EA%B7%BC-%EC%9D%84-%EA%B5%AC%ED%95%98%EB%8A%94-2%EA%B0%80%EC%A7%80-%EB%B0%A9%EB%B2%95sqrt-pow-%EC%86%8C%EC%8A%A4-%EC%BD%94%EB%93%9C

### 스타 수열(다시 풀 것)

- [ ] 1회차
- [ ] 2회차
- [ ] 3회차

https://school.programmers.co.kr/learn/courses/30/lessons/70130

https://github.com/HongYouBin/Programmers/blob/main/70130.cpp

- 처음에 완전탐색을 고민했다. 경우의 수가 2^500000 가 나오기 때문에 적용할 수 없다. dp의 메모이제이션을 고민해봤는데, 도저히 사용할 방법이 떠오르지 않았다.
- 처음에 교집합을 정한 후 a 배열을 모두 돌면서 교집합과 겹치는 부분을 체크하면서 답을 갱신해줬다. 문제점은 최악의 경우 시간복잡도가 O(500000^2)가 된다는 것이다. 시간 복잡도를 줄일 필요가 있었다.
- 시간 복잡도를 어떻게 줄일까 고민하다 다른 사람의 풀이를 보니 명확해졌다. 정수 x를 교집합으로 정한다고 가정하면 스타 수열 최대값은 x가 배열 a에 등장하는 회수보다 작거나 같다. 따라서 이미 구한 스타 수열의 최대 길이가 정수 x의 등장 횟수보다 작으면 셀 필요가 없고, 해당 방법으로 문제를 해결했다.

### 합승 택시 요금

https://school.programmers.co.kr/learn/courses/30/lessons/72413

https://github.com/HongYouBin/Programmers/blob/main/72413.cpp

- 플로이드 와샬 알고리즘으로 한 점에서 다른 점까지의 최소 경로를 기록한 표를 만들었다. 그 후 기준점을 만들어 (시작 지점에서 기준점까지 최소 경로 + 기준점에서 A 까지 최소 경로, 기준점에서 B 까지 최소 경로)를 구해 가장 작은 값을 리턴하도록 했다.
- n이 최대 200이기 때문에 플로이드 알고리즘을 사용한다면 시간복잡도가 O(10^7)이 된다. 따라서 시간 안에 해결 가능하다.
- 다른 사람의 풀이를 보니 다익스트라 알고리즘을 사용하여 a와 다른 지점의 최단 경로, b와 다른 지점의 최단 경로, s와 다른 지점의 최단 경로를 기록한 표를 만들어 정답을 갱신했다.

### 경주로 건설 (카카오 기출)

https://school.programmers.co.kr/learn/courses/30/lessons/67259

https://github.com/HongYouBin/Programmers/blob/main/67259.cpp

- 배열의 최대 크기가 25\*25이기 때문에 완전탐색을 구현할 수 있었다. 최단 경로를 구할 때 완전탐색보다 다익스트라가 편해보여서 다익스트라로 구현했다.
- 한 배열에서 다른 배열로 갈 때 방향을 유지하면 경로를 기존 거리에 100을 더한 값을 우선순위 큐에 넣어줬고, 방향을 바꿀때 기존 거리에 600을 더한 값(방향 바꾸는 비용 500, 바꾼 방향으로 진행하는 비용 100)을 우선순위 큐에 넣어 구현했다.
- 다른 사람들의 풀이를 보니 대부분 bfs, dfs를 사용해서 구현했다. 큐, 스택에 방향을 유지할 때 100을 넣고, 방향을 바꿀 때 600을 넣었다.
- 우선순위 큐를 비교연산자 구현해야 했다.
  - https://hydroponicglass.tistory.com/169

### 경주로 건설 (카카오 기출)

https://school.programmers.co.kr/learn/courses/30/lessons/67259

https://github.com/HongYouBin/Programmers/blob/main/67259.cpp

- 투 포인터로 구현했다.
- 앞 뒤 포인터로 모든 보석이 모인 연속한 집합을 구한 후 거리를 계산해준다. 가장 적은 거리를 가진 연속 집합이 정답이 된다.

### 양궁 (카카오 기출)

https://school.programmers.co.kr/learn/courses/30/lessons/92342

https://github.com/HongYouBin/Programmers/blob/main/92342.cpp

- 완전탐색으로 구현했다.
- 라이언이 피치보다 1개 더 쏘면 이기기 때문에 이겨야 하는 라운드를 정한 후 해당 라운드의 라이언의 화살의 수를 피치보다 1개 더 많이 쏘도록 만들었다.
- dfs로도 구현 가능하다. 단계가 총 11개고 화살의 최대 수가 10개 이기 때문에 모든 경우의 수를 dfs로 구현 가능하다.

### 멀쩡한 사각형

https://school.programmers.co.kr/learn/courses/30/lessons/62048

https://github.com/HongYouBin/Programmers/blob/main/62048.cpp

- 대각선이 지나치는 총 개수가 가로, 새로 길이의 최대 공약수라는 사실을 알게되면 쉽게 구현 가능하다.
  - https://kim519620.tistory.com/entry/%EB%A9%80%EC%A9%A1%ED%95%9C-%EC%82%AC%EA%B0%81%ED%98%95-feat-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-62048%EB%B2%88

### 불량 사용자(카카오 기출)

- [ ] 1회차
- [ ] 2회차
- [ ] 3회차

https://school.programmers.co.kr/learn/courses/30/lessons/64064

https://github.com/HongYouBin/Programmers/blob/main/64064_1.cpp

https://github.com/HongYouBin/Programmers/blob/main/64064_2.cpp

https://github.com/HongYouBin/Programmers/blob/main/64064_3.cpp

- 처음에 이진 탐색으로 풀어야 하나 고민했다. 하지만 배열의 최대 크기가 8이기 때문에 굳이 이진 탐색으로 풀 필요가 없다는 사실을 깨달았고, 완전 탐색으로 방향을 바꾸었다.
- 첫 번째 방법은 틀린 접근이었다. banned_id 크기만큼 user_id에서 스트링을 뽑는다. 뽑은 스트링에서 '*'를 붙여 만들 수 있는 모든 스트링을 만들어 맵에 저장한 후 banned_id에 map을 조회하도록 했다. 문제는 하나의 user_id에서 2개 이상의 banned_id를 만족하는 *을 붙인 스트링을 생성할 수 있다는 것이다. 예를 들어 banned_id가 \*rodo만 갖고 있고 user_id가 prodo, crodo라고 하면 1개의 banned_id에 2개의 user_id가 만족하게 된다는 문제점이 있다. 따라서 해당 접근 방법은 틀렸다.
  - https://github.com/HongYouBin/Programmers/blob/main/64064_1.cpp
- 두 번째 접근도 잘못됐다. 마찬가지로 user_id에서 banned_id 크기만큼 문자열을 뽑았다. 그 후 for문으로 모든 user 문자열과, banned 문자열을 비교하는 방법으로 구현했다. 문제점은 한 개의 banned_id가 user_id를 선점하면, 다른 banned_id가 선점된 user_id를 선택하지 못한다는 것이다. 예를 들어보겠다. user_id가 frodo, crodo이고 banned_id가 fr*d*, *rodo이라고 가정하자. frodo가 *rodo, fr*d* 둘 다 적용 가능하고 crodo는 *rodo만 적용 가능하다. 이때 frodo가 *rodo를 선점한다고 할 때 crodo는 아무 것도 선점하지 못하게 된다. 따라서 답인 frodo와 crodo가 나오지 못하고, frodo만 나오게 된다.
  - https://github.com/HongYouBin/Programmers/blob/main/64064_2.cpp
- 따라서 dfs를 사용한 조합으로 구현해야 한다. dfs를 사용해서 모든 경우의 수를 따져줘야 하고, 제재 아이디가 생성되면 생성된 값을 조합으로(순서에 상관 없이) 저장해야 한다. 따라서 dfs로 user_id가 banned_id를 기준으로 일치하는지 확인한 후 다른 user_id와도 일치하는지 확인하는 방법으로 구현했다. 두 문자열이 일치하면 bitmap 마스킹으로 넘겨 조합으로 순서에 상관 없이 map에 저장되도록 만들었다.
  - https://github.com/HongYouBin/Programmers/blob/main/64064_3.cpp

### 구명보트

https://school.programmers.co.kr/learn/courses/30/lessons/42885

https://github.com/HongYouBin/Programmers/blob/main/42885.cpp

- 구명보트에 최대 2명이라는 조건을 보지 못해 오름차순 정렬 후 작은 수부터 구명보트를 채우려고 했다. 물론 오답이 발생했다.
- 최대 2명이라는 조건 때문에 몸무게가 제일 작은 사람과 제일 큰 사람을 태워야 한다. 2명을 몸무게가 작은 순부터 채우면 순서가 뒤로 갈수록 큰 사람끼리 2명을 채워야 하기 때문에 무게 제한을 넘게 된다. 따라서 작은 사람과, 큰 사람을 태워야 최소가 된다.
- 문제의 조건을 꼼꼼하게 따져봐야 한다.

### 테이블 해시 함수

https://school.programmers.co.kr/learn/courses/30/lessons/147354

https://github.com/HongYouBin/Programmers/blob/main/147354.cpp

- bit 연산이 필요한 문제이다. XOR 연산자는 ^ 이다.
  - https://m.blog.naver.com/rthis_dev/221627197529

### 택배 배달과 수거하기(카카오 기출, 다시 풀 것)

- [ ] 1회차
- [ ] 2회차
- [ ] 3회차

https://school.programmers.co.kr/learn/courses/30/lessons/150369

https://github.com/HongYouBin/Programmers/blob/main/150369.cpp

- 그리디 문제이다.
- 처음 문제를 보고 배달하는 집과, 수거하는 집 중 가장 멀리 있는 집을 선택하여 처리해야 한다는 사실을 알았다. 모든 집에서 배달과 수거를 해야하고, 멀리 있는 집을 들를 때 배달과 수거가 동시에 가능하기 때문에 가장 멀리 있는 집을 선택해야 한다. 가까운 집 먼저 처리하면 뒤에 있는 집에서 배달과 수거가 불가능하기 때문에 멀리 있는 집부터 처리해야 한다. ex) cap = 4, d = {2, 0, 2, 0}, p = {0, 2, 0, 2}면 멀리있는 집부터 처리하면 4*2 안어 처리가 가능하지만 가까운 집부터 처리하면 3*2+4\*2의 거리가 소모된다. 따라서 가장 멀리 있는 집부터 처리해야 하는 그리디한 문제이다.
- 아이디어를 떠올렸지만 구현에서 막혔다. 배달과 수거 동시에 일어나기 때문에 어떻게 처리해야 하는지 어려웠다. 다른 사람의 풀이를 보니 쉬운 아이디어로 해결했다. 배달과 수거를 처리해야 하는 집 중 가장 멀리 있는 집을 선택하고 그 집을 기준으로 cap의 개수만큼 배달 사장 개수와 수거 상자 개수를 줄이면 된다. 줄인 개수가 cap보다 작으면 다음 상자도 처리하고 반대로 cap보다 크면 cap을 초과한 수만큼 줄이는 방법으로 구현했다.

### 고고학 최고의 발견

- [ ] 1회차
- [ ] 2회차
- [ ] 3회차

https://school.programmers.co.kr/learn/courses/30/lessons/131702

https://github.com/HongYouBin/Programmers/blob/main/131702.cpp

- 완전탐색으록 구현했다가 시간초과가 발생했다. 머리를 사용해서 시간복잡도를 줄여야 했다. 아이디어가 떠오르지 않아 힌트를 참고했다. 기준점과 상, 하, 좌, 우 5개가 동시에 움직이고 기준점에서 위에 있는 점은 기준점이 옮겨지면 더이상 움직이지 못한다. 따라서 기준점 위에 있는 배열의 값을 무조건 0으로 만들어야 하기 때문에 시간복잡도를 줄일 수 있다.
- 첫 번째 행은 모든 경우의 수를 탐색해줘야 한다 따라서 dfs를 사용해서 모두 돌려야 한다. 두 번째 행부터 마지막 행까지 기준점 위의 배열 값을 보면 움직여야 하는 횟수가 정해진다. 정해진 횟수에 따라 회전하고 다음 배열로 넘어가면 된다.
- 아이디어를 떠올렸고 구현까지 다 종료했지만 오답이 발생했다. 마지막 행을 검사하지 않기 때문에 dfs로 모든 배열을 다 순회한 후 배열이 모두 12시를 가리키는지 확인하는 과정을 거쳐야 한다. 따라서 check() 함수를 만들어 구현했다.
- 요즘 그냥 완전탐색이나 dfs로 구현하면 시간초과가 발생하는 문제를 많이 보고있다. 단순히 구현이 아니라 시간 복잡도를 줄이기 위해 생각하는 과정이 필요로 하는 문제들이다. 구현 문제를 만나면 정확하게 시간 복잡도를 계산한 후 시간 복잡도를 초과하면 어떻게 해서 줄여야 하나 고민하는 과정을 거쳐야 한다.

### 12927 야근 지수

https://school.programmers.co.kr/learn/courses/30/lessons/12927

https://github.com/HongYouBin/Programmers/blob/main/12927.cpp

- 가장 큰 수를 작게 만들 때 야근 지수가 가장 크게 작아진다. 따라서 가장 큰 수를 뽑고 다음 큰 수보다 작거나 같게 만들어야 가장 크게 줄어든다.
- 1씩 빼면 시간초과가 발생한다. 어차피 큰 수를 반복해서 빼줘야 하기 때문에 큰 수를 두 번째로 큰 수보다 1줄이는 방법을 사용하면 시간을 크게 줄일 수 있다.

### 152996 시소 짝꿍

- [ ] 1회차
- [ ] 2회차
- [ ] 3회차

https://school.programmers.co.kr/learn/courses/30/lessons/152996

https://github.com/HongYouBin/Programmers/blob/main/152996.cpp

- 처음 접근 방법
  1. weights가 10^5이기 때문에 완전탐색 사용불가능하다고 판단했다. O(N)안에 처리해야 한다.
  2. 각 무게를 모두 2곱 3곱 4곱하여 겹치는게 있으면 ans를 1씩 추가하는 방법을 떠올렸다.
     2-1. 해당 방법을 사용하면 중복되는 숫자를 처리 불가능해진다. ex) 100, 100, 100일 때 처리 불가하다.
     2-2. 다른 곱에서 겹치는 경우가 처리 불가능하다. ex) 100, 200일 때 100*2 = 200, 100*4 = 200\*2
- 처음 접근 방법에서 더 벗어나 모든 수를 동시에 움직이지 않고 정렬을 한 후 작음 수부터 큰 수를 탐색한다. 탐색할 때 한 수로 더 큰 수를 만들어 겹치는 수가 있는 확인하는 방법을 사용해야 한다.
- 작은 수로 큰 수를 만드는 방법이 총 2곱, 3/2곱, 4/3곱 총 3가지 이다. 따라서 각 곱을 한 후 수가 있나 확인해주면 된다.
- 문제를 정확하게 읽지 않았고, 꼼꼼하게 생각하지 않아서 오답이 발생한 것 같다. 신중하게 읽고 생각해야 한다.
- 다른 사람의 풀이를 보니 그냥 2중 for문으로 각 수를 탐색하면서 기준 수를 정하고(i) 다른 수(j)를 탐색할 때 겹치는게 있나 확인하는 방법으로 구했다. O(N/2)안에 해결 가능하다.

### 152995 인사고과 (다른 방법으로도 풀어볼 것)

https://school.programmers.co.kr/learn/courses/30/lessons/152995

https://github.com/HongYouBin/Programmers/blob/main/152995.cpp

- 모든 scores에 대해 완전 탐색하면 O(N\*N)의 시간복잡도로 TLE가 발생한다.
- a, b가 0부터 100000이기 때문에 a의 숫자를 인덱스로 하는 배열을 만든다. 배열에는 a가 쌍으로 갖고 있는 수중 가장 큰 b를 넣어준다. ex) a, b -> arr[a] = max(arr[a], b) 그러면 다른 a1, b1가 성과급을 받을 수 있나 따질 때 배열의 인덱스를 a1+1부터 살펴보면 된다. 인덱스 0부터 a1까지는 a1보다 작거나 같기 때문에 살펴보지 않아도 된다.
- 다른 사람의 풀이를 보니 a를 기준으로 내림차순 정렬을 한 후 인덱스 i를 기준으로 0부터 i-1까지만 살펴보는 방법으로 구현했다. i부터 끝까지는 a보다 작거나 같기 때문에 살펴볼 필요가 없다.
- a를 기준으로 내림차순 정렬을 한 후 scores를 조회하면서 가장 큰 b를 갱신한다. 내림차순으로 정렬했기 때문에 당연히 a는 앞보다 작기 때문에 확인할 필요가 없고 b는 가장 큰 b만 살펴보면 된다. 가장 큰 b보다 작으면 성과급을 받을 수 없다.

### 154538 숫자 변환하기

https://school.programmers.co.kr/learn/courses/30/lessons/154538

https://github.com/HongYouBin/Programmers/blob/main/154538.cpp

- queue 자료구조를 이용해서 풀었다.

### 154539 뒤에 있는 큰 수

https://school.programmers.co.kr/learn/courses/30/lessons/154539

https://github.com/HongYouBin/Programmers/blob/main/154539.cpp

- 우선순위 큐를 사용했다. 가장 작은 수를 우선순위로 갖는 큐를 생성하고 배열을 조회하면서 현재 인덱스가 가르키고 있는 수(x) 보다 작은 수들을 다 빼주고 답을 x로 설정하고 x를 우선순위 큐에 넣는 방법으로 구현했다.
- 다른 사람의 풀이를 보니 스택을 사용했다. 스택에 수를 쌓은 후 스택에 있는 수보다 큰 수가 나오면 while문을 사용해서 빼주는 방법을 사용했다.
- 문제를 볼 때 다양한 자료구조(큐, 스택, 우선순위 큐)로 풀 수 있는지 고민해야 한다.

### 154540 무인도 여행

https://school.programmers.co.kr/learn/courses/30/lessons/154540

https://github.com/HongYouBin/Programmers/blob/main/154540.cpp

- 완전탐색으로 풀었다. bfs 알고리즘 사용했다.

### 148652 유사 칸토어 비트열

https://school.programmers.co.kr/learn/courses/30/lessons/148652

https://github.com/HongYouBin/Programmers/blob/main/148652.cpp
https://github.com/HongYouBin/Programmers/blob/main/148652_2.cpp

- [ ] 1회차
- [ ] 2회차
- [ ] 3회차

- 완전탐색으로 풀었다 시간초과가 발생했다. 시간 복잡도를 줄이기 위해 완성된 비트열이 대칭이 된다는 특징을 이용하여 비트열을 절반만 구한 후 1의 개수를 구하는 방법을 선택했다. 하지만 오답이 발생했다.
- 프랙탈 패턴을 띄기 때문에 재귀를 사용해야 한다. 패턴이

1.  1, 1, 0, 1, 1
2.  4, 4, 0, 4, 4
3.  16, 16, 0, 16, 16 ...
    형태로 이루어진다. 따라서 프랙탈인 것을 눈치채야 했고 자연스럽게 재귀 아이디어를 떠올려야 했다.

- 아이디어가 떠올랐어도 구현이 까다로웠다. 프렉탈을 이용한 문제가 익숙하지 않아 구현에 시간이 오래 걸렸다.
- 구현완료 후 테스트 케이스를 통과했음에도 오답이 발생했다. 오랜 시간 고민 끝에 그 이유를 알았다. 재귀의 현재 레벨에서 다음 레벨로 넘어갈 때 0인 부분 즉 인덱스로 [2]인 부분으로 넘어가는지 확인해야 한다. [2]인 부분은 0이기 때문에 재귀의 다음 단계로 넘어가면 안 된다. 설계를 할 때 치밀하게 고민했어야 하는 부분이다.
- 내가 푼 풀이가 깔끔하지 않아 다른 사람의 코드를 구현해 보았다. 프랙탈 패턴이고 시간 복잡도가 크게 나타나면 재귀를 고민해봐야 한다.

### 84512 모음사전

https://school.programmers.co.kr/learn/courses/30/lessons/84512

https://github.com/HongYouBin/Programmers/blob/main/84512.cpp

- 완전탐색으로 풀었다. 최대 5자리까지 A, E, I, O, U로 만들 수 있는 모든 문자의 경우의 수를 탐색하여 map에 넣어준 후 오름차순으로 순서를 정하는 방식으로 문제를 풀었다.
- 완전 탐색을 사용하지 않고 dp나 rfind()를 사용하여 문제를 해결하는 방법이 눈에 띄었다.

### 155651 호텔 대실

- [x] 1회차
- [ ] 2회차
- [ ] 3회차

https://school.programmers.co.kr/learn/courses/30/lessons/155651

https://github.com/HongYouBin/Programmers/blob/main/155651.cpp

- 처음 그리디 방법이 바로 떠올렸다. 접근은 좋았다.
- 오답) 끝나는 시간이 가장 빠른 것을 기준으로 정렬한 후 순서대로 우선순위 큐에 넣어줬다.
  - 끝나는 시간을 기준으로 정렬하면 안되는 이유 : https://hillier.tistory.com/115 빨리 시작하는 강의를 빈 강의실에 넣는게 더 이득이다.
- 정답) 시작 시간을 기준으로 오름차순 정렬한 후 순서대로 우선순위 큐에 넣는다. 우선순위 큐는 끝나는 시간이 짧을수록 루트에 오도록 설정한다. 큐의 최고 사이즈가 답이 된다.
- 시간을 억지로 클래스로 생성했는데 비효율적이다. 분으로 바꿔 계산하는게 구현이 더 쉽다.

### 142085 디펜스 게임

https://school.programmers.co.kr/learn/courses/30/lessons/142085

https://github.com/HongYouBin/Programmers/blob/main/142085.cpp

- 그리디로 구현했다.
- 언제 무적권을 사용하는지에 따라 진행할 수 있는 라운드가 달라진다. 따라서 enemy가 높은 순서대로 무적권을 사용해야 한다.
- 우선순위 큐를 사용하여 현재까지 진행한 라운드에서 enemy가 가장 큰 k개의 변수를 넣어 저장하도록 했다. i번까지 진행했을 때 우선순위 큐에서 가장 작은 수와 enemy[i]의 값을 비교하여 enemy[i]가 작으면 sum을 더해주고 반대면 우선순위 큐의 값을 sum에 더한 후 pop하고, enemy[i]를 우선순위 큐에 넣어주는 방법을 이용했다.

### 150368 이모티콘 할인 (카카오 기출)

https://school.programmers.co.kr/learn/courses/30/lessons/150368

https://github.com/HongYouBin/Programmers/blob/main/150368.cpp

- 완전탐색으로 구현했다.
- 이모티콘의 개수가 7개이고 각 이모티콘마다 4개의 할인율을 설정할 수 있어서 4^7의 시간안에 이모티콘의 모든 할인율을 설정할 수 있었고 각 유저가 이모티콘이나 서비스를 구입하는지 따지는 경우가 최대 100 \* 7 이기 때문에 시간 안에 문제가 해결 가능했다.
- 소수나 분수를 계산할 때 최대한 큰 수가 되도록 곱을 먼저하고 나머지를 마지막에 해야한다.

### 150368 이모티콘 할인 (카카오 기출)

https://school.programmers.co.kr/learn/courses/30/lessons/150368

https://github.com/HongYouBin/Programmers/blob/main/150368.cpp

- 완전탐색으로 구현했다.
- 이모티콘의 개수가 7개이고 각 이모티콘마다 4개의 할인율을 설정할 수 있어서 4^7의 시간안에 이모티콘의 모든 할인율을 설정할 수 있었고 각 유저가 이모티콘이나 서비스를 구입하는지 따지는 경우가 최대 100 \* 7 이기 때문에 시간 안에 문제가 해결 가능했다.
- 소수나 분수를 계산할 때 최대한 큰 수가 되도록 곱을 먼저하고 나머지를 마지막에 해야한다.

### 148653 마법의 엘리베이터

- [x] 1회차
- [ ] 2회차
- [ ] 3회차

https://school.programmers.co.kr/learn/courses/30/lessons/148653

https://github.com/HongYouBin/Programmers/blob/main/148653.cpp

- 각 자리수마다 올림을 할 것인지 내림을 할 것인지 따져줘야 한다. storey가 100,000,000 이하이기 때문에 경우의 수는 2^10 이하이고 시간안에 해결 가능하다.
- 메모이제이션을 사용하면 더 빠르게 구현이 가능하다. 다음 단계로 넘어간 값 중 최소값을 계산하여 메모이제이션을 활용할 수 있다.
- 정수에서 각 자리의 숫자를 분리해야 할 때 모듈러 연산과 나머지 연산을 활용하자 num % 10 을 통해 작은 자리 숫자를 분리할 수 있고 num / 10 후 다시 10을 곱하면 남은 숫자를 구할 수 있다.
- 10을 제곱한 수 중 num보다 작으면서 가장 높은 값을 알고 싶을 때 int base = 0; while (pow(10, base + 1) <= curNum) base++; 식을 활용하자 구한 base로 pow() 함수를 활용할 수 있다.

### 77885 2개 이하로 다른 비트

https://school.programmers.co.kr/learn/courses/30/lessons/77885

https://github.com/HongYouBin/Programmers/blob/main/77885.cpp

- 짝수일 때 + 1해주면 된다. 간단하게 해결 가능하다.
- 홀수일 때가 문제이다. 홀수를 비트로 바꾼 후 문제에 맞게 바꾸면 일정한 규칙이 발생한다. 가장 왼쪽에서 가까운 0을 1로 바꾼 후 바로 왼쪽 1을 0으로 바꾸면 정답이 된다. 가까운 0을 찾기 위해 shift연산을 썼고 어느 정도 맞았지만 시간 초과가 발생했다.
- shift 연산을 최대한 줄이고 바로 2를 곱하는 방법을 사용했는데 정답이 됐다. 생각보다 shift 연산의 오버헤드가 큰 듯하다.

### 76502 괄호 회전하기

https://school.programmers.co.kr/learn/courses/30/lessons/76502

https://github.com/HongYouBin/Programmers/blob/main/76502.cpp

- 주어진 조건에 맞춰 시뮬레이션 하면 된다. stack 자료구조 활용했다.

### 12952 N-Queen

https://school.programmers.co.kr/learn/courses/30/lessons/12952

https://github.com/HongYouBin/Programmers/blob/main/12952.cpp

- 완전탐색을 이용했다.
- 2차원 배열을 생성한 후 퀸을 빈 칸에 놓은 후 유효한지 체크하는 방법이 처음에 떠올랐다가 더 효율적인 방법을 생각해냈다.
- 각 행에 1개만 둬야 하기 때문에 재귀에서 row를 1씩 증가시켜 겹치지 않게 설정했다. 또한 column도 겹치면 안되기 때문에 column을 사용했는지 확인하는 배열을 만든 후 조건을 따졌다.
- 문제는 대각선을 확인하는 방법이다. 체스판을 보면서 한가지 규칙이 떠올랐는데 행과 열 각각 0부터 증가시켜 번호를 매긴 후 각 칸을 행과 열에 적힌 번호의 합을 구하면 왼쪽 아래에서 오른쪽 위로 향하는 대각선의 값이 일치한다는 사실을 알게 되었다. 반대로 열을 0부터 증가시키고 행은 n-1부터 0까지 감소시키는 번호를 매긴 후 각 칸의 행과 열에 적힌 번호의 합을 구하면 왼쪽 위에서 오른쪽 아래로 향하는 대각선이 일치한다. 따라서 이런 규칙을 활용하면 대각선을 방문했는지 안했는지 확인 가능하다.

### 12952 N-Queen

https://school.programmers.co.kr/learn/courses/30/lessons/12952

https://github.com/HongYouBin/Programmers/blob/main/12952.cpp

- 완전탐색을 이용했다.
- 2차원 배열을 생성한 후 퀸을 빈 칸에 놓은 후 유효한지 체크하는 방법이 처음에 떠올랐다가 더 효율적인 방법을 생각해냈다.
- 각 행에 1개만 둬야 하기 때문에 재귀에서 row를 1씩 증가시켜 겹치지 않게 설정했다. 또한 column도 겹치면 안되기 때문에 column을 사용했는지 확인하는 배열을 만든 후 조건을 따졌다.
- 문제는 대각선을 확인하는 방법이다. 체스판을 보면서 한가지 규칙이 떠올랐는데 행과 열 각각 0부터 증가시켜 번호를 매긴 후 각 칸을 행과 열에 적힌 번호의 합을 구하면 왼쪽 아래에서 오른쪽 위로 향하는 대각선의 값이 일치한다는 사실을 알게 되었다. 반대로 열을 0부터 증가시키고 행은 n-1부터 0까지 감소시키는 번호를 매긴 후 각 칸의 행과 열에 적힌 번호의 합을 구하면 왼쪽 위에서 오른쪽 아래로 향하는 대각선이 일치한다. 따라서 이런 규칙을 활용하면 대각선을 방문했는지 안했는지 확인 가능하다.

### 70129 이진 변환 반복

https://school.programmers.co.kr/learn/courses/30/lessons/70129

https://github.com/HongYouBin/Programmers/blob/main/70129.cpp

- 주어진 조건에 맞춰 구현했다.
- 2진수를 만들 때 재귀를 사용했다. 앞으로 이진수를 만들 일이 있을 때 재귀를 활용해야 한다. 처음에 종료조건을 잘못 설정해줬다. num/2가 0이 될 때 종료하도록 했는데 num이 0이 될 때 종료되도록 바꿔야 한다.

```
string makeBinary(int num, string s) {
	if (num == 0) return s;

	char newS = (num % 2) + '0';
	return makeBinary(num / 2, newS + s);
}
```

### 70129 이진 변환 반복

https://school.programmers.co.kr/learn/courses/30/lessons/159993

https://github.com/HongYouBin/Programmers/blob/main/159993.cpp

- bfs 알고리즘 사용했다. 시작점부터 레버까지 최단거리 + 레버부터 출구까지 최단거리 구하면 된다.

### 68936 쿼드압축 후 개수 세기

https://school.programmers.co.kr/learn/courses/30/lessons/68936

https://github.com/HongYouBin/Programmers/blob/main/68936.cpp

- 분할 정복 알고리즘을 사용했다.

### 68645 삼각 달팽이

https://school.programmers.co.kr/learn/courses/30/lessons/68645

https://github.com/HongYouBin/Programmers/blob/main/68645.cpp

- 사이즈가 n일 때 한바퀴 돈 후 생성된 삼각형 안에 n-3 사이즈로 삼각형이 생성되는 규칙을 찾았다. 해당 규칙을 이용해 구현하였다.
- 다른 사람의 코드를 보니 더 간단하게 구현했다. 사이즈가 n일 때 n개의 직선이 생기고 직선이 한번 끝날 때마다 크기가 1씩 줄어드는 특징을 이용했다.

```
 for (int i = 0; i < n; i++) {
        for (int j = p;j >= 1; j--) {
            if(i%3==0) {
                arr[++x][y] = k;
            } else if (i % 3 == 1) {
                arr[x][++y] = k;
            } else if (i % 3 == 2) {
                arr[--x][--y] = k;
            }
            k++;
        }
        p--;
    }
```

### 67257 수식 최대화(카카오 기출)

https://school.programmers.co.kr/learn/courses/30/lessons/67257

https://github.com/HongYouBin/Programmers/blob/main/67257_1.cpp
https://github.com/HongYouBin/Programmers/blob/main/67257_2.cpp

- 연산자와 피연산자를 배열로 받은 뒤 순열로 연산자의 우선순위를 정한 후 계산했다. vector의 erase 연산이 오버헤드가 크지만 expression의 크기가 100밖에 되지 않아 완전탐색으로 풀이가 가능했다.
- 1번은 permutation을 함수로 직접 구현한 방법이다. 2번은 오름차순 후 next_permutation으로 순열을 구현했다. 둘 다 알고있는게 좋긴 하나 2번 방법이 구현이 간단하기 때문에 이용하는 것이 좋아보인다. 자바로 풀 때 next_permutation()이 지원되지 않아 재귀로 직접 구현했고 그 방법이 익숙해져 있었다. 자바로 문제를 풀다 C++로 풀다보니 next_permutation을 써야겠다는 생각을 못했다. 잊지말고 활용해야 한다.

### 42890 후보키 (카카오 기출)

https://school.programmers.co.kr/learn/courses/30/lessons/42890

https://github.com/HongYouBin/Programmers/blob/main/42890.cpp

- 비트맵과 부분 집합을 활용한 완전 탐색으로 문제를 풀었다.
- 선택한 후보키의 집합이 다른 후보키의 집합에 포함되지 않도록 처리하는 부분이 가장 까다로웠다. 이미 확인이 끝난 후보키를 저장한 벡터인 candid에서 하나씩 비교를 해주어야 했는데 어떻게 비교를 해야 하나 고민했다. 비트의 속성을 활용하여 금방 아이디어를 떠올렸다.

```
  // 비트 a가  비트 b에 포함되는지 확인해야 할 때
  (a&b) == a //a와 b를 and 연산한 값이 a와 같으면 a는 b에 포함된다.
  // 비트 a가 비트 b를 포함하는지 확인해야 할 때
  (a|b) == b
```

- 위의 비트가 포함하는지 확인하는 방법은 유용하게 사용할 수 있기 때문에 잊지 말아야 한다.

### 72411 메뉴 리뉴얼 (카카오 기출)

https://school.programmers.co.kr/learn/courses/30/lessons/72411

https://github.com/HongYouBin/Programmers/blob/main/72411.cpp

- 부분순열로 만들 수 있는 모든 메뉴의 경우의 수를 구한 후 맵에 넣어주는 방법으로 구현했다.

### 72412 순위 검색 (카카오 기출)

https://school.programmers.co.kr/learn/courses/30/lessons/72412

https://github.com/HongYouBin/Programmers/blob/main/72412.cpp

- [x] 1회차
- [ ] 2회차
- [ ] 3회차

- 처음에 info string의 각각 항목에 대해 비트를 설정한 후(ex. cpp는 1의 자리가 1, java는 1의 자리가 0 ... ) 배열을 생성해 해당 비트 값을 넣는 방법으로 풀려고 했다. 하지만 시간 초과가 발생하고 구현이 까다로워 해당 방법으로 풀지 못했다.
- 간단하게 구현하기 위해서 info에 string의 각 조건을 비트로 표현하지 말고 그냥 하나로 붙인 후 맵에 넣는 방법으로 구현할 수 있다. 맵에 넣을 때 값을 여러개 저장해야 하기 때문에 `map<string, vector<int>>` 로 설정해야 한다. 이때 info vector안에 있는 string을 띄어쓰기 단위로 직접 구현하기 번거로운데 이를 해결하기 위해 sstream을 사용하여 띄어쓰기 단위로 나눠 저장하면 된다.
  - https://myprivatestudy.tistory.com/48

```
 stringstream ss(s);
        string input = "";
        vector<string> sVt(4);

        for (int i = 0; i < 4; ++i) {
            ss >> input;
            sVt[i] = input;
        }
        ss >> input;
        int score = stoi(input);
        fillMap(sVt, score);
```

- 시간초과를 막기 위해 이분탐색을 하면서 O(logN)안에 문제를 해결해야 한다. map안에 저장한 vector값을 정렬한 후 query로 찾는 조건을 맵에 대입하면서 이분탐색을 진행하면 문제를 시간안에 해결할 수 있다.

```
for (auto& s : query) {
        stringstream ss(s);
        string input;
        string searchStr = "";
        for (int i = 0; i < 7; ++i) {
            ss >> input;
            if (input == "and") continue;
            searchStr += input;
        }
        ss >> input;
        int score = stoi(input);
        int idx = lower_bound(mp[searchStr].begin(), mp[searchStr].end(), score) - mp[searchStr].begin();
        ans.push_back(mp[searchStr].size() - idx - 1);
    }
```

### 87694 아이템줍기

https://school.programmers.co.kr/learn/courses/30/lessons/87694

https://github.com/HongYouBin/Programmers/blob/main/87694.cpp

- [x] 1회차
- [ ] 2회차
- [ ] 3회차

- bfs/dfs보다 어떻게 배열을 활용하여 외곽 길이를 표현해야 하는지 아이디어를 떠올리는게 메인인 문제였다.
- 그냥 배열로 바깥쪽 테두리를 표현하면 'ㄷ' 형태의 테두리에서 오답이 발생한다. 따라서 전체 길이를 2배로 만들어줘야 하고 문제를 풀면서 떠올려야 하는 첫 번째 아이디어이다.
- 2배로 만들어야 하기 때문에 시작점, 목표점, rectagle의 꼭지점 좌표 모두 2배로 만든 후 바깥쪽을 따라 bfs를 해야 답이 나온다.
- 한 쪽만 2배를 해줘서 오답이 발생했다. 선분을 2배로 만들기 위해 모든 좌표 값을 2배를 해줘야 한다.
