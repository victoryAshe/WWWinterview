<hr>
# static멤버 vs non-static 멤버
<hr>

<br>

||클래스 변수(Static변수)|인스턴스 변수(Non-Static변수)|지역 변수|
|:------:|:---:|:---:|:---:|
|**정의**|클래스 내에 Static 키워드로 선언된 변수|클래스 내에 선언된 변수|메소드 블럭 안에 선언된 변수|
|**라이프 싸이클**| 프로그램의 생성과 종료를 같이함<br>(JVM 실행 후 클래스가 메모리에 올라갈 때 <br>~ 프로그램이 종료될떄까지 유지)|객체의 생성과 종료를 같이함|메소드의 생성과 종료를 같이함|
|**생성 횟수**|1번<br>(클래스가 메모리에 올라갈 때)<br>=> 클래스의 생성 횟수와 상관 X |객체 생성마다<br>매번 새로운 변수가 생성|메소드 생성마다 매번 새로운 변수가 생성|
|**동일한 클래스의<br>모든 객체들에 의한 공유 여부**|O|X|X|
|메모리에 적재되는 위치|Satic Area|Stack|Stack|

## ex)
  ![](https://user-images.githubusercontent.com/33229855/109810230-9ef37680-7c6c-11eb-9cf5-1651fd0ff11d.png)
  ![](https://user-images.githubusercontent.com/33229855/109814411-d0bb0c00-7c71-11eb-90b8-a9c6158d53e9.png)
  Heap 영역(동적할당영역) - new()로 생성된 객체가 할당

<br>

## static 변수가 필요한 이유
  C/C++과 다르게,  
  자바는 캡슐화 원칙에 따라서 어떤 변수나 함수도 클래스 바깥에 존재할 수 없으므로  
  필요할 때에 전역변수나 전역메소드로 사용하기 위함

<br>

## static 변수 사용에 주의할 점
  - 실제 static 멤버의 생성 시점은 JVM에 따라 다르다.
  - 보통 JVM은 필요한 대부분의 클래스를 처음부터 로딩하기 때문에  
    static멤버의 생성 시점은 JVM이 시작되는 시점이라고 할 수 있다.

<br>

## static 변수의 제약조건
  - static 메소드는 오직 static멤버만 접근 가능
    static메소드도 static멤버와 로드되는 시점이 동일하기 때문에  
    객체가 생성되지 않은 상황에서도 변수를 사용할 수 있어야 한다.
  - this 키워드 사용 불가 ( ∵ static메소드는 객체가 생성되지 않은 상황에서도 호출이 가능 )
    this - 호출 당시 실행 중인 객체를 가리키는 레퍼런스
  
<br>
<br>
<br>

<hr>

# 클래스 vs 객체 vs 인스턴스
## 클래스
객체를 특성(속성+기능=>변수+메서드)에 따라 분류하여 통칭할 수 있는 집합적 개념

<br>

## 객체(Object)
OOP 관점에서 클래스에 선언된 것대로 생성되어 선언이 되어있는 실체

### 특징
- 클래스의 인스턴스
- 현실 세계에 가까운 개념
- 실체에 초점

<br>

## 인스턴스(Instance)
메모리에 할당해서 객체를 실체화한 것
### 특징
- SW 세계에 가까운 개념
- 추상적인 개념(명세)와 구체적인 객체 사이의 관계에 초점을 맞출 경우에 사용하고 클래스와 객체 사이의 관계로 한정지어서 사용할 필요는 없다.

<br>

## 비교

### * 클래스 vs 객체  
컴퓨터 프로그램을 만드는 과정에서 개발자는 바로 해당 애플리케이션의 창조자가 된다.  
그래서 우리도 객체 지향 프로그래밍을 할 때 클래스를 먼저 설계 하게 된다.  
그런데 이게 객체 지향의 추상화와 무슨 관련이 있을까?  
사람이라는 클래스를 설계 한다고 해보자. 사람 클래스를 만들기 위해 주변에서 보이는 실체들, 사람 객체들을 관찰해서 사람 객체들이 가진 공통된 특성을 찾게 된다.  
시력, 몸무게, 혈액형, 직업, 연봉, 자동차 유무 등등 무수한 속성을 갖게 되며,
먹다, 자다, 일하다, 노래듣다 등 무수한 기능/행위를 갖는다.  
그런데 사람 클래스가 사람 객체들의 모든 특성을 나열할 수 있을까? 또 그럴 필요가 있을까?
여기서 또 하나의 개념이 나온다. 바로 애플리케이션 경계다.
때로는 애플리케이션 경계를 컨텍스트(Context)라고 부르기도 한다.
애플리케이션 경계를 알기 위해서는 단순한 질문 하나만 던져 보면 된다.
"내가 창조하려는 세계는 어떤 세상인가?"  
조금 더 프로그래밍적으로 질문을 바꾼다면 다음과 같이 바꿀 수 있을 것이다.
"내가 만들고자 하는 애플리케이션은 어디에서 사용될 것인가?"
만약 병원 애플리케이션을 만들고 있다면 사람은 환자를 의미하는 좀 더 구체적인 이름으로 바꿀 수 있을 것이고 클래스 설계도 달라질 것이다. 병원 애플리케이션이라고 생각하니 사람 클래스에서 필요 없는 특성들이 보이기 시작한다.

<br>

### * 객체 VS 인스턴스
인스턴스가 인스턴스화하여 레퍼런스를 할당한 객체라고 하지만  
이는 원본(추상적인 개념)으로부터 생성되었다는 것에 의미를 부여하는 것일 뿐 엄격하게 객체와 인스턴스를 나누긴 어렵다.

<br>

## 비유
클래스 : 객체 개념에서 비롯된다.
- 사람 : 김연아 = 쥐 : 미키마우스
- 사람 줄리엣 = new 사람();  
사람이라는 클래스(분류)를 이용해 유일무이하고 새로운 하나의 사람(객체)을 만들어 홍길동(객체 참조 변수)이라는 이름을 지어준 것이다.  
그런데 클래스를 이용해 object를 만들었다는 것을 강조할 때는 object라는 표현보다는 클래스의 인스턴스(instance)라는 표현을 쓴다.  
=> 객체(object) = 클래스의 인스턴스

<br>
<br>
<br>

<hr>
# 직렬화 vs 역직렬화
<hr>

## 직렬화  
JVM의 힙/스택 메모리에 있는 객체 데이터 **==변환==>** 외부의 자바 시스템에서도 사용할 수 있는 바이트 형태

```java
@Entity
@AllArgsConstructor
@toString
public class HubContent implements Serializable {
private static final long serialVersionUID = 1L;
    
private String title;
private String subtitle;

HubContent hubcontent = new HubContent("제목", "부제");
byte[] serializedHubContent;
try (ByteArrayOutputStream baos = new ByteArrayOutputStream()) {
try (ObjectOutputStream oos = new ObjectOutputStream(baos)) {
    oos.writeObject(hubContent);
        
    // 직렬화된 HubContent 객체
    serializedHubContent = baos.toByteArray();
}
}
```

### * 특징  
객체들의 데이터를 연속적인 데이터로 변형하여 Stream을 통해 데이터를 읽도록 해준다. 

### * 용도  
객체들을 통째로 파일로 저장하거나 전송하기 위함

### * 조건  
  자바.io.serializable 인터페이스 상속 받거나  
  Serializable을 implement한 클래스를 상속받아서 직렬화가 가능한 클래스 객체  
  ( int, long, String 등 자바의 기본 자료형 or Serializable을 구현한 클래스 객체 )

### * 방법  
ObjectOutputStream 객체 이용(일단 내보내는거니까)

<br>

## 역직렬화
직렬화된 바이트 데이터 **==변환==>** JVM에 상주하는 객체

```java
try (ByteArrayInputStream bais = new ByteArrayInputStream(serializedHubContent)) {
    try (ObjectInputStream ois = new ObjectInputStream(bais)) {
        
      // 역직렬화된 HubContent 객체를 읽어온다.
      Object objectHubContent = ois.readObject();
      HubContent hubContent = (HubContent) objectHubContent;
    }
}
```

### * 조건  
- **직렬화된 대상이 된 객체의 클래스가 클래스 패스에 존재해야하고  
    import된 상태**  
    (∵ 같은 시스템 내부라도 역/직렬화를 진행하는 시스템의 소스 버전이 다를 가능성 有)

- **자바 직렬화 대상 객체와의 동일한 serialVersionUID**  
    직렬화하면 내부에서 자동으로 SerialVersionUID라는 고유의 번호를 생성하여 직렬화와 역직렬화 할 때 상호간의 key 역할을 하도록 관리한다.  
    만약 이 SerialVersionUID가 맞지 않는다면 다음과 같은 오류를 출력한다.  
    `java.io.InvalidClassException: com.java.test.User; local class incompatible: stream classdesc serialVersionUID = -2617558951961522125, local class serialVersionUID = 3278902038563169060`
    - 직접 관리하는 이유  
    serialVersionUID를 직접 선언하지 않아도 내부적으로 클래스의 구조 정보를 이용해 자동으로 생성된 해쉬값이 할당되지만 클래스의 멤버 변수가 추가되거나 삭제되면 serialVersionUID가 달라진다.

<br>

- **클래스의 멤버 변수 타입이 같아야함**
  
- **멤버 변수를 제거하거나 변수명을 바꾸지 않아야 한다.**  
  (∵ 예외는 발생하지 않지만 데이터의 누락발생)

### * 방법
ObjecttInputStream 객체 이용 (일단 읽어들이는 거니까)

<br>
<br>
<br>

<hr>
# GC(Garbage Collection. 가비지 컬렉션)
<hr>

JVM의 실행엔진에서 메모리 최적화를 위해  
Heap 영역에 저장되는 객체들 중 더 이상 참조되지 않는 객체를 모아서 정리하는 기능

## * 가비지 콜렉터가 하는 일
- 메모리 할당
- 사용 중인 메모리 인식
- 미사용 메모리 인식

<br>

## * Stop the World
모든 애플리케이션 스레드의 작업이 멈추는 상태.
- 자바 애플리케이션은 GC 실행 시, GC 실행 스레드를 제외한 모든 스레드를 멈추고  
  GC 완료 후 다시 스레드들을 실행 상태로 변경
- 어떤 GC 알고리즘을 사용하더라도 Stop the World는 불가피하며 최소화하기 위해 GC 튜닝을 진행

<br>

## * 가비지 콜렉터가 들리는 Heap 메모리 영역 상세
![alt](https://github.com/WeareSoft/tech-interview/raw/master/contents/images/JVMHeap.png)

### 원리
  - Young 영역에 있는 객체는 각 하위 영역이 가득 차면 Miner GC가 동작하여 더이상 참조되지 않는 객체 제거
  - Old 영역에 있는 객체는 영역이 가득 차면 Major GC(Full GC)가 동작하여 더이상 참조되지 않는 객체 제거

<br>

### 동작 과정
객체를 최초 생성하면 Young 영역 중 Eden 영역에 위치  
-> Eden 영역에서 Miner GC 발생 시, 참조 중인 객체라면 Survivor1로 이동  
-> Survivor1에서 Miner GC 발생 시, 참조 중인 객체라면 Survivor2로 이동  
-> Survivor2에서 Miner GC 발생 시, 참조 중인 객체라면 다시 Survivor1 영역으로 이동  
  (Survivor1 <--> 2 반복)  
-> Survivor 영역이 가득 차거나 Young 영역에서 오래 살아남은 객체는 Old 영역으로 이동
- age bit  
    Miner GC에서 살아남은 횟수를 기록하는 값.  
    => 오래 살아남은 객체는 해당 비트 수가 높은 값  

-> Old 영역에 있는 객체는 Major GC가 발생했을 때 참조 여부에 따라 공간이 유지되거나 제거

<br>

### * java9의 default GC
G1GC(Garbage First Garbage Collector)
- 특징
  - Java 9, 10의 default GC
  - 활성화 옵션  
    -XX:+UseG1GC
  - 큰 메모리를 가진 멀티 프로세스 시스템에서 사용하기 위해 개발된 GC
  - Stop the World 최소화 목적(실시간 GC는 불가능)

<br>

- G1GC vs ParallelGC  
G1은 더 짧은 주기의 Full GC 작업을 수행하여 전체적인 처리량이 줄어드는 대신  
일시 정지 시간을 크게 단축

  - ParallelGC  
    Java 7, 8의 default GC로서  
    Old Generation 영역에서만 Full GC(공간 재확보 및 조각 모음) 수행

<br>
<br>
<br>

<hr>
# Call by value vs Call by Reference
<hr>

함수가 호출될 때, 메모리 공간 안에서는 함수를 위한 별도의 임시 공간이 생성된다.
||Call by Value|Call by Reference|
|:------:|:---:|:---:|
|**정의**|값에 의한 호출|참조에 의한 호출|
|**함수 호출 시 전달 인자**|복사된 변수의 값|변수의 레퍼런스|
|**함수 내에서 인자값 변경 시<br>외부변수 값 변경**|X<br>(∵지역적으로 사용되는 local value의 특성)|O|

<br>

cf) Java는 Call by <u>Value(=기본자료형의 값 또는 객체에 대한 레퍼런스)</u>
- 기본자료형의 경우  
  해당하는 변수의 값을 복사해서 전달한다.

- 참조자료형의 경우  
  해당하는 변수가 가지는 값이 레퍼런스이므로  
  인자로 넘길 때 Call by Value에 의해 변수가 가지고 있는 레퍼런스가 복사되어 전달된다.
  (참조변수 p 자체의 레퍼런스가 아닌 p가 저장하고 있는 값(이것도 레퍼런스))
