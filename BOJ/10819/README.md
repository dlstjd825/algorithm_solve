# [BOJ] 10819. 차이를 최대로
| 티어 | 유형 | 푼 언어 | 링크 |
| :-: | :-: | :-: | :-: |
|실버2|`브루트포스`|c++|[BOJ 10819](https://www.acmicpc.net/problem/10819)|

![alt text](image.png)

## 접근
처음에 설마 모든 경우를 다 해보는 거겠어 라는 생각에 좀 어렵게 접근했던 것 같다.     
근데 `n`의 최댓값이 8이라 다 돌아도 괜찮을 것 같았다.   
근데 모든 경우를 어떻게 처리할 지가 문제였다. 그래서 인터넷 뒤져보니까 `algorithm` STL에     
`next_permutation`이라는 메서드를 사용하면 된다고 해서 이걸 사용했다.   
`next_permutation`은 일단 배열이 정렬된 상태라고 가정하고 시작한다. 그래서 직접 정렬을 해줘야한다.   
버블정렬 그런거 써도 될 것 같았는데 이미 `algorithm`을 불러왔으니까 `sort`메서드 썼다.   
`do-while` 구문으로 처음 정렬된 배열에 대해 계산해보고 결과에 저장한다.     
`next_permutation`으로 다음 경우를 만든다음 다시 계산해보고, 이전 경우의 값보다 크면 결과를 덮어씌운다.    
이렇게 하면 쉽게 답이 나온다!!    
[전체코드보기](10819.cpp) 

```cpp
sort(ary, ary + n);

do {
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += abs(ary[i] - ary[i + 1]);
    }
    rst = rst > sum ? rst : sum;
} while (next_permutation(ary, ary + n));
```

