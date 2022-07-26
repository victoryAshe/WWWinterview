# REST(Representational State Transfer) API
REST API란 **HTTP 프로토콜 설계**를 제대로 활용할 수 있도록 제시하는 API 아키텍쳐를 말한다.
### 구성
- 자원(RESOURCE) - URI
- 행위(Verb) - HTTP METHOD
- 표현(Representations)
### 특징
1. Uniform 유니폼 인터페이스
2. Stateless 무상태성
3. Cacheable 캐시 가능
4. Self-descriptiveness 자체 표현 구조
5. client-server 구조
6. 계층형 구조
-  다중 계층으로 구성될 수 있으며 보안, 로드 밸런싱, 암호화 계층을 추가해 구조상의 유연성을 둘 수 있고 PROXY, 게이트웨이 같은 네트워크 기반의 중간매체를 사용할 수 있게 한다.
### 디자인 가이드
- URI는 자원 정보를 나타내야 한다
- 자원에 대한 행위는 HTTP Method(GET, POST, PUT, PATCH, DELETE)로 표현한다

참고)
- https://meetup.toast.com/posts/92

---
# session/cookie
참고) 
- https://velog.io/@fortice/Spring-%EC%84%B8%EC%85%98-%EC%9D%B8%ED%84%B0%EC%85%89%ED%84%B0-%EC%BF%A0%ED%82%A4

---
# JWT(JSON Web Token)
JWT는 **전자 서명 된 URL-safe (URL로 이용할 수있는 문자 만 구성된)의 JSON**을 말한다.

![](./images/jwt.png)
- RFC 7519 명세를 따른다.
- 토큰 자체에 사용자의 권한 정보나 서비스를 사용하기 위한 정보가 포함(Self-contained)된다.
- RESTful 과 같은 무상태(Stateless)인 환경에서 사용자 데이터를 주고 받을 있다.
- JWT는 유저를 인증하고 식별하기 위한 토큰 기반 인증에 활용된다.

### 구조
#### header
- JWT 에서 사용할 타입과 해시 알고리즘의 종류를 담는다.
#### payload
- 서버에서 첨부한 사용자 권한 정보와 데이터가 담긴다.
#### signature
- Header, Payload 를 Base64 URL-safe Encode 를 한 이후 Header 에 명시된 해시함수를 적용하고, 개인키(Private Key)로 서명한 전자서명이 담긴다.
  - 전자서명은 Header, Payload 가 변조되었는지 확인하기 위해 사용되는 중요 정보이며 JWT 를 신뢰할 수 있는 토큰으로 사용할 수 있는 근거가 된다.
  - 전자서명에는 비대칭 암호화 알고리즘을 사용하므로 암호화를 위한 키와 복호화를 위한 키가 다르다. 
  - 암호화(전자서명)에는 개인키를, 복호화(검증)에는 공개키를 사용한다.

### 특징
- Payload가 많아지면, 그만큼 토큰의 길이가 길어지므로 통신의 오버헤드가 증가한다.
- RESTful 과 같은 무상태(Stateless) 환경에서의 통신이 용이하고 사용하기 쉽다.

참고)
- http://www.opennaru.com/opennaru-blog/jwt-json-web-token/
- https://pronist.dev/143
- https://inpa.tistory.com/entry/WEB-%F0%9F%93%9A-JWTjson-web-token-%EB%9E%80-%F0%9F%92%AF-%EC%A0%95%EB%A6%AC

---
# OAuth2.0

