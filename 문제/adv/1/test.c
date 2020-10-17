#include <stdio.h>
#include <time.h>

int main() {

	

	int num = 0;
	scanf("%d", &num);
	int jaritsu = 0;
	scanf("%d", &jaritsu);

	clock_t start;
	start = clock();

	int goal = 0;
	int temp = 1;
	// case 0
	// ***0 5 * 4 * 3
	for (int i = num - 1; i >= num - 3; i--) {
		if (i == 0)break;
		temp *= i;
	}
	goal += temp;
	temp = 1;
	
	
	// case 2, 4, 6....
	// # => 0은 안됨
	// #**2 4 * 4 * 3

	for (int l = 0; l < (num / 2) + (num%2) - 1; l++) {
		temp *= 4;
		for (int j = num - 2; j >= num - 3; j--) {
			if (j == 0)break;
			temp *= j;
		}
		goal += temp;
		temp = 1;
	}

	printf("%d\n", goal);
	
	
	
	printf("실행시간 : %f\n", (double)(clock() - start) / CLOCKS_PER_SEC);
	
	getch();
	return 0;
}