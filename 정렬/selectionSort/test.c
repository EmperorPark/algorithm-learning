#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selectionSort(int * arr, int n);
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

	for (int i = N; i > 0; i--) {
		selectionSort(arr, i);
	}

	for (int i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("����ð� : %f\n", (double)(clock() - start)/CLOCKS_PER_SEC);

	getch();
	return 0;
}


void selectionSort(int * arr, int n) {
	int max = 0;
	int sel = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
			sel = i;
		}
	}
	arr[sel] = arr[n -1];
	arr[n - 1] = max;

	//��ͷ� ó���� ���� �ʹ� ������ ȣ�� ���ÿ����÷η� ���ؼ� main���� for������ ó��
	/*if (n > 1) {
		selectionSort(arr, n - 1);
	}*/

}