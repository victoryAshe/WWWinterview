# Semaphore AND Mutex @ 또로리

## **배경**
- **프로세스 간의 통신**  
동시에 실행되는 프로세스끼리 데이터를 읽기/쓰기 연산을 통해 주고 받는 작업

<br>


- **공유자원**  
프로세스 간의 통신 중에 여러 프로세스가 공동으로 이용하는 자원(변수, 메모리, 파일, 하드웨어 등)  

<br>


- **임계구역(Critical section)**  
공유 자원에 접근하는 코드의 영역  
ex) 각 프로세스가 전역 변수 사용하는 곳(예금 확인→입금→예금 저장하는 부분)  
⇒ 임계영역은 공유 자원 접근 순서에 따라 실행 결과가 달라지는 프로그램의 영역이므로  
1개의 프로세스만 실행되도록 해야한다.

<br>


- 공유자원 접근 시, 발생 가능한 문제
 : 경쟁 조건(Race condition) 문제  
2개 이상의 프로세스가 동시에 공유 자원을 읽거나 쓰는 상황  
ex) 예금 기존 잔액으로 10만원이 있는 것을 두 프로세스가 동시 확인   
→ 각각 10,5만원 입금 시에 25가 되어야 하는데
다른 프로세스의 작업을 무시하고 덮어써서 결과값 달라짐  
⇒ 대안 : 동기화  
병행 프로세스 작업 중에 발생하는 경쟁조건 문제를 방지하기 위해 프로세스들의 공유 자원 접근 순서를 정하기 위함.  

<br>

- 고전적인 동기화 문제
  - 유한 버퍼 문제(bounded-buffer problem)
  - Readers-Writers 문제(The Readers-Writers Problem)
  - 식사하는 철학자들 문제(The Dining-Philsophers Problem)

<br>

- 임계구역 문제 해결을 위한 요구 조건
    1. 상호 배제(Mutual exclusion) ★  
    Race condition과 같은 문제를 막기 위해서 등장한 개념으로  
    한 프로세스가 임계구역에 들어가면 다른 프로세스는 들어갈 수 없어야 한다.
    2. 한정 대기(Bounded waiting)  
    어떤 프로세스든 무한 대기하지 않아야 한다.  
    ⇒ 프로세스 임기 영역 진입은 유한한 시간 내에 허용되어야 한다.
 
    3. 진행의 융통성(Progress flexibility)  
    한 프로세스가 다른 프로세스의 진행을 방해해서는 안된다.

- 임계구역 문제 해결 방법(동기화 방법)  
여러 개의 프로세스를 어떻게 동기화할 것인가가 핵심
  - MUTEX(Mutual exclusion.뮤텍스.상호배제) 기법
  - Semaphore(세마포어) 기법  

    
  
<br>

## MUTEX(Mutual exclusion.뮤텍스.상호배제) 기법
임계구역에 오직 하나의 프로세스가 접근하도록 다른 프로세스는 막아주는 기법

![alt](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/2d597bb4-5bc7-4d2a-ad2c-0d8ccd3b8669/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20220803%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20220803T072401Z&X-Amz-Expires=86400&X-Amz-Signature=2f3ad521ba16fc341a9f66f848dec147d92473335e9e75ccb39c4accdbdfb6bc&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22Untitled.png%22&x-id=GetObject)

### * 특징
![alt](https://blog.kakaocdn.net/dn/bRk7ZC/btrjDfRyr0w/mkrLaphliLGifZIxHLG7DK/img.png)
![alt](https://blog.kakaocdn.net/dn/cMxqzF/btrjud9guz0/5ekgkoGoxAO7o0IgFYyiI0/img.png)
- 동기화 대상 : 1개
- 상호배제 달성 방법
한 프로세스에 의해서만 소유될 수 있는 키 객체를 가지고 락(Lock)을 사용

### * SW적 해결방법
- 특징  
  현재 OS에서 더 이상 쓰이지 않는 방법

<br>

- 기본 연산
    - 임계 영역 진입 전 진행 상황 검사
    - 임계 영역 벗어나기 전 후처리

<br>

- 대안과 문제점
  - CASE 1)  
  임계구역 문제를 해결하기 위해 lock 1개를 사용
    - 문제점
        - 상호배제 위배
        - 무한루프 ⇒ 시스템 자원 낭비
  - CASE 2)    
    상호배제 위배 문제를 보완하기 위해 lock을 2개 사용한다.  
    일단 잠금을 하고 다른 프로세스가 잠겼는지 확인하므로 두 프로세스의 상호 배제가 보장된다.
    - 문제점
        - 한정대기 위배
        ⇒ 교착상태(Deadlock) 발생(6장)  
        : 두 개 이상의 작업이 서로 상대방의 작업이 끝나기 만을 기다리고 있기 때문에  
        한정 대기 조건을 보장받지 못해서 임계구역에 대한 작업이 진행되지 못하는 상태
       
       - 프로세스 개수에 비례하는 lock 변수 개수 ⇒ 비효율적인 확장성

  - CASE 3)  
공유 변수 lock의 <u>값의 구분</u>을 통해 다른 프로세스가 임계구역에 있는지 확인하고 없으면 진입  
⇒ 하나의 잠금 확인 문장으로 상호 배제와 한정 대기를 보장한다.
    - 문제점  
    진행의 융통성 위배  
    ⇒ 각각의 프로세스가 우선순위에 상관없이 한 번에 한 번만 번갈아 가며 실행  
    ⇒ 경직된 동기화(Lockstep synchronization) 발생  
        : 프로세스의 진행이 다른 프로세스로 인해 방해받는 현상
- 해결책
  - 데커 알고리즘(Dekker’s Solution)  
기존 Lock 방식이 지닌 문제점을 보완하기 위해  
<u>임계공유 변수 turn를 추가함으로써</u> 임계 구역에 들어갈 프로세스/스레드를 결정하는 방식

  - 피터슨 알고리즘(Peterson’s Solution)      
    데커 알고리즘 방식 + 하나의 프로세스에게 양보하도록 하는 방식  
    - 조건 만족  
      상호 배제 O, 한정된 대기 O, 진행 O(P2는 P1의 한 번의 출입 후 구역 진입)
      
    - 특징  
        - 초기에는 2개의 프로세스만 사용 가능했지만  
        이후 3개 이상의 경우에도 적용할 수 있는 방법이 논의되고 있다.
        - 현대의 컴퓨터 구조에서의 작동이 보장되지 않는다.  
        프로세스 또는 컴파일러는 성능 향상을 위해 종속성이 없는 읽기 및 쓰기 작업들을 재정렬 할 수도 있음  
        ⇒ 명령어가 재배치가 되면 Peterson 방법은 상호 배제를 보장 X  
             ( EX - 진입구역에서 lock1=true;와 true=2;의 순서를 바꾸면 보장 X )  
        ⇒ 현재 컴퓨터구조에서는 적합하지 않다.

        - 바쁜 대기 ⇒ CPU 효율성 저하

<br>

### * HW적 해결방법 - 동기화를 위한 하드웨어 지원
- 배경  
임계구역에 대해 단순히 인터럽트 발생을 금지시킨다면?

  - 단일 처리기 환경  
    명령어의 현재 순서대로 실행됨

  - 다중 처리기 환경  
  메시지가 모든 처리기에 인터럽트 불능 전달  
⇒ 각 임계 구역에 진입 지연 시킴, 시스템 클록 갱신  
⇒ CPU 효율 저하

  오늘날의 다중처리기 환경에서  
임계구역에서의 문제를 해결하기 위한 하드웨어적인 동기화 방법으로서
3가지 명령어 제공

<br>

- 종류
  - 메모리 장벽(Memory Barriers/Fences)  
  컴퓨터 아키텍처가 메모리의 모든 변경 사항을 다른 모든 프로세서로 전파하는 명령어  
  ⇒ 다른 프로세서에서 실행 중인 스레드에 메모리 변경 사항이 보이는 것을 보장

  - 하드웨어 명령어 (Hardware Instructions) - 원자적 명령어  
  단어의 내용을 검사 및 변경하거나  
  2가지의 워드의 내용을 원자적으로(Atomic) 교환할 수 있는,  
  즉 인터럽트 되지 않는 하나의 단위로서의 HW 명령어  
  (실행 중 interrupt를 받지 않음으로써 다른 프로세스에 선점되지 않음)
      - 특징  
      둘 다 하드웨어 명령(기계어 명령)이라서  
      일반적으로 고급 언어를 사용하는 사용자 입장에서는 이 명령어를 사용할 수 없는 경우가 많다.  
      (c, java에 이런 명령 들어가 있지 않다.)
      - 종류
          - test_and_set()
              
              ![Untitled](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/eb29ffac-2df6-407e-8ff5-8acf79338826/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20220804%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20220804T065048Z&X-Amz-Expires=86400&X-Amz-Signature=4e24b21c96869e12f9c7589dcf0b8c038060200789d18dbc6b6f3e86f841a901&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22Untitled.png%22&x-id=GetObject)
              
              원래 target 이 가지고 있던 값을 결과로 돌려주면서  
              동시에 target 값을 true로 변경  
              (앞선 예제처럼 두 개가 떨어진 명령이라면 임계구역 보장 x)  
              ⇒ 명령어 실행 중간의 타임아웃에 따른 임계구역 위협 문제 방지  
              
              - 조건 만족 : 상호배제 O, 한정대기 X, 진행 O
              - 착안된 알고리즘  
                  lock이라는 공유 변수가 한 프로세스에서 false일 경우 lock을 true로 만들고 자신은 임계구역으로 들어간다. 임계구역에서 빠져나온 프로세스가 lock을 false로 만들면 다른 프로세스가 들어가는 과정이 반복되는 알고리즘
          
          <br>  

          - compare_and_swap()  
          두 워드의 내용 교환에 기반을 둔 다른 기법

    <br>  

          
  - 원자적 변수 (Atomic Variables)  
  정수 및 부울과 같은 기본 데이터 유형에 대한 원자적 연산을 제공

<br>

- 장점
    - 단일 프로세서와 공유 메모리 기반 다중 프로세서에 모두 적용 가능
    - 간단하고 검증하기 쉬움
    - 서로 다른 변수를 사용하면 다중 임계영역 지원

<br>

- 단점  
    - 바쁜 대기(Busy-waiting)  
    - 기아,교착 상태 발생 가능

<br>

## Semaphore(세마포어) 기법   
사용가능한 공유자원의 개수를 의미하며  
프로그래밍 언어 수준에서 임계영역에 여러 프로세스가 접근하는 것을 막아주는 역할을 한다.  

cf) 세마포어  
깃발(기차 교차로에서 기차 교통을 통제하기 위해 사용), 정수 값을 갖는 변수.

![alt](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/5b14564d-a342-47bd-990f-b347d71d9c0b/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20220803%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20220803T140449Z&X-Amz-Expires=86400&X-Amz-Signature=8ffa8092e6b019491fc7682e1d37cb85f41638c71fff4eef38f9cbe8fa5b16e0&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22Untitled.png%22&x-id=GetObject)

<br>


### * 특징
- 동기화 대상 : 하나 이상
- 공유 자원에 접근할 수 있는 프로세스의 최대 허용치만큼 동시에 사용자가 접근 가능
- 자원을 사용하지 않는 상태가 될 때, 대기하던 프로세스가 즉시 자원을 사용하고  
이미 다른 프로세스에 의해 사용중이라는 사실을 알게 되면 재시도 전에 일정시간 대기

<br>

### * 목적  
한정된 수의 사용자만을 지원할 수 있는 공유 자원에 대한 접근을 통제하기 위함

<br>

### * 상호배제 달성 방법  
  사용가능한 자원의 수를 공통으로 관리하는 하나의 값(세마포어)으로 이용  
  (각 프로세스는 세마포어의 값을 확인하고 변경 가능)  

<br>

### * 기본 연산
- 초기화 연산(Initialize operation)  
세마포어 값을 음이 아닌 값으로 초기화한다.

- wait( ) - 대기 연산(Wait operation)  
세마포어 값을 감소시킨다.
  - 값이 음수 : 호출한 프로세스는 블록(수면) 된다.
  - 값이 양수 : 프로세스는 계속 수행 가능

- signal( ) - 시그널 연산(Signal operation)  
세마포어 값을 증가시킨다.  
값이 양수가 아니면 블록된 프로세스를 깨운다.  

<br>

### * 문제점
- 프로세스가 세마포어를 사용하지 않고 바로 임계구역에 들어간 경우
- 시그널 신호가 발생하지 않은 경우  
=> 프로세스 간의 동기화가 이루어지지 않아 세마포어 큐에서 대기하고 있는 프로세스들이 무한 대기 발생
- 대기연산과 시그널연산을 반대로 사용하여 상호 배제가 보장되지 않은 경우


