# [BOJ] 2309. 일곱 난쟁이
| 티어 | 유형 | 푼 언어 | 링크 |
| :-: | :-: | :-: | :-: |
|브론즈1|`수학` `정렬`|c++|[BOJ 2309](https://www.acmicpc.net/problem/2309)|

![alt text](image.png)

## 접근 #1
정렬은 원소가 9개이기 때문에 버블정렬로 쉽게 구현했다.   
그냥 무식하게 반복문 돌려서 모든 경우를 확인해봤다. [코드보기](2309-1.cpp)   
```cpp
for (int a = 0; a < 9; a++) {
    for (int b = a + 1; b < 9; b++) {
        for (int c = b + 1; c < 9; c++) {
            for (int d = c + 1; d < 9; d++) {
                for (int e = d + 1; e < 9; e++) {
                    for (int f = e + 1; f < 9; f++) {
                        for (int g = f + 1; g < 9; g++) {
                            if (height[a] + height[b] + height[c] + height[d] + height[e] + height[f] + height[g] == 100) {
                                cout << height[a] << endl;
                                cout << height[b] << endl;
                                cout << height[c] << endl;
                                cout << height[d] << endl;
                                cout << height[e] << endl;
                                cout << height[f] << endl;
                                cout << height[g] << endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
}
```


## 접근 #2
접근 #1이 너무 무식한 방법이라 다른 방법을 찾았다.   
`(전체 배열의 합 - 100)`이 되는 두 원소를 찾고, 그 원소를 제외하고 출력하면 된다. [코드보기](2309-2.cpp)
```cpp
for (int i = 0; i < 9; i++) {
    sum += height[i];
}

int diff = sum - 100;

for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
        if (height[i] + height[j] == diff) {
            for (int k = 0; k < 9; k++) {
                if (k != i && k != j) {
                    cout << height[k] << endl;
                }
            }
            return 0;
        }
    }
}
```
