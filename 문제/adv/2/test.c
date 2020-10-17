#include<stdio.h>
#include<time.h>

char maze[10][10];
int N = 0, M = 0;
char goal[2] = { 0, };
char R[2] = { 0, };
char B[2] = { 0, };

int up();
int down();
int left();
int right();

int main() {

	int i, j, k;
	int temp = 0;
	int count = 0;
	int map[1024 * 2][10];

	scanf("%d %d", &N, &M);
	scanf("%c", &temp);
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%c", &maze[i][j]);
			if (maze[i][j] == 'O') {
				goal[0] = i;
				goal[1] = j;
			}
			else if (maze[i][j] == 'R') {
				R[0] = i;
				R[1] = j;
			}
			else if (maze[i][j] == 'B') {
				B[0] = i;
				B[1] = j;
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
		for (j = 0; j < 10; j++) {
			if (map[i][j] == 0) temp = up();
			else if (map[i][j] == 1) temp = down();
			else if (map[i][j] == 2) temp = left();
			else if (map[i][j] == 3) temp = right();
			/*
			for (int test = 0; test < N; test++) {
			for (int test2 = 0; test2 < M + 1; test2++) {
			printf("%c", maze[test][test2]);
			}
			printf("\n");
			}

			getch();
			*/
			if (temp != 1)count++;
			else break;
		}
		if (temp == 1)break;
		count = 0;
	}

	printf("%d", count);

	getch();
	return 0;
}

int up() {
	for (int i = 0; i < N - 2; i++) {
		if (maze[B[0] - 1][B[1]] == 'O')return -1;
		else if (maze[B[0] - 1][B[1]] == 'R' &&
			maze[R[0] - 2][R[1]] != '#')B[0] -= 1;
		else if (maze[B[0] - 1][B[1]] != '#')B[0] -= 1;
		else if (maze[B[0] - 1][B[1]] == '#')break;

		if (maze[R[0] - 1][R[1]] == 'O')return 1;
		else if (maze[R[0] - 1][R[1]] == 'B' &&
			maze[B[0] - 2][B[1]] != '#')R[0] -= 1;
		else if (maze[R[0] - 1][R[1]] != '#')R[0] -= 1;
		else if (maze[R[0] - 1][R[1]] == '#')break;

	}
	return 0;
}

int down() {
	for (int i = 0; i < N - 2; i++) {
		if (maze[B[0] + 1][B[1]] == 'O')return -1;
		else if (maze[B[0] + 1][B[1]] == 'R' &&
			maze[R[0] + 2][R[1]] != '#')B[0] += 1;
		else if (maze[B[0] + 1][B[1]] != '#')B[0] += 1;
		else if (maze[B[0] + 1][B[1]] == '#')break;

		if (maze[R[0] + 1][R[1]] == 'O')return 1;
		else if (maze[R[0] + 1][R[1]] == 'B' &&
			maze[B[0] + 2][B[1]] != '#')R[0] += 1;
		else if (maze[R[0] + 1][R[1]] != '#')R[0] += 1;
		else if (maze[R[0] + 1][R[1]] == '#')break;
	}
	return 0;
}

int left() {
	for (int i = 0; i < M - 2; i++) {
		if (maze[B[0]][B[1] - 1] == 'O')return -1;
		else if (maze[B[0]][B[1] - 1] == 'R' &&
			maze[R[0]][R[1] - 2] != '#')B[1] -= 1;
		else if (maze[B[0]][B[1] - 1] != '#')B[1] -= 1;
		else if (maze[B[0]][B[1] - 1] == '#')break;

		if (maze[R[0]][R[1] - 1] == 'O')return 1;
		else if (maze[R[0]][R[1] - 1] == 'B' &&
			maze[B[0]][B[1] - 2] != '#')R[1] -= 1;
		else if (maze[R[0]][R[1] - 1] != '#')R[1] -= 1;
		else if (maze[R[0]][R[1] - 1] == '#')break;
	}
	return 0;
}

int right() {
	for (int i = 0; i < M - 2; i++) {
		if (maze[B[0]][B[1] + 1] == 'O')return -1;
		else if (maze[B[0]][B[1] + 1] == 'R' &&
			maze[R[0]][R[1] + 2] != '#')B[1] += 1;
		else if (maze[B[0]][B[1] + 1] != '#')B[1] -= 1;
		else if (maze[B[0]][B[1] + 1] == '#')break;

		if (maze[R[0]][R[1] + 1] == 'O')return 1;
		else if (maze[R[0]][R[1] + 1] == 'B' &&
			maze[B[0]][B[1] + 2] != '#')R[1] += 1;
		else if (maze[R[0]][R[1] + 1] != '#')R[1] += 1;
		else if (maze[R[0]][R[1] + 1] == '#')break;
	}
	return 0;
}