# [BOJ] 17626. Four Squares
| 티어 | 유형 | 푼 언어 | 링크 |
| :-: | :-: | :-: | :-: |
|실버3|`dp`|c++|[BOJ 17626](https://www.acmicpc.net/problem/17626)|

![alt text](image.png)

## 접근 1.
`dp[n]`을 `n`을 만들 때 사용할 제곱수의 최소 개수라고 하자. `n`이 제곱수이면 `1`로 초기화했다.    
```cpp
for (int i = 1; i * i <= 50000; i++) {
    dp[i * i] = 1;
}
```     
`j`를 `i`이하의 가장 큰 제곱수라 하면, 점화식을 다음과 같이 생각했다.   
```
dp[i] = dp[j] + dp[i - j]
```
`i`이하의 가장 큰 제곱수는 find_square이라는 함수로 구했다.
```cpp
int find_square(int a) {
    int rst = sqrt(a);
    return (rst * rst > a ? (rst - 1) * (rst - 1) : rst * rst);
}
```
예를 들어 `i = 26`이라 하자. 그럼 `j = 25`이고, 그럼 
```
dp[26] = dp[25] + dp[1] = 2
``` 
이런 셈인 것이다. 구현하면 다음 코드와 같다.   
```cpp
for (int i = 1; i <= n; i++) {
    if (dp[i] == 1) continue;

    int j = find_square(i);

    dp[i] = dp[j] + dp[i - j];
}
```
근데 이렇게 하면 최솟값이란걸 보장할 수 없었다. 반례로 `12`가 있다.   
이 점화식에 따르면 `j = 9`이고,    
```
dp[12] = dp[9] + dp[3] = dp[9] + dp[1] + dp[1] + dp[1] = 4
``` 
이렇게 된다. 근데 실제 최솟값은 
```
dp[12] = dp[4] + dp[4] + d[4] = 3
```
이다.


## 접근 2.
정답은 i 이하의 모든 제곱수를 고려하는 것이다.    
그래서 점화식을 다음과 같이 작성해야 한다.
```
dp[i] = min(dp[i], dp[i - j*j] + 1)  (j = 1 to int(sqrt(i)))
```

`dp[i - j*j]`에 `1`을 더해주는 이유는 `dp[i - j*j]`와 `j*j`의 합으로 나타낸다는 뜻이기 때문이다.    
여기서 min 메서드를 사용하기 때문에 제곱수 항들을 제외한 나머지 항은 충분히 큰 수로 초기화 해야한다.   
아래는 이 점화식을 구현한 것이다.
```cpp
for (int i = 1; i <= n; i++) {
    if (dp[i] == 1) continue;

    for (int j = 1; j * j < i; j++) {
        dp[i] = min(dp[i], dp[i - j * j] + 1);
    }
}
```
[전체코드보기](17626.cpp)