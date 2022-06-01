# 2nd Meeting
* [TCP가 신뢰성을 확보하기 위해 사용하는 프로토콜](https://github.com/victoryAshe/WWWinterview/blob/main/CS_Interview/Network/2ndMeeting.md#tcp%EA%B0%80-%EC%8B%A0%EB%A2%B0%EC%84%B1%EC%9D%84-%ED%99%95%EB%B3%B4%ED%95%98%EA%B8%B0-%EC%9C%84%ED%95%B4-%EC%82%AC%EC%9A%A9%ED%95%98%EB%8A%94-%ED%94%84%EB%A1%9C%ED%86%A0%EC%BD%9C)
* [로드 밸런싱](https://github.com/victoryAshe/WWWinterview/blob/main/CS_Interview/Network/2ndMeeting.md#%EB%A1%9C%EB%93%9C-%EB%B0%B8%EB%9F%B0%EC%8B%B1)
* [Blocking/Non-blocking & Synchronous/Asynchronous](https://github.com/victoryAshe/WWWinterview/blob/main/CS_Interview/Network/2ndMeeting.md#blockingnon-blocking--synchronousasynchronousv)
---
## TCP가 신뢰성을 확보하기 위해 사용하는 프로토콜   *@Ashe*
### 용어 설명
**TCP***Transmission Control Protocol*: 트랜스포트 계층에서, 애플리케이션 계층에 **신뢰적 · 연결지향형 서비스**를 제공하는 네트워크 계층 프로토콜.  
**세그먼트**: TCP, UDP의 각 패킷   
**데이터그램**: 네트워크 계층 패킷  
**RDT***Reliable Data Transfer protocol*: 신뢰적인 데이터 전송 프로토콜  
**pkt**: packet의 약자.  / **rcv**: receive의 약자.  

### 신뢰성 있는 데이터 전송: RDT 3.0 프로토콜_비트 오류와 패킷의 손실이 있는 채널 상에서의 신뢰적 데이터 전송
**어떻게 패킷 손실을 검출할 것인가?**: 송신자에게 손실된 패킷의 검출과 회복의 책임을 부여  
* 시간 기반의 재전송 매커니즘: **Countdown Timer 이용**  
   1. 매 패킷(첫 번째/재전송 패킷)이 송신된 시간에 타이머를 시작  
   2. 타이머 인터럽트에 반응 (적당한 행동을 취함)  
   3. 타이머를 멈춤  
 
**패킷 손실이 발생했을 때 어떤 행동을 할 것인가?**: 패킷 재전송, 중복된 데이터는 패킷의 순서번호를 통해 detect

### 송신자에 대한 유한 상태 머신
![rdt 3.0 송신자 FSM](https://user-images.githubusercontent.com/80302657/171311445-c83eff00-335d-4d5c-a7e6-249e796d17cf.png)
**Alternating-bit protocol**: rdt 3.0의 동작에서 **패킷 순서번호가 0과 1이 번갈아 일어나므로** 붙여진 별칭.  

###  TCP의 RDT를 위해 제공되는 메커니즘
**체크섬**: 전송된 패킷 안의 비트 오류를 발견하는 데 사용됨  
  
**타이머**: 채널 안에서 패킷이 손실되었기 때문에 발생되는 패킷/ACK의 타임아웃/재전송에 사용됨.  
            지속 타임아웃(타임아웃은 패킷이 지연되었지만 손실되지는 않았을 때)/ 패킷이 정상적으로 수신되었으나 ACK가 손실되었을 때 발생  
            -> 수신자에 의해서 수신되는 패킷은 중복 복사(수신)된 패킷일 수 있음  
  
**순서번호**: 송신자 ▶ 수신자의 데이터 패킷 순서 번호를 붙이기 위해 사용됨.  
              수신산 패킷의 순서 번호에 격차가 있다면: 수신자는 손실된 패킷을 검사함.  
              수신한 패킷의 순서 번호가 중복된다면: 수신자는 패킷의 중복 복사(수신)을 검사함.  
  
**확인응답(ACK)**: 패킷/집합이 정확히 수신됐다는 응답을 송신자에게 하기위해 수신자가 사용하는 것.  
                   ACK는 일반적으로 패킷의 순서번호/확인응답된 패킷을 전달함.  
                   ACK를 프로토콜에 의존하기 때문에, ACK는 개별적이거나 누적될 수 있음.  
  
**부정 확인응답(NCK)**: 패킷이 정확히 수신되지 않았다는 응답을 송신자에게 하기 위해 수신자가 사용하는 것.  
                        NCK는 일반적으로 정확히 수신되지 않은 패킷의 순서번호를 전달함.  
  
**윈도우, 파이프라이닝**: 송신자는 주어진 범위에 있는 순서번호를 가진 패킷만 전송하도록 제한될 수 있음.  
                          ACK가 송신자에게 도달하지 않았어도, 다중 패킷을 허용하여 전송한다면 송신자의 이용률은 전송-후-대기 모드의 동작보다 증가될 수 있음.  
                          여기서 윈도우의 크기는 수신자의 메시지 수신·버퍼링 능력/네트워크의 혼잡 정도/둘 모두에 근거하여 설정됨.   



### 출처
컴퓨터 네트워킹: 하향식 접근 제 7판, 퍼스트북

---
## 로드 밸런싱   *@흐느*




---
## Blocking/Non-blocking & Synchronous/Asynchronous   *@Bora*



---
