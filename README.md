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
