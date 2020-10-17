#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int map[50][50];
int cross[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
int M = 0;//���� -> 2�����迭�� 1�����迭����
int N = 0;//���� 2�����迭 ����

void dfs(int x, int y);

int main() {

	int T = 0;
	scanf("%d", &T);

	clock_t start = clock();

	int K = 0;

	int i, j;

	int temp1;
	int temp2;

	int cnt;


	for (int idx = 0; idx < T; idx++) {
		for (i = 0; i < 50; i++) {
			for (j = 0; j < 50; j++) {
				map[i][j] = 0;
			}
		}
		M = 0;
		N = 0;
		K = 0;
		cnt = 0;

		scanf("%d %d %d", &M, &N, &K);

		for (i = 0; i < K; i++) {
			//temp1 ������ġ -> 1��������
			//temp2 ������ġ -> 2��������
			scanf("%d %d", &temp1, &temp2);

			map[temp2][temp1] = 1;
		}


		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				if (map[i][j] == 1) {
					cnt++;
					dfs(i, j);
				}
			}
		}

		printf("#%d %d\n", idx+1, cnt);
		//printf("%d\n", cnt);

	}

	printf("����ð� : %f\n", (double)(clock() - start) / CLOCKS_PER_SEC);

	getch();
	return 0;
}

//2���� �迭 �������� �˻� dfs
void dfs(int x, int y) {
	map[x][y] = 0;


	for (int i = 0; i < 4; i++) {
		int tempX = x + cross[i][0];
		int tempY = y + cross[i][1];

		if (tempX < 0 || tempY < 0 || tempX >= 50 || tempY >= 50) {
			continue;
		}

		if (map[tempX][tempY] == 0) {
			continue;
		}

		dfs(tempX, tempY);

	}

}