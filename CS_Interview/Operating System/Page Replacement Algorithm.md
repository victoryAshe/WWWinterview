## 목차
* [개념 설명]()
* [페이지 교체]()
* [페이지 교체 알고리즘]()
  
## 개념 설명
<details>
<summary>📌 개념 목록</summary>
<div markdown="1">
  
* <b>가상 메모리</b> : 사용자의 논리적 메모리 개념과 실제적인 메모리 개념을 분리하여, 작은 메모리 공간으로도 큰 가상 주소 공간을 프로그래머에게 제공하는 기술  
    > 프로세스 실행에 필요한 전체 메모리 크기 중 당장 필요한 공간만을 실제 물리 공간에 할당  
    > 나머지는 가상으로만 할당해줬다가 필요해졌을 때에 실제 할당이 일어남!
  * **요구 페이징 기법**: 가상 메모리는 대개 page로 관리되며, process 실행 과정에서 필요한 page들만 메모리에 적재  
  -> 한 번도 접근 안된 page는 적재 X
  
* <b>page</b>: process가 점유하는 고정 크기의 논리적 메모리 block
  * **pager**: process 내 개별 page들을 관리
  * **page table**: process마다 존재하여, 논리 메모리인 page들의 순차적 실행을 돕기 위해 page들이 각각 저장된 실제 frame 위치 등을 저장해 놓은 자료구조.  
  ∵ page들은 외부적으로 단편화되어 frame에 저장되어 있으므로 그 실제 위치를 알려주지 않으면 순차 실행되기 힘들다.
  * **페이지 부재** *page default*: **요구 페이징 기법** *Demand Paging*에 관련하여, process 실행 中 필요해진 page를 메모리에 요청했는데 해당 page가 메모리에 적재되어있지 않은 상황
  * **victim page**: page 교체를 해야하는 상황에서 새로운 page 대신 *버려질(희생될)* 기존 page
  
* <b>frame</b>: 고정크기의 물리적 메모리 block
  * **page frame**: page를 저장할 수 있는 frame
  * **frame table**: frame들의 할당 상태 및 사용 可 여부, 총 frame 갯수 등을 담은 자료구조.

* <b>Belady의 모순</b>: page frame의 개수를 늘려도 page 부재 발생이 오히려 늘어난다는 모순
  
</div>
</details>
  
  
## 페이지 교체
[**Page Default**]() 발생 시, 요청했던 page를 보조 저장장치에서 불러와야 하는데 만약 물리 메모리가 모두 사용 중이면 일어난다.
> ※ 페이지 교체를 하지 않고, 운영체제가 해당 process를 강제종료 시키는 경우도 있음!
  
### 페이지 교체의 흐름
1. 디스크(보조 저장 자치)에서 필요한 page의 위치 찾기
2. 빈 [page frame]() 찾기  
  ⅰ) **page 교체 알고리즘**을 통해 [victim page]() 선택:   
  ⅱ) victim page를 disk에 기록하고, 관련된 [page table]() 수정  
3. 새롭게 비워진 page table 내의 frame에 새 page를 읽어오고, [frame table]() 수정
4. 사용자 process 재시작

## 페이지 교체 알고리즘
### FIFO: *First In First Out*
**먼저 물리 메모리에 들어온 순서**대로 victim page가 됨.   
페이지 교체 알고리즘 중 가장 간단하다.  
  
➕ 이해하기 · 프로그래밍이 쉬움  
➖  
  * 오래된 page(victim)가 나중에 필요해질 수 있는 정보를 담고 있을 수 있음 ex) 초기 변수
  * 처음부터 활발히 사용되던 page가 victim이 되어, page 부재율을 높일 수도 있음
  * [Belady의 모순]() 발생
  
### 최적(OPT): *Optimal*
**앞으로 가장 오래 사용되지 않을 page**를 victim으로 선택  
주로 비교 연구 목적으로 사용됨  
  
➕   
   * Belady의 모순 발생 X
   * 페이지 교체 알고리즘 중 가장 낮은 page 부재율 보장  

➖ 구현의 어려움   ∵ 모든 process의 메모리 참조 계획을 미리 파악할 방법이 없음  
   
### LRU: *Least Recently Used*
OPT의 근사 알고리즘으로, **가장 오랫동안 사용되지 않은 page**를 victim으로 선택  
대체로 FIFO보다는 우수하나, OPT보다는 낮은 성능을 보임  
  
### LFU: *Least Frequently Used*
**가정**: 활발히 사용되는 page는 참조 횟수가 많아진다.  
-> **참조 횟수가 가장 적은 page**를 victim으로 선택  
  
➖  
   * **초기 가정과 어긋나는 지점**이 발생할 수 있음  
      ex) process가 특정 page를 집중 사용하다가 다른 기능을 사용하는 경우  
        -> 사용되지 않는 page가 메모리에 머무를 수도 있음  
      
   * OPT를 제대로 근사하지 못해 잘 쓰이진 않음

### MFU: *Most Frequently Used*
**가정**: 참조 횟수가 가장 적은 page는 최근에 올라왔고, 앞으로 계속 사용된다.  
-> **참조 횟수가 가장 많은 page**를 victim으로 선택  
  
➖ OPT를 제대로 근사하지 못해 잘 쓰이진 않음  

## 출처
[Interview_Question_for_Beginner](https://github.com/JaeYeopHan/Interview_Question_for_Beginner/tree/master/OS#%EA%B0%80%EC%83%81-%EB%A9%94%EB%AA%A8%EB%A6%AC)



