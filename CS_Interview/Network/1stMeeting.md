# 1stMeeting
* [TCP와 UDP의 차이](https://github.com/victoryAshe/WWWinterview/blob/main/CS_Interview/Network/1stMeeting.md#tcp%EC%99%80-udp%EC%9D%98-%EC%B0%A8%EC%9D%B4)
* [TCP에서 흐름제어와 혼잡제어의 차이](https://github.com/victoryAshe/WWWinterview/blob/main/CS_Interview/Network/1stMeeting.md#tcp%EC%97%90%EC%84%9C-%ED%9D%90%EB%A6%84%EC%A0%9C%EC%96%B4%EC%99%80-%ED%98%BC%EC%9E%A1%EC%A0%9C%EC%96%B4%EC%9D%98-%EC%B0%A8%EC%9D%B4)
* [TCP에서 3-way-handshaking의 방식](https://github.com/victoryAshe/WWWinterview/blob/main/CS_Interview/Network/1stMeeting.md#tcp%EC%97%90%EC%84%9C-3-way-handshake%EC%9D%98-%EB%B0%A9%EC%8B%9D)
* [HTTP와 HTTPS의 차이와 그 구체적인 방식](https://github.com/victoryAshe/WWWinterview/blob/main/CS_Interview/Network/1stMeeting.md#http%EC%99%80-https%EC%9D%98-%EC%B0%A8%EC%9D%B4%EC%99%80-%EA%B7%B8-%EA%B5%AC%EC%B2%B4%EC%A0%81%EC%9D%B8-%EB%B0%A9%EC%8B%9D)
---
## TCP와 UDP의 차이   *@ 또로리*

### 답변 내용

전체적으로 설명하긴 했으나 기억을 더듬으며 답변하느라 연결되지 않게 말함

### 보완 내용

**- 정의**  
TCP : 가상회선 생성을 통해 신뢰성 있는 연결형 서비스를 제공해주는 프로토콜  
UDP : 데이터그램 단위로 전송하여 비연결형 서비스를 제공해주는 프로토콜

**- 데이터 경계 구분 여부**  
TCP : X - 바이트스트림 위주의 프로토콜로서 패킷에 전송번호,양 끝단에 연결 상태 부여를 통해 순차,연쇄적으로 조각난 데이터 전송 가능  
UDP : O - IP 패킷에 데이터그램 메시지 전체가 다 들어감

**- 데이터에 대한 신뢰성 보장**  
TCP : O - 흐름/혼잡/오류제어를 이용  
UDP : X

**- 영향**  
TCP : 속도 느림  
UDP : 속도 빠름 => 적은 오버헤드, 데이터그램의 도착 순서 변경/중복/알림없는 누락 가능성

**- 우선순위**  
TCP : 신뢰성  
UDP : 속도

**- 용도**  
TCP : 파일 전송  
UDP : 스트리밍과 같이 RTP가 필요한 실시간 커뮤니케이션 서비스

---
## TCP에서 흐름제어와 혼잡제어의 차이   *@ 흐느*

### Flow Control 흐름 제어

- stop & wait와 sliding window 방식을 사용한다.
  - Stop and wait : 매번 전송한 패킷에 대해 확인응답을 받아야만 그 다음 패킷을 전송하는 방법
  - Sliding Window : 수신 측에서 알려주는 윈도우 크기만큼 송신측에서 세그먼트를 전송할 수 있게 하여 데이터 흐름을 동적으로 조절하는 제어 기법
- TCP 통신에서 수신자는 송신자에게 항상 수신 가능한 버퍼의 크기를 알려준다.
  - 송신자는 이 크기를 넘어서는 데이터를 전송하지 않음으로써, 버퍼를 초과하는 데이터를 (너무 많이 혹은 너무 빠르게) 보내 데이터 유실을 발생시키지 않도록 한다.
  - 세그먼트Segment의 헤더에 RcvWindow(가용 가능한 버퍼 크기) 값을 작성한다.
  - 최초 3 way handshake 시, SYNACK 응답에도 RcvWindow 값을 작성한다.

### Congestion Control 혼잡 제어

> 송신측의 데이터는 지역망이나 인터넷으로 연결된 대형 네트워크를 통해 전달됩니다. 만약 한 라우터에 데이터가 몰릴 경우, 자신에게 온 데이터를 모두 처리 할 수 없게 됩니다. 이런 경우 호스트들은 또 다시 재전송을 하게되고 결국 혼잡만 가중시켜 오버플로우나 데이터 손실을 발생시키게 됩니다. 따라서 이러한 네트워크의 혼잡을 피하기 위해 송신측에서 보내는 데이터의 전송속도를 강제로 줄이게 되는데, 이러한 작업을 혼잡제어라 합니다.  
> 또한 네트워크 내에 패킷의 수가 과도하게 증가하는 현상을 혼잡(Congesetion)이라 하며 혼잡현상을 방지하거나 제거하는 기능을 혼잡제어라 합니다. 흐름제어가 송신측과 수신측 사이의 전송속도를 다루는데 반해 혼잡제어는 호스트와 라우터를 포함한 보다 넓은 관점에서의 전송 문제를 다루게됩니다.

네트워크 상의 혼잡 제어를 위해 2가지 접근방식을 고려해볼 수 있다.

- 양 끝 노드에서 제어하는 방식
  - 끝 노드에서 데이터 통신 중의 유실이나 지연 등을 바탕으로 유추하는 방식
  - 실제 현실에서 활용되는 방식이다.
- 네트워크에서 지원해 혼잡을 제어하는 방식
  - 라우터가 끝 노드 시스템에 피드백을 제공한다.
  - 이상적인 구현방식이나 현실적이지 못하다.

### 3가지 주요 알고리즘

**1. Slow Start**

- 최소 대역폭, 병목 현상에 대한 정보를 얻을 수 없으므로, 느리게 시작해서 지수적으로 크기(transmission rate, window size)를 늘려나간다.

**2. Additive increase 선형적 증가**

- 일정 이상 증가한 이후에는 선형적으로 크기를 증가시킨다.

**3. Mulitplicative decrease 배수적 감소**

- packet drop/loss 가 발생하면, 절반 크기로 전송 크기를 감소시킨다.
  - CongWin 이 threshold 이하이면, 최초 시작 속도에서 다시 시작한다.
  - CongWin 이 threshold 이상이면, 절반 크기 속도에서 다시 시작한다.

**4. Fast Retransmission 빠른 재전송**
패킷을 받는 쪽에서 먼저 도착해야 할 패킷이 도착하지 않고 다음 패킷이 도착한 경우에도 ACK 패킷을 보내게 됩니다. 순번이 중복된 ACK 패킷을 받게 되고, 이것을 감지하는 순간 문제가 되는 순번의 패킷을 재전송해 줄 수 있습니다. 빠른 재전송은 중복된 순번의 패킷을 3개 받으면 재전송을 하게 됩니다. 이런 현상이 일어나는 것은 약간 혼잡한 상황이 일어난 것이므로 혼잡을 감지하고 Window size를 줄이게 됩니다.

출처: https://jwprogramming.tistory.com/36 [개발자를 꿈꾸는 프로그래머]

### 송신자가 혼잡을 인지하는 방법

- 데이터 유실, 시간 초과 또은 3회 반복되는 ack 신호

### 속도 Rate (단순화 한 계산)

Rate = CongWin / RTT (byte/sec)

- RTT(Round Trip Time)

### 출처

1. 네트워크 강의, kocw 이석복 교수님
2. https://jwprogramming.tistory.com/36 [개발자를 꿈꾸는 프로그래머]
---
## TCP에서 3-way-handshaking의 방식   *@ Ashe*  

TCP는 3-way handshaking 과정을 통해 연결을 설정하고, 4-way handshaking을 통해 해제한다.
### **용어 설명**
* Client: 연결 요청을 먼저 시도한 요청자
* Server: 연결 요청을 받은 수신자

### **3-way handshaking**
* **개념**
  * TCP 통신을 이용하여 데이터를 전송하기 위해 **네트워크 연결을 설정(Connection Establish)**하는 과정  
  * 양쪽 모두 데이터를 전송할 준비가 되었다는 것을 보장하고, 실제로 데이터 전달을 시작하기 전에 상대쪽이 준비되었다는 것을 알 수 있도록 한다.  
   -> TCP/IP 프로토콜을 이용해 통신하는 응용 프로그램이 데이터를 전송하기 전에, 먼저 정확한 전송을 보장하기 위해 상대방 컴퓨터와 사전에 세션을 수립하는 과정
* **기본 매커니즘**
  * **PAR**_ *Positive Acknowledgement with Re=transmission*: 을 통해 신뢰적 통신을 제공!  
    -> Par을 사용하는 기기는 ack를 받을 때까지 데이터 유닛을 재전송 
   ![images_averycode_post_cd53e336-a624-4f8a-b7e5-20fe62eb6648_image](https://user-images.githubusercontent.com/80302657/168985259-ac0f3aeb-30a5-4b5a-b4ae-f6e669205a46.png)

  * 수신자가 데이터 유닛(:세그먼트)이 손상된 것을 확인하면(Error Detection에 사용되는 transport layer의 checksum 활용), 해당 세그먼트를 없애고 sender는 positive ack이 오지 않은 세그먼트를 다시 보내야 함  
    -> 이 과정에서 클라이언트-서버 사이에 3개의 세그먼트가 교환되는 것을 확인할 수 있다: 3-way handshake
* **작동 방식**
  *  **SYN**_ *Synchronization*: 연결요청, 세션을 설정하는 데 사용되며 초기에 시퀀스 번호를 보냄
  *  **ACK**_ *Acknowledgement*: 보낸 시퀀스 번호에 TCP 계층에서의 길이 or 양을 더한 것과 같은 값을 ACL에 포함해 전송
    : 동기화 요청에 대한 답변: `Client의 Sequence Number+1`을 해 ACK로 돌려줌  
    
    ![image](https://user-images.githubusercontent.com/80302657/171321066-a7747c0c-3931-486d-89ab-39bd8b014d8a.png)

### 출처
1. [averycode.log](https://velog.io/@averycode/%EB%84%A4%ED%8A%B8%EC%9B%8C%ED%81%AC-TCPUDP%EC%99%80-3-Way-Handshake4-Way-Handshake)
2. 컴퓨터 네트워킹: 하향식 접근 제 7판, 퍼스트북
  
---
## HTTP와 HTTPS의 차이와 그 구체적인 방식   *@ 보라*

### 답변한 내용

HTTP 와 HTTPS 는 네트워크 통신 규약이다. HTTP 는 리소스를 주고받을 때 암호화되지 않은 평문으로 주고받기 때문에 도청의 가능성이 있다. HTTPS는 HTTP 에 리소스를 암호화하는 Secure Socket Layer 를 추가한 프로토콜이다.

### 보완 내용

🤨 **HTTP는 어떻게 통신하는지?**  
웹브라우저에 URL 주소를 입력하면 DNS 서버에 요청을 보내 해당하는 웹서버의 IP 주소를 얻어온다. 이 웹서버와 연결요청(SYN)-응답, 연결요청(ACK, SYN)-응답,연결성립(ACK)의 3단계 과정을 거치는 3-way handshake 과정을 거쳐 TCP 연결을 하고, 연결 후 클라이언트는 서버에게 리소스를 요청하고 서버는 클라이언트에게 리소스를 응답한다. 응답 후 서버는 통신끝남알림(FIN)-확인, 남은 데이터 전송(ACK)-통신끝남알림(FIN)-확인, 연결종료(ACK) 의 4단계를 거치는 4-way handshake 과정을 거쳐 클라이언트와의 연결을 종료한다.

🤨 **HTTPS 는 어떻게 동작하는지?**  
HTTPS 는 대칭키로 데이터를 암호화하고 공개키로 이 대칭키를 한번 더 암호화하여 보안을 강화한 프로토콜이다. HTTP 통신 중 HTTP 메시지를 교환하기 전 암호화/복호화를 위해 `SSL Handshake` 과정을 거친다. 서버는 클라이언트가 요청 시 대칭키 생성을 위한 랜덤 데이터와 인증기관에서 발급한 대칭키 암호화를 위한 공개키가 담겨 있는 인증서를 전송하고, 클라이언트는 서버의 랜덤데이터와 자신의 랜덤데이터로 생성한 대칭키를 인증서의 공개키로 암호화해 서버에게 전송한다. 이후 리소스를 대칭키로 데이터를 암호화하여 통신하고, 통신이 끝나면 사용한 대칭키를 폐기한다. 이렇게 공개키와 대칭키 방식을 혼합해 쓰는 이유는, 공개키 암호화 방식은 컴퓨터 리소스를 많이 사용하기 때문에 전체 데이터에 대해 수행하기에는 부담스럽고, 대칭키는 수신측과 송신측이 동일한 키를 공유하기 때문에 보안의 문제가 발생하기 떄문이다.

🤨 **공개키, 대칭키 암호화 방식이 무엇인지?**  
대칭키는 암호화/복호화에 사용하는 키가 같은 암호화 알고리즘이다. 암호화/복호화 연산이 복잡하지 않아 연산속도가 빠르고 구현이 용이해 대량 데이터 암호화에 유리하나, 암호화/복호화 키가 동일하기 때문에 중간에 유출 가능성이 있고 다수와 통신 시 키의 개수가 급증해 키를 전달하고 관리하기 어렵다. 공개키는 암호화/복호화에 사용하는 키가 다른 암호화 알고리즘이다. 공개해도 무관한 공개키로 암호화하고 타인에게 노출되지 않도록 각자 보관하는 개인키로 복호화한다. 공개키가 유출되어도 복호화를 할 수 없어 유출 가능성이 낮지만, 암호화/복호화 연산이 복잡한 수학 연산을 기반으로 하기 때문에 대칭키 알고리즘에 비해 연산속도가 느려 대량 데이터 암호화에 사용될 경우 매우 느려진다.
