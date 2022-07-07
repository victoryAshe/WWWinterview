# 4th Meeting
* [삽입 정렬](https://github.com/victoryAshe/WWWinterview/blob/main/CS_Interview/Sort/4thMeeting.md#%EC%82%BD%EC%9E%85-%EC%A0%95%EB%A0%AC----%EB%98%90%EB%A1%9C%EB%A6%AC)
* [버블 정렬](https://github.com/victoryAshe/WWWinterview/blob/main/CS_Interview/Sort/4thMeeting.md#%EB%B2%84%EB%B8%94-%EC%A0%95%EB%A0%AC----%ED%9D%90%EB%8A%90)
* [퀵 정렬](https://github.com/victoryAshe/WWWinterview/blob/main/CS_Interview/Sort/4thMeeting.md#%ED%80%B5-%EC%A0%95%EB%A0%AC--ashe)
---
## 삽입 정렬   *@ 또로리*
앞에서부터 차례대로 정렬되어있는 부분집합의 요소들과 하나씩 비교하며<br>
자신의 위치를 찾아 삽입하는 정렬

- 원리<br>
    두 번째 인덱스의 값을 삽입변수에 넣고<br>
    두 번째 인덱스에서 -1을 한 첫 번째 인덱스 값과 비교하며 시작한다.<br>
    다시 새로운 비교값인 왼쪽값이 삽입값보다 더 작아서 비교를 멈출 때까지 과정을 반복 한다.<br> 

- 최선<br>
    모든 요소들이 최대한 정렬되어 있을 경우 => 퀵정렬보다 강력 => O(N)<br>
    이유 - 가장 왼쪽 데이터와 한번씩만 비교를 진행<br> 
 
- 최악<br>
    모든 요소들이 역으로 정렬되어 모든 값과 비교하는 경우 => O(N^2)(평균도 동일)<br> 
    
- 선택 VS 삽입<br>
    둘 다 동일한 시간복잡도를 가지지만<br>
    최선에서<br>
    
    <br>
    선택 - 전체 아이템 스캔<br>
    삽입 - 필요한 아이템만 스캔<br>
    <br>
    
    더 나은 성능을 보이므로 삽입이 더 낫다.

---
## 버블 정렬 Bubble Sort  *@ 흐느*
![버블정렬](./images/bubble-sort.gif)
- 인접한 두 개의 데이터를 비교하는 것을 반복하며 정렬을 진행한다.
- 단순하고 직관적이며, 구현이 쉽지만, 그만큼 효율 면에서는 부족하기 때문에 실제로 활용되지는 않는다. 

```java
import java.util.Arrays;

public class BubbleSort {

    int[] intArray;

    public static void main(String[] args) {
        int[] intArrayEg = {20, 35, -15, 7, 55, 1, -22};
        BubbleSort bubble = new BubbleSort();
        bubble.sort(intArrayEg);
        Arrays.stream(intArrayEg).forEach(x -> System.out.println(x));
    }

    public void sort(int[] intArray) {
        this.intArray = intArray;

        for (int i = this.intArray.length-1; i>0; i--) {
            for (int j = 0; j < i; j++) {
                if (this.intArray[j] > this.intArray[j+1]) {
                    swap(j, j+1);
                }
            }
        }
    }

    private void swap(int j, int k) {
        if (j==k) return;
        int temp = this.intArray[j];
        this.intArray[j] = this.intArray[k];
        this.intArray[k] = temp;
    }

}
```

### 시간 복잡도
- O(N^2)
- 최악, 최선, 평균 모두 N^2의 시간복잡도를 갖는다.
  - 인접한 두 개의 데이터의 크기 비교 연산을 이중으로 반복한다.
  - 
### 공간 복잡도
- O(n)
  - 주어진 배열 안에서 swap(교환)을 통해 정렬이 수행된다.

### 특징
- 제자리 정렬 In-place Algorithm
  - 정렬을 하기 위해, 또 다른 정렬을 생성하지 않는다.
- 안정 정렬 Stable Sort
  - 인접한 두 값을 비교해, 순서의 변경이 필요한 경우만 swap 연산을 이용해 정렬한다.
  - 같은 크기의 값이 나열된 경우에는 swap 연산이 발생하지 않는다.

> 참조 자료
>  - https://github.com/GimunLee/tech-refrigerator/blob/master/Algorithm/%EA%B1%B0%ED%92%88%20%EC%A0%95%EB%A0%AC%20(Bubble%20Sort).md#%EA%B1%B0%ED%92%88-%EC%A0%95%EB%A0%AC-bubble-sort
> - https://github.com/GoForITStudy/CS_study/blob/main/Algorithm/Sort%20Algorithms.md

---
## 퀵 정렬  *@Ashe*
![Quick Sort gif](https://github.com/GimunLee/tech-refrigerator/raw/master/Algorithm/resources/quick-sort-001.gif)
- 분할 정복(divide and conquer) 방법 을 통해 주어진 배열을 정렬
- Merge Sort와 달리 배열을 비균등하게 분할

### 과정
1. 배열 가운데서 하나의 원소를 고른다. -> **피벗(pivot)**  
2. 분할(Divide): 피벗을 기준으로 배열을 둘로 나눈다. 
   - 피벗 앞: 피벗보다 값이 작은 모든 원소들
   - 피벗 뒤: 피벗보다 값이 큰 모든 원소들
   - 분할을 마친 뒤에 피벗은 더 이상 움직이지 않는다.
3. 재귀(Recursion): 분할된 두 개의 작은 배열에 대해 위 과정을 반복  
* 재귀 호출이 한번 진행될 때마다 최소한 하나의 원소는 최종적으로 위치가 정해지므로, 이 알고리즘은 반드시 끝난다는 것을 보장할 수 있다.

### 시간 복잡도 *T(n)*
이동 횟수는 비교 횟수보다 적으므로 계산에서 무시한다.
- **최선**: `O(nlog₂n)`
   - `n=2^k`일 때, 순환 호출의 깊이 = `k`
   - 순환 호출의 깊이 `n` * 각 순환 호출 단계의 비교 연산 `nlog₂n` = `nlog₂n`
- **최악**: `O(n^2)`  
   -  정렬하고자 하는 배열이 오름차순 정렬되어있거나 내림차순 정렬되어있는 경우
   -  `n=2^k`일 때, 순환 호출의 깊이 = `n`
   -  순환 호출의 깊이 * 각 순환 호출 단계의 비교 연산 = n^2  
- **평균**: `O(nlog₂n)`

### 공간 복잡도
- `O(n)`
- **제자리 정렬**: 주어진 배열 안에서 교환(swap)을 통해, 정렬이 수행됨

### 장점
- **시간 복잡도 = `O(nlog₂n)`**: 다른 정렬 알고리즘과 비교했을 때 가장 빠름
   - 불필요한 데이터의 이동을 줄이고 먼 거리의 데이터를 교환
   - 한 번 결정된 피벗들이 추후 연산에서 제외됨
- **제자리 정렬**: 정렬하고자 하는 배열 안에서 교환하는 방식이므로, 다른 메모리 공간을 필요 X

### 단점
- **불안정 정렬(Unstable Sort)**
- 정렬된 배열에 대해서는 Quick Sort의 불균형 분할에 의해 오히려 수행시간이 더 많이 걸림

### 출처
[GimunLee/tech-refrigerator](https://github.com/GimunLee/tech-refrigerator/blob/master/Algorithm/%ED%80%B5%20%EC%A0%95%EB%A0%AC%20(Quick%20Sort).md)
