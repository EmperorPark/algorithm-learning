#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int swap(int i, int j);
int Permutation(int TotalN, int N);
int data[10];
int permu[3628800][10];

int cnt = 0;


int main() {

	int T = 0;
	int N = 0;
	int compare = 0;
	int max = 0;
	int val[10][10];
	int i, j;
	int pacto = 1;

	scanf("%d", &T);
	clock_t start = clock();

	for (int idx = 0; idx < T; idx++) {
		scanf("%d", &N);
		
		memset(data, 0, sizeof(data));
		memset(val, 0, sizeof(val));
		memset(permu, 0, sizeof(permu));
		pacto = 1;

		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				scanf("%d", &val[i][j]);
				
			}
			
		}

		for (j = 0; j < N; j++) {
			data[j] = j + 1;
		}
		cnt = 0;
		Permutation(N, N, 0);
		
		
		for (i = N; i > 0; i--) {
			pacto *= i;
		}

		for (int k = 0; k < pacto; k++) {
			for (int l = 0; l < N; l++) {
				//printf("%d %d ", permu[k][l], val[l][permu[k][l]-1]);
				compare += val[l][permu[k][l]-1];
			}
			if (max < compare) {
				max = compare;
			}
			//printf("\n");
			//printf("%d\n", compare);
			compare = 0;
		}
		printf("#%d %d\n", idx + 1, max);
	}

	

	printf("실행시간: %f\n", (double)(clock() - start) / CLOCKS_PER_SEC);
	getch();

	return 0;
}

int swap(int i, int j)
{
	int temp;
	
	//같은자리면 바꾸지 않는다
	if (i == j) return 0;
	temp = data[i];
	data[i] = data[j];
	data[j] = temp;
	return 0;
}

int Permutation(int TotalN, int N)
{
	int i;

	//가장큰값부터 시작해서 재귀하면서 값을 떨어뜨리고 1이되었을때 수의 개수 만큼 반복하면서 data배열에 있는 값을 출력
	if (N == 1) {
		for (i = 0; i<TotalN; i++) {
			permu[cnt][i] = data[i];
			
		}
		cnt++;
		return 0;
	}

	for (i = 0; i<N; i++) {
		swap(i, N - 1);//스왑
		Permutation(TotalN, N - 1);//재귀
		swap(i, N - 1);//복원
	}
}