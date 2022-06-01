# 3rd Meeting
* [Quick Sort](https://github.com/victoryAshe/WWWinterview/blob/main/CS_Interview/Sort/3rdMeeting.md#quick-sort)
* [Heap Sort](https://github.com/victoryAshe/WWWinterview/blob/main/CS_Interview/Sort/3rdMeeting.md#heap-sort)
* [Merge Sort](https://github.com/victoryAshe/WWWinterview/blob/main/CS_Interview/Sort/3rdMeeting.md#merge-sort)
---
## Quick Sort   *@ 또로리*




---
## Heap Sort   *@ 흐느 @ 보라*



---
## Merge Sort   *@Ashe*
합병 정렬이라고도 부르며, 분할 정복 방법을 통해 구현한다.  
Quick Sort와 함께 많이 언급되는 빠른 정렬 방식이나, Quick Sort와는 반대로 **안정 정렬**에 속한다.  
![Merge Sort](https://gmlwjd9405.github.io/images/algorithm-merge-sort/merge-sort-concepts.png)

**공간 복잡도**: O(n)  
||**시간 복잡도**||
|:---:|:---:|:---:|
|**평균**|**최선**|**최악**|
|Θ(nlogn)|Ω(nlogn)|O(nlogn)|


**방식**
1. 배열의 길이가 0 또는 1이면 이미 정렬된 것으로 생각
2. else: 정렬되지 않은 배열을 절반으로 잘라 비슷한 크기의 두 배열로 나눔
3. 각 부분의 배열을 재귀적으로 합병 정렬을 이용해 정렬  
   3-1. 2개의 배열 값들을 처음부터 하나씩 비교해 더 작은 값을 새로운 배열(sorted)로 옮김  
   3-2. 둘 중 하나가 끝날 때까지 3-1을 반복  
   3-3. 하나의 배열이 끝나면 나머지 배열 값을 전부 새로운 배열(sorted)로 복사
   3-4. 새로운 배열(sorted)를 원래의 배열로 옮김
4. 두 배열을 다시 하나의 정렬된 배열로 합병
>📌 실제로 정렬이 이루어지는 시점은 2개의 리스트를 합병하는 단계!  


**예시**
![Merge Sort Example](https://gmlwjd9405.github.io/images/algorithm-merge-sort/merge-sort.png)

### 안정 정렬과 불안정 정렬
* **안정 정렬***Stable Sort*: 중복된 값을 입력 순서와 동일하게 정렬되는 알고리즘 (중복된 부분은 순서가 유지됨)  
   * 삽입정렬, 병합정렬, 버블 정렬 등이 포함됨!  
* cf) **불안정 정렬***Unstable Sort*: 중복된 값이 입력 순서와 동일하지 않게 정렬되는 알고리즘
   * 퀵정렬, 선택정렬, 계수정렬 등이 포함됨!  

### 출처
1. [JaeYeopHan/Interview Question for Beginner](https://github.com/JaeYeopHan/Interview_Question_for_Beginner/tree/master/Algorithm#sorting-algorithm)
2. [gyoogle/tech interview for developer](https://github.com/gyoogle/tech-interview-for-developer/blob/master/Algorithm/MergeSort.md)
3. [Heee's Development Blog](https://gmlwjd9405.github.io/2018/05/08/algorithm-merge-sort.html)






