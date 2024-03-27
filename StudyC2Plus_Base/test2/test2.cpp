#include <stdio.h>

// 개속 반복, 0 입력시 종료
//소득세를 계산하시겠습니까 ? 0)No 1)Yes
//연간 총 소득을 입력하세요(만 단위) : 3000
//("당신의 소득세는 %d 입니다.", per) 출력
//
////per 구간 공식
//100000 < value : per = 45
//100000 >= value 이고 value > 50000 : per = 42
//50000 >= value 이고 value > 30000 : per = 40
//30000 >= value 이고 value > 15000 : per = 38
//15000 >= value 이고 value > 8800 : per = 35
//8800 >= value 이고 value > 4600 : per = 24
//4600 >= value 이고 value > 1200 : per = 15
//1200 >= value 이면 : per = 6

//함수 이름 : standardWeight
//맴버 변수 : float height
//리턴 값 : float
//공식 : (height - 100) * 0.9
float standardWeight(float height)
{
	return (height - 100) * 0.9;
}

//함수 이름 : GetBMI
//맴버 변수 : float weight, float standardWeight
//리턴 값 : float
//공식 : (weight - standardWeight)  * 100 / standardWeight
float GetBMI(float weight, float standardWeight)
{
	return (weight - standardWeight) * 100 / standardWeight;
}

// 개속 반복, 0 입력시 종료
//BMI를 계산하시겠습니까 ? 0)No 1)Yes
//몸무게를 입력해주세요 : weight에 값 입력
//키를 입력해주세요 : height에 값 입력
//bmi에 따른 등급 판정
//등급		비만도 수치
//10이하		정상
//10초과 20이하	과체중
//20 초과		비만

int main()
{
	bool bRun = true;

	while (bRun)
	{
		printf("BMI를 계산하시겠습니까 ? 0)No 1)Yes : ");
		int input = 0;
		scanf_s("%d", &input);

		switch (input)
		{
		case 0:
			bRun = false;
			break;

		case 1:
		{
			int weight = 0, height = 0, BMI = 0;
			printf("몸무게를 입력해주세요 : ");
			scanf_s("%d", &weight);
			printf("키를 입력해주세요 : ");
			scanf_s("%d", &height);
			BMI = GetBMI(weight, standardWeight(height));

			if (10 <= BMI){
				printf("정상\n");
			}
			else if (10 < BMI && BMI <= 20){
				printf("과체중\n");
			}
			else if (20 > BMI){
				printf("비만\n");
			}
		}
			break;

		default:
			break;
		}
	}
}