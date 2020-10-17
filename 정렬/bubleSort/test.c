#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int bubleSort(int * arr, int n);
int main() {

int N = 0;
int *arr;
int flag = 0;

scanf("%d", &N);

clock_t start = clock();

arr = (int*)malloc(N * sizeof(int));
memset(arr, 0, sizeof(arr));

for (int i = 0; i < N; i++) {
scanf("%d", &arr[i]);
}

while (1) {
if (bubleSort(arr, N) != 1) break;
}


for (int i = 0; i < N; i++) {
	printf("%d ", arr[i]);
}
printf("\n");
printf("실행시간 : %f\n", (double)(clock() - start) / CLOCKS_PER_SEC);

getch();
return 0;
}

int bubleSort(int * arr, int n) {
	int flag = 0;
	int temp = 0;

	for (int i = 0; i < n - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			temp = arr[i + 1];
			arr[i + 1] = arr[i];
			arr[i] = temp;
			flag = 1;
		}
	}

	//재귀로 처리시 수가 너무 많으면 스택오버플로로 인해서 리턴값주고 main에서 if문으로 처리
	/*if (flag == 1) {
	bubleSort(arr, n);
	}*/

	return flag;

}


/*
#include<stdio.h>

int main() {
for (int i = 10000; i >= 1; i--) {
printf("%d\n", i);
}

return 0;
}
*/