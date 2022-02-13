#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // rand() 포함 라이브러리
#include <time.h> // time() 포함 라이브러리

int avoid_dup(int* a_p1, int* a_p2, int* a_p3);
int main() {
	srand(time(NULL)); // rand() 값을 시간에 따라 변하게 설정
	int ans, a_p1, a_p2, a_p3;
	a_p1 = rand() % 10; // ans p-first
	a_p2 = rand() % 10; // ans p-second
	a_p3 = rand() % 10; // ans p-third
	
	int pa_p1 = &a_p1;
	int pa_p2 = &a_p2;
	int pa_p3 = &a_p3;
	avoid_dup(pa_p1, pa_p2, pa_p3); // 중복 피하기
	ans = a_p1 * 100 + a_p2 * 10 + a_p3; // 정답

	printf("<야구 게임>\n10회 안에 중복되지 않은 세 자릿수의 숫자를 맞추세요\n");

	for (int i = 0; i < 10; i++) {
		printf("%d번째 시도:", i + 1);

		int put;
		scanf("%d", &put); // 입력값
		int ball = 0;
		int strike = 0;
		int out = 0;

		int p_p1, p_p2, p_p3;
		p_p1 = put / 100; // put p-first
		p_p2 = (put % 100) / 10; // put p-second
		p_p3 = put % 10; // put p-third

		// p_p1 check
		if (p_p1 == a_p1) {
			strike++;
		}
		else if (p_p1 == a_p2 || p_p1 == a_p3) {
			ball++;
		}
		else
			out++;
		// p_p2 check
		if (p_p2 == a_p2) {
			strike++;
		}
		else if (p_p2 == a_p1 || p_p2 == a_p3) {
			ball++;
		}
		else
			out++;
		// p_p3 check
		if (p_p3 == a_p3) {
			strike++;
		}
		else if (p_p3 == a_p1 || p_p3 == a_p2) {
			ball++;
		}
		else
			out++;
		
		printf("입력값:%d%d%d, S:%d, B:%d, O:%d\n", p_p1, p_p2, p_p3, strike, ball, out);

		if (put == ans) {
			printf("정답입니다!\n정답:%d%d%d", a_p1, a_p2, a_p3);
			break;
		}
		else if (i == 10) {
			printf("도전 실패...\n정답:%d%d%d", a_p1, a_p2, a_p3);
			break;
		}
	}
	
	return 0;
}

int avoid_dup(int *a_p1, int *a_p2, int *a_p3) {
	if (*a_p2 == *a_p1) {
		*a_p2 -= 1;
		if (*a_p2 < 0) {
			*a_p2 += 10;
		}
	}
	else if (*a_p3 == *a_p1 || *a_p3 == *a_p2) {
		*a_p3 -= 1;
		if (*a_p3 < 0) {
			*a_p3 += 10;
		}
		if (*a_p3 == *a_p1 || *a_p3 == *a_p2) {
			*a_p3 -= 1;
		}
	}
	return 0;
}
