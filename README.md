# Programmers

### 양과 늑대 92343 (카카오 기출)

#### https://school.programmers.co.kr/learn/courses/30/lessons/92343

#### https://github.com/HongYouBin/Programmers/blob/main/92343.cpp

- 비트마스크를 이용한 완전 탐색문제이다. DP처럼 메모이제이션을 이용하여 풀 수도 있다. 비트마스크 개념이 앞으로 자주 쓰일 것 같으니 익혀둬야 한다.
  - https://velog.io/@qwe910205/%EB%B9%84%ED%8A%B8%EB%A7%88%EC%8A%A4%ED%81%AC
- 현재 노드에서 다음 노드로 조건을 따져야 한다. 조건을 만족하면 num 변수에 해당 노드를 방문했다는 비트를 찍고 넘겨야 한다.
- 매번 재귀 단계에서 방문한 비트를 참고하여 양과 늑대의 수를 세주고 양의 최대 값을 갱신하는 방법으로 해당 문제를 풀 수 있다.

### 피로도 87946

#### https://school.programmers.co.kr/learn/courses/30/lessons/87946

#### https://github.com/HongYouBin/Programmers/blob/main/87946.cpp

- 완전탐색 문제이다. K의 수가 8밖에 되지 않아 완전탐색으로 풀 수 있다. 처음에 그리디 문제인가 고민했다. K의 수가 8인 것을 확인한 순간 그리디 고민을 멈추고 완전탐색으로 넘어가야 했다. 최대한 빨리 풀이 방안을 고민하고, 명백한 방법이 보이면 애매한 방법을 버리고 넘어가서 풀자.
- 순열 사용을 위해 bin vector를 생성했는데, 그럴 필요 없이 dungeons vector를 오름차순 정렬한 후 바로 사용하면 간단하게 풀 수 있었다.
- dungeons vector에서 방문하지 않은 vector를 다시 생성하여 재귀로 넘겨주는 방법으로 푼 사람도 있고, dfs를 사용해서 푼 사람도 눈에 띄었다.

### 섬 연결하기

#### https://school.programmers.co.kr/learn/courses/30/lessons/42861

#### https://github.com/HongYouBin/Programmers/blob/main/42861.cpp

- 크루스칼로 해결했다.(그리디)

### 연속 부분 수열 합의 개수

#### https://school.programmers.co.kr/learn/courses/30/lessons/131701

#### https://github.com/HongYouBin/Programmers/blob/main/131701.cpp

- map을 사용해서 완전 탐색으로 해결했다.
- 길이가 1인 연속 합부터, 길이가 elements의 크기인 연속 합까지 for문으로 차례대로 구했다.
- 다른 사람의 풀이를 보니 기준 인덱스를 정한 후, 정한 인덱스부터 다른 인덱스를 차례로 방문하여 합을 구해 set에 넣어주고, 기준 인덱스를 옮기는 방식으로 해결했다.

### 숫자 타자 대회

#### https://school.programmers.co.kr/learn/courses/30/lessons/136797

#### https://github.com/HongYouBin/Programmers/blob/main/136797.cpp

- dfs를 사용한 완전 탐색으로 풀면 시간 초과가 발생한다. 매 number마다 왼손으로 누를지, 오른손으로 누를지 2개의 경우의 수가 발생하기 때문에 2^(100000) 시간 복잡도가 발생한다. 따라서 메오이제이션을 사용하는 dp개념을 활용해야 한다. 즉 dfs+dp 활용
- 매 단계(level) 왼손 위치, 오른손 위치에 따라 나오는 결과값을 dp 배열에 저장한다. 그 후 단계, 왼손 위치, 오른손 위치가 dp에 저장된 값이면 계산을 하지 않고 dp 배열 값을 참조하면서, 시간복잡도를 줄일 수 있다.
- 완전 탐색으로 설계한 후, 시간 복잡도를 줄여야 하면 dp의 메모이제이션 개념을 떠올려 봐야 한다.

### 입국심사

#### https://school.programmers.co.kr/learn/courses/30/lessons/43238

#### https://github.com/HongYouBin/Programmers/blob/main/43238.cpp

- 이분탐색으로 구현했다.
- 시간을 정한 후 해당 각 시간안에 심사관이 몇 명을 심사하는지 계산한 후 n보다 작으면 시간을 늘려주고, n보다 크거나 같으면 시간을 줄여줬다.

### 두 큐 합 같게 만들기

#### https://school.programmers.co.kr/learn/courses/30/lessons/118667

#### https://github.com/HongYouBin/Programmers/blob/main/118667.cpp

- 그리디로 구현했다.
- 합이 큰 큐를 pop한 후 합이 작은 큐에 push 했다.
- 언제 -1을 return 해야 하는지 기준을 설정하는 부분이 까다로웠다. 계산을 해보니 각각 queue 길이 합의 2배를 하면 처음 큐의 상태로 돌아왔다. 따라서 2\*(큐1의 길이+큐2의 길이)가 답이 된다.

### 교점에 별 만들기

#### https://school.programmers.co.kr/learn/courses/30/lessons/87377

#### https://github.com/HongYouBin/Programmers/blob/main/87377.cpp

- 구현하면서 까다로운 부분이 3가지 있었다. 첫 번째로는 정수판단 여부이다. 생각보다 간단하게 했는데 나눈 값을 mod연산하여 0인지 아닌지로 판단하는 방법과 구한 값과 int로 캐스팅한 값을 빼서 0인지 아닌지 판단하는 방법이 있다. 비슷한 문제가 나오면 잊지 말고 활용해야 한다.
- 최대한 작은 배열을 생성해 return해야 하는 조건이 까다로웠다. 최대 Y값을 구한 y값에서 뺀다. 구한 x값을 최소 x값에 빼는 방법으로 구현했다.
- core dumped가 발생해서, 그 이유를 알고 처리하는 과정이 까다로웠다. 알고보니 두 직선의 교점을 구하는 방법에서 각각의 A, B, C를 곱해줘야 하는데, 그 과정에서 최대값이 10^10 이 된다. int의 최대 값이 10^9이기 때문에 long long 타입을 사용해야한다. core dumped가 메모리에 잘못되게 접근했기 때문에 발생하는데, 지금은 오버플로우 때문에 발생한듯 싶다. 변수의 최대값을 미리 구한 후 데이터 타입을 고려해줘야 하고, 문제 없이 풀었는데도 메모리에 오류가 발생하면 데이터 타입을 적절히 설정했나 검토해야 한다.
