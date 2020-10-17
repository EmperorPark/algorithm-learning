#include<stdio.h>
#include<time.h>

char maze[11][11];
int N = 0, M = 0;
char goal[2] = { 0, };
char R[2] = { 0, };
char B[2] = { 0, };

int up();
int down();
int left();
int right();

void debug() {
	printf("goal %d %d\n", goal[0], goal[1]);
	printf("B %d %d\n", B[0], B[1]);
	printf("R %d %d\n", R[0], R[1]);
}

int main() {

	int i, j, k;
	int temp = 0;
	int count = 0;
	int min = 2048;
	int map[1024 * 2][10];
	int fstR[2];
	int fstB[2];

	scanf("%d %d", &N, &M);
	clock_t start = clock();
	scanf("%c", &temp);
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%c", &maze[i][j]);
			if (maze[i][j] == 'O') {
				goal[0] = i;
				goal[1] = j;
			}
			else if (maze[i][j] == 'R') {
				fstR[0] = R[0] = i;
				fstR[1] = R[1] = j;
			}
			else if (maze[i][j] == 'B') {
				fstB[0] = B[0] = i;
				fstB[1] = B[1] = j;
			}
		}
		scanf("%c", &temp);
	}


	//memset(map, 0, sizeof(map));

	for (i = 0; i < 1024; i++) {
		temp = i;
		for (j = 0; j < 10; j++) {
			map[i][j] = temp % 2;
			temp >>= 1;
			if (j % 2 == 0) {
				map[i][j] += 2;
			}
		}
	}
	for (i = 1024; i < 2048; i++) {
		temp = i;
		for (j = 0; j < 10; j++) {
			map[i][j] = temp % 2;
			temp >>= 1;
			if (j % 2 == 1) {
				map[i][j] += 2;
			}
		}
	}
	
	for (i = 0; i < 2048; i++) {
		temp = 0;
		count = 0;
		maze[R[0]][R[1]] = '.';
		maze[B[0]][B[1]] = '.';
		maze[fstR[0]][fstR[1]] = 'R';
		maze[fstB[0]][fstB[1]] = 'B';
		R[0] = fstR[0];
		R[1] = fstR[1];
		B[0] = fstB[0];
		B[1] = fstB[1];
		for (j = 0; j < 10; j++) {
			if (map[i][j] == 0) temp = up();
			else if (map[i][j] == 1) temp = down();
			else if (map[i][j] == 2) temp = left();
			else if (map[i][j] == 3) temp = right();

			//getch();
			count++;
			if (temp != 0)break;
		}
		if (temp == 1 && min > count)min = count;	
	}
	if (min >= 2048)min = -1;
	printf("%d\n", min);

	printf("실행시간 : %f\n", (double)(clock() - start) / CLOCKS_PER_SEC);
	getch();
	return 0;
}

int up() {
	
	int i;
	//B가 R보다 위에 있으면 B부터 움직인다.
	if (B[0] < R[0]) {
		for (i = 0; i < N - 3; i++) {
			if (maze[B[0] - 1][B[1]] == 'O')return -1;
			else if (maze[B[0] - 1][B[1]] == '.') {
				maze[B[0]][B[1]] = '.';
				B[0]--;
				maze[B[0]][B[1]] = 'B';
			}

			if (maze[R[0] - 1][R[1]] == 'O') {
				//for (int j = 0; j < N - (R[0] - 1); j++) {
				for (int j = 0; ; j++) {
					if (maze[R[0] - 1 + j][R[1]] == '#')break;
					if (maze[R[0] - 1 + j][R[1]] == 'B') {
						return -1;
					}
				}
				return 1;
			}
			else if (maze[R[0] - 1][R[1]] == '.') {
				maze[R[0]][R[1]] = '.';
				R[0]--;
				maze[R[0]][R[1]] = 'R';
			}

		}
	}
	else {
		for (i = 0; i < N - 3; i++) {
			if (maze[R[0] - 1][R[1]] == 'O') {
				//for (int j = 0; j < N - (R[0] - 1); j++) {
				for (int j = 0; ; j++) {
					if (maze[R[0] - 1 + j][R[1]] == '#')break;
					if (maze[R[0] - 1 + j][R[1]] == 'B') {
						return -1;
					}
				}
				return 1;
			}
			else if (maze[R[0] - 1][R[1]] == '.') {
				maze[R[0]][R[1]] = '.';
				R[0]--;
				maze[R[0]][R[1]] = 'R';
			}

			if (maze[B[0] - 1][B[1]] == 'O')return -1;
			else if (maze[B[0] - 1][B[1]] == '.') {
				maze[B[0]][B[1]] = '.';
				B[0]--;
				maze[B[0]][B[1]] = 'B';
			}

		}
	}
	
	return 0;
}

int down() {

	int i;
	//B가 R보다 아래에 있으면 B부터 움직인다.
	if (B[0] > R[0]) {
		for (i = 0; i < N - 3; i++) {
			if (maze[B[0] + 1][B[1]] == 'O')return -1;
			else if (maze[B[0] + 1][B[1]] == '.') {
				maze[B[0]][B[1]] = '.';
				B[0]++;
				maze[B[0]][B[1]] = 'B';
			}

			if (maze[R[0] + 1][R[1]] == 'O') {
				//for (int j = 0; j < N - (R[0] + 1); j++) {
				for (int j = 0; ; j++) {
					if (maze[R[0] + 1 - j][R[1]] == '#')break;
					if (maze[R[0] + 1 - j][R[1]] == 'B') {
						
						return -1;
					}
				}
				return 1;
			}
			else if (maze[R[0] + 1][R[1]] == '.') {
				maze[R[0]][R[1]] = '.';
				R[0]++;
				maze[R[0]][R[1]] = 'R';
			}

		}
	}
	else {
		for (i = 0; i < N - 3; i++) {
			if (maze[R[0] + 1][R[1]] == 'O') {
				//for (int j = 0; j < N - (R[0] + 1); j++) {
				for (int j = 0; ; j++) {
					if (maze[R[0] + 1 - j][R[1]] == '#')break;
					if (maze[R[0] + 1 - j][R[1]] == 'B') {
						return -1;
					}
				}
				return 1;
			}
			else if (maze[R[0] + 1][R[1]] == '.') {
				maze[R[0]][R[1]] = '.';
				R[0]++;
				maze[R[0]][R[1]] = 'R';
			}

			if (maze[B[0] + 1][B[1]] == 'O')return -1;
			else if (maze[B[0] + 1][B[1]] == '.') {
				maze[B[0]][B[1]] = '.';
				B[0]++;
				maze[B[0]][B[1]] = 'B';
			}

		}
	}

	return 0;
}

int left() {

	int i;
	//B가 R보다 왼쪽에 있으면 B부터 움직인다.
	if (B[1] < R[1]) {
		for (i = 0; i < M - 3; i++) {
			if (maze[B[0]][B[1] - 1] == 'O')return -1;
			else if (maze[B[0]][B[1] - 1] == '.') {
				maze[B[0]][B[1]] = '.';
				B[1]--;
				maze[B[0]][B[1]] = 'B';
			}

			if (maze[R[0]][R[1] - 1] == 'O') {
				//for (int j = 0; j < M - (R[1] - 1); j++) {
				for (int j = 0; ; j++) {
					if (maze[R[0]][R[1] - 1 + j] == '#')break;
					if (maze[R[0]][R[1] - 1 + j] == 'B') {
						return -1;
					}
				}
				return 1;
			}
			else if (maze[R[0]][R[1] - 1] == '.') {
				maze[R[0]][R[1]] = '.';
				R[1]--;
				maze[R[0]][R[1]] = 'R';
			}

		}
	}
	else {
		for (i = 0; i < M - 3; i++) {
			if (maze[R[0]][R[1] - 1] == 'O') {
				//for (int j = 0; j < M - (R[1] - 1); j++) {
				for (int j = 0; ; j++) {
					if (maze[R[0]][R[1] - 1 + j] == '#')break;
					if (maze[R[0]][R[1] - 1 + j] == 'B') {
						return -1;
					}
				}
				return 1;
			}
			else if (maze[R[0]][R[1] - 1] == '.') {
				maze[R[0]][R[1]] = '.';
				R[1]--;
				maze[R[0]][R[1]] = 'R';
			}

			if (maze[B[0]][B[1] - 1] == 'O')return -1;
			else if (maze[B[0]][B[1] - 1] == '.') {
				maze[B[0]][B[1]] = '.';
				B[1]--;
				maze[B[0]][B[1]] = 'B';
			}

		}
	}

	return 0;
}

int right() {

	int i;
	//B가 R보다 오른쪽에 있으면 B부터 움직인다.
	if (B[1] > R[1]) {
		for (i = 0; i < M - 3; i++) {
			if (maze[B[0]][B[1] + 1] == 'O')return -1;
			else if (maze[B[0]][B[1] + 1] == '.') {
				maze[B[0]][B[1]] = '.';
				B[1]++;
				maze[B[0]][B[1]] = 'B';
			}

			if (maze[R[0]][R[1] + 1] == 'O') {
				//for (int j = 0; j < M - (R[1] + 1); j++) {
				for (int j = 0; ; j++) {
					if (maze[R[0]][R[1] + 1 - j] == '#')break;
					if (maze[R[0]][R[1] + 1 - j] == 'B') {
						return -1;
					}
				}
				return 1;
			}
			else if (maze[R[0]][R[1] + 1] == '.') {
				maze[R[0]][R[1]] = '.';
				R[1]++;
				maze[R[0]][R[1]] = 'R';
			}

		}
	}
	else {
		for (i = 0; i < M - 3; i++) {
			if (maze[R[0]][R[1] + 1] == 'O') {
				//for (int j = 0; j < M - (R[1] + 1); j++) {
				for (int j = 0; ; j++) {
					if (maze[R[0]][R[1] + 1 - j] == '#')break;
					if (maze[R[0]][R[1] + 1 - j] == 'B') {
						return -1;
					}
				}
				return 1;
			}
			else if (maze[R[0]][R[1] + 1] == '.') {
				maze[R[0]][R[1]] = '.';
				R[1]++;
				maze[R[0]][R[1]] = 'R';
			}

			if (maze[B[0]][B[1] + 1] == 'O')return -1;
			else if (maze[B[0]][B[1] + 1] == '.') {
				maze[B[0]][B[1]] = '.';
				B[1]++;
				maze[B[0]][B[1]] = 'B';
			}

		}
	}

	return 0;
}