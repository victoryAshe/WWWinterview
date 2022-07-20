# Design Pattern

### 디자인 패턴이란 무엇인가?
디자인 패턴은 쉽게 말해서, 좋은 코드를 헤메이지 않고 잘 작성하도록 도와주는 가이드와 같다.

디자인 패턴은 객체지향의 기본 특성과 객체 지향의 원칙에 입각해서 우리에게 어떻게 객체지향 시스템을 잘 설계할 것인지 알려주는 설계 디자이너이자 컨설턴트인 것이다.
이러한 패턴은 경험을 통해 검증된 산물이므로, 우리는 이러한 선배 개발자들의 노고가 담긴 패턴을 활용해 좌충우돌하는 시간을 줄일 수 있을 것이다.

## 객체지향 특성

### 추상화

### 캡슐화

### 다형성

## 객체지향 원칙

### SRP 단일 책임 원칙
하나의 클래스는 하나의 책임을 가져야 한다는 원칙이다.

### OCP(Open-Closed Principle) 개방 폐쇄 원칙
> 확장에는 열려있고 수정(변화)에는 닫혀있다.

쉽게 풀어 말하자면, 클래스 간의 결합도를 최대한 줄여서
확장이 필요한 경우에 해당 기능을 담당하는 클래스들만 수정하고,
그 외 클래스들에는 부작용을 일으키는 영향을 만들지 않도록 설계하는 것이다.

### DIP 의존 역전 원칙

>구현체가 아닌 추상체에 의존한다는 원칙이다.  

어떤 객체가 특정 기능을 수행하기 위해서 다른 객체에 의존하게 될 때, 이 객체를 추상화 된 클래스에 의존하게 함으로써 해당 기능을 수행하기 위한 최소한의 정보에만 노출되도록 한다.

이를 통해서 실제 기능의 구현은 추상화, 캡슐화 되어서 클라이언트 객체 (특정 객체를 활용하는 객체를 클라이언트 객체라고 부른다.) 에게는 드러나지 않도록 할 수 있다.

의존 역전 원칙에서 의존성이 역전되는 시점은 컴파일 시점으로, 어떤 구현체를 클라이언트가 활용할지 정해지는 때라고 볼 수 있다.

### ISP(Interface Segregation Principle) 인터페이스 분리 원칙 

목적과 관심이 다른 클라이언트가 있다면 이를 적절히 분리해서 클라이언트의 목적과 용도에 적합한 인터페이스만을 제공한다.

### 리스코프 원칙

참고 자료)
1. 헤드퍼스트 디자인패턴
2. https://mangkyu.tistory.com/194 [MangKyu's Diary:티스토리]


# Strategy Pattern 전략 패턴

특정 행동을 담당하는 인터페이스를 생성하여 관리할 수
있다.

Duck 클래스에서는 행동 인터페이스 타입의 매개변수를 두고,
각 하위클래스가 초기화될 때, 추상화된 인터페이스를 구현한 클래스를
할당하여 행동을 위임한다.

setter 메소드를 이용하여, 이러한 구현체를 동적으로 지정할거나
수정할 수도 있다.

개방 폐쇄 원칙(Open-Closed Principle)에 따라 변경이 발생하는 부분을
나머지 코드에 영향을 주지 않도록 분리하여 추상화, 캡슐화한다.

또한 의존 역전 원칙(Dependency Inversion Principle)에 따라, 구현이 아닌
추상에 의존하도록 설계한다. 즉, 클래스 간의 의존, 결합도를 낮춘다.
이러한 디자인을 strategy pattern 이라고 부른다.

행위(behavioral) 알고리즘을 캡슐화하여 동적으로 구현체를 교환하여 사용
할 수 있도록 하며, 이를 사용하는 클라이언트와는 독립적으로 구현되므로,
결합도를 낮춘다.

- 관련 코드 구현 : https://github.com/HanaHww2/head-first-design-pattern/tree/main/src/me/study/ch1 (출처: 헤드 퍼스트 디자인 패턴)

#### 과거 작성한 코드에서 스트래티지 패턴을 적용해서 수정할 부분...

# Template/Callback Pattern
- 스프링에서 자주 활용되는 **전략 패턴**의 변형 패턴이라고 할 수 있다.
- 이 패턴에서 콜백은 주로 **`단일 메소드 인터페이스`** 를 사용하며, 이를 구현할 때, **`익명 내부 클래스`** 로 만든다.
  - 콜백이 내부 클래스로 선언되므로, 자신을 생성한 클라이언트 메소드 내의 정보를 직접 참조할 수 있다.
  - 클라이언트와 콜백이 강하게 결합된다. 
- 메소드 단위로 사용할 오브젝트를 전달받는 마이크로 DI를 이용한다.

### 클라이언트
- 템플릿 안에서 실행될 로직을 담은 콜백 오브젝트 생성한다.
- 콜백이 참조할 정보를 제공한다.
- 템플릿 메소드를 호출하며 콜백을 파라미터로 전달한다. (메소드 레벨의 마이크로 DI)
### 템플릿
- 정해진 작업 흐름을 따라 내부에서 생성한 참조 정보를 가지고 콜백 오브젝트 메소드를 호출한다.
- 콜백으로부터 결과를 돌려받으면 작업을 마저 수행한다.
### 콜백 
- 클라이언트 메소드에 있는 정보와 템플릿이 제공한 참조 정보를 이용해 작업을 수행하고 그 결과를 템플릿에 반환한다. 

## Callback 콜백이란?
- 실행되는 것을 목적으로 다른 오브젝트 메소드에 전돨되는 오브젝트를 말한다.
- 파라미터로 전달되나, 특정 로직을 담은 메소드를 실행시키기 위해서 사용한다.
- 자바에서는 매개변수로 메소드 자체를 전달할 방법이 없으므로, 메소드가 담긴 오브젝트를 전달해야 하며, 이를 펑셔널 오브젝트(functional object)라고 한다.
# 템플릿 메소드 패턴 (template method pattern)

스프링에서 애용되는 디자인 패턴이다.

**제어의 역전**이라는 개념을 활용해 문제를 해결하는 디자인 패턴이라고 볼 수 있다. 제어권을  상위 템플릿 메소드에 넘기고, 자신(하위 구현 클래스)은 필요할 때 호출되어 사용되는 방식 때문이다.

상속을 통해 슈퍼 클래스의 기능을 확장할 때 사용하는 가장 대표적인 방법이다. 변하지 않는 기능은 슈퍼 클래스에 만들어 두고 자주 변경되며 확장할 기능은 서브 클래스에서 만들도록 한다.

- 추상 메소드 또는 오버라이드 가능한 메소드를 정의해두고, 이러한 메소드를 활용해 코드의 기본 알고리즘 골격을 담고 있는 템플릿 메소드를 만든다.
- 서브 클래스에서는 추상 메소드를 구현하거나 훅 메소드를 오버라이드하는 방법을 이용해 기능의 일부를 확장한다.
    - 슈퍼 클래스에서 디폴트 기능을 정의해두거나 비워뒀다가, 서브 클래스에서 선택적으로 오버라이드할 수 있도록 만들어 둔 메소드를 훅(hook) 메소드라고 한다.

```java
// 슈퍼 클래스
public abstract class AbstractUserDao {
	public  void add(User user) throws ClassNotFoundException, SQLException {
		Connectionc = getConnection(); // 추상 메소드를 활용한 템플릿 메소드
		PreparedStatement ps = c.prepareStatement(
        // 생략
        ps.close();
        c.close();
    }
	public User get(String id) throws ClassNotFoundException, SQLException {
		Connectionc = getConnection();
		PreparedStatement ps = c.prepareStatement(
	         
        // 생략
        rs.close();
        ps.close();
        c.close();
		return user;
    }

	// 추상메소드
	public abstractConnectiongetConnection()throwsClassNotFoundException, SQLException;
}

// 구현 서브 클래스
public class SubUserDao extends UserDao {
		// 서브 클래스에서 추상 메소드를 구현해 기능을 확장한다. 템플릿 메소드 패턴 활용
    @Override
    public Connection getConnection() throws ClassNotFoundException, SQLException {
        Class.forName("com.mysql.cj.jdbc.Driver"); // ClassNotFoundException
        Connection c = DriverManager.getConnection( // SQLException
                "jdbc:mysql://localhost/toby", "id", "pw");
        return c;
    }
}
// 서브 클래스는 Connection interface를 구현한 오브젝트를 생성한다. 팩토리 메소드 패턴 활용.
```
---