#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertionSort(int * arr, int n);
int main() {

	int N = 0;
	int *arr;

	scanf("%d", &N);

	clock_t start = clock();

	arr = (int*)malloc(N * sizeof(int));
	memset(arr, 0, N * sizeof(int));

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < N; i++) {
		insertionSort(arr, i);
	}

	for (int i = 0; i < N; i++) {
		//printf("%d\n", arr[i]);
		printf("%d ", arr[i]);
	}

	printf("\n");
	printf("실행시간 : %f\n", (double)(clock() - start)/CLOCKS_PER_SEC);
	getch();
	return 0;
}


void insertionSort(int * arr, int n) {
	
	int temp = 0;

	if (n == 0) {
		if (arr[0] > arr[1]) {
			temp = arr[1];
			arr[1] = arr[0];
			arr[0] = temp;
		}
		return;
	}
	
	for (int i = n; i > 0; i--) {
		if (arr[i] < arr[i - 1]) {
			temp = arr[i - 1];
			arr[i - 1] = arr[i];
			arr[i] = temp;
		}
		else {
			break;
		}
	}
}