#include <stdio.h>

int main(void) {

	/* 대입연산자 
	연산자 기준 오른쪽의 값을 왼쪽 변수(메모리)에 대입*/
	int intResult = 0;
	double doubleResult = 0.0;

	/* 산술연산자+
	+, -, *, /, % */
	intResult = 3 + 4;
	doubleResult = 3.0 + 4.0;
	printf("%d, %lf\n", intResult, doubleResult);
	
	intResult = 2 - 1;
	doubleResult = 4.0 - 3.0;

	intResult = 3 * 4;
	doubleResult = 3.0 * 4.0;

	/* 나누기 연산자 주의사항은 0으로 나누지 않도록 주의하자*/
	intResult = 3 / 4;
	doubleResult = 3.0 / 4.0;
	printf("%d\n%lf\n", intResult, doubleResult);

	/* 나머지 연산은 정수에서만 사용할 수 있다.
	나머지가 나누어떨어지면 0을 반환하지만 아니라면 나머지값을 반환하는 연산자
	무엇의 배수인지 짝수인지 홀수인지 확인하는데 사용할 수 있다.*/
	intResult = 3 % 4;
	doubleResult = 3 % 4;

	/* 부호연산자*/
	intResult = +3;
	intResult = -3;

	intResult = 0;
	/* 복합 대입연산자
	Result = Result + 값 처럼 한 변수에 값을 연산하고 다시 변수에 대입하고싶을 때 변수명을 두번써야하는 불편함이 있다
	이것을 해결하는 것이 복합 대입연산자*/
	intResult += 1;
	intResult += 1;
	printf("%d\n", intResult);


	/* ++, -- 증감연산자*/
	intResult++;
	printf("%d\n", intResult++);
	printf("%d\n", ++intResult);

	/* 관계연산자 
	>,<,>=,<= 등호는 반드시 오른쪽에 붙어야한다.*/
	

	/* 비트연산자
	비트 &연산자 비트와 비트를 and연산을 한다.
	0000
	0101
	0000 이다.*/
	// & and 비트 이항연산자
	printf("%d & %d = %d\n", 5, 10, 5 & 10);

	// | or 비트 이항연산자
	printf("%d | %d = %d\n", 5, 10, 5 | 10);

	// ^ xor 비트 이항연산자
	printf("%d ^ %d = %d\n", 15, 10, 15 ^ 10);

	// 쉬프트연산자 (상위 워드는 배경색이고, 하위워드는 글자색일때 사용)
	// 아니면 비트하나마다 속성값을 주게되는것도 쉬프트 연산으로 빠르게 연산 가능.
	/* >>(우측이동), <<(좌측이동) */
	printf("%d >>%d %d\n", 2, 2, 2 << 2);


	// 삼항연산자 ? :
	int program = 0;
	printf("안녕하세요 %s입니다.\n", program ? "C" : "C++");

	// , (콤마연산자)
	int commaResult = 0;
	int a = 0, b = 0;
	commaResult = a = 3, b++;/* 프리포멧 지원용 연산자인거 같은데*/

	printf("commaResult = %d, a = %d, b = %d\n", commaResult, a, b);
	
	// sizeof() 데이터형이 메모리에서 차지하는 공간을 구해서 리턴해줌 (단위: 바이트)
	int size_int = sizeof(int);
	int size_size_int = sizeof(int);
	int size_intConstant = sizeof(3);
	printf("%d, %d, %d\n", size_int, size_size_int,
						size_intConstant);
	
	// 연산자 우선순위
	/*
	1. 최우선 연산자
	2. 단항 연산자
	3. 산술
	5. 쉬프트
	4. 관계
	5. 논리
	6. 연산자
	7. 대입연산자
	혹시라도 우선순위가 불확실하다면, 우선계산해야할 수식에 괄호치는 습관이 더 유용하기도 하다.*/

	// 캐스팅 연산자

	/* 암시적 형변환
	* 
	* 코드에 따로 지정하지 않아도 컴파일러가 자동으로 변환하는 것*/
	/*short + char 처럼 int형으로 치환되어서 연산되는 데이터들은 연산시 자동으로 레지스터 크기인 int로 변환된다.
	이것을 승격이라고 한다.*/

	int num_int = 10;
	double num_double = 12.34;
	printf("%d\n", num_int + num_double); // 8바이트 만큼의 데이터를 읽어야 하는데, 4바이트만 정수형으로 읽히면서 값 오류
	printf("%lf\n", num_int + num_double);
	float num_float = 1.2;
	double num_double2 = 12.34;
	num_float = num_double2;
	printf("%f\n", num_float);

	/*
	명시적 형변환
	코드에 직접적으로 형변환을 하겠다고 선언하여 서로 호환이 불가능하던 데이터형에 데이터를 대입하기도 할 수있다.
	컴파일러는 그것을 오류로 제공하지 않아서 오류가 날 가능성이 높아서 주의 해야한다.*/
	int n;
	float f;
	f = 5 / 3;
	printf("%f\n", f);
	f = (float)5 / 3;
	printf("%f\n", f);
	
	/* 해볼만한 주제
	1. 다양한 데이터형 끼리 연산하기
	2. 데이터들 sizeof()로 바이트크기 구해보기
	3. 1+2: 다양한 자료형끼리 연산한것을 sizeof()연산하기
	4. 비트연산결과를 출력하기전에 직접한번 계산해보기*/

	return 0; 
}