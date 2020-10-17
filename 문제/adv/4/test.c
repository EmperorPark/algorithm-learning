#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Stack {
	int buf[15];
	int top;
};

void Push(struct Stack *stack, int data);
int Pop(struct Stack *stack);
int IsFull(struct Stack *stack);
int IsEmpty(struct Stack *stack);
void InitStack(struct Stack * stack);

int N = 0;
int a[15][15] = { 0, };
int visit[15] = { 0, };
void dfs(int i, int goal);

struct Stack *sta;

int ph[15] = { 0, };
int min = 2401;
int F = 0;
char Fflag = 0;

int main() {

	sta = (struct Stack *)malloc(sizeof(struct Stack));

	int T = 0;
	//int N = 0;//함수에서 접근을 위해 전역으로
	int M = 0;
	int S = 0, E = 0;
	//int F = 0;//함수에서 접근을 위해 전역으로
	
	int map[105][2] = { 0, };//105 -> (n * (n-1)) / 2  :::: n => 15 max값
	
	int i;
	
	scanf("%d", &T);
	clock_t start = clock();//시간체크용

	for (int idx = 0; idx < T; idx++) {
		scanf("%d", &N);
		scanf("%d", &M);
		scanf("%d", &S);
		scanf("%d", &E);
		scanf("%d", &F);

		min = 2401;
		InitStack(sta);
		memset(ph, 0, sizeof(ph));
		memset(map, 0, sizeof(map));
		memset(a, 0, sizeof(a));
		memset(visit, 0, sizeof(visit));

		for (i = 0; i < N; i++) {
			scanf("%d", &ph[i]);
		}

		for (i = 0; i < M; i++) {
			scanf("%d %d", &map[i][0], &map[i][1]);
			a[map[i][0] - 1][map[i][1] - 1] = ph[map[i][1] - 1];//무방향그래프
			a[map[i][1] - 1][map[i][0] - 1] = ph[map[i][1] - 1];//무방향그래프
		}

		dfs(S-1, E-1);//DFS로 모든 경로 탐색
		
		if (min > 2400) {
			min = -1;
		}
		printf("#%d %d\n", idx + 1,min);
		

	}
	
	printf("실행시간 : %f\n", (double)(clock() - start) / CLOCKS_PER_SEC);
	getch();
	return 0;
}



void dfs(int v, int goal) {
	int j;
	int temp = 0;

	visit[v] = 1;
	Push(sta, v);


	if (v == goal) {
		int count = sta->top + 1;
		for (j = 0; j < count; j++) {
			//printf("%d ", ph[sta->buf[j]]);
			if (ph[sta->buf[j]] >= F) {
				Fflag = 1;
				break;
			}
			temp += ph[sta->buf[j]];
		}
		if (Fflag == 0 && temp < min) {
			min = temp;
		}
		//printf("스택%d \n", temp);
		temp = 0;
		Fflag = 0;
		

		Pop(sta);
		return;
	}

	for (j = 0; j < N + 1; j++) {
		if (a[v][j] > 0 && visit[j] != 1) {
			dfs(j, goal);
			visit[j] = 0;
		}
	}
	Pop(sta);
}


void InitStack(struct Stack *stack) {
	stack->top = -1;
}

int IsFull(struct Stack *stack) {
	return (stack->top + 1) == 15;
}

int IsEmpty(struct Stack *stack) {
	return stack->top == -1;
}

void Push(struct Stack *stack, int data) {
	if (IsFull(stack)) {
		printf("Stack Full Error\n");
		return;
	}
	stack->top++;
	stack->buf[stack->top] = data;
}

int Pop(struct Stack *stack) {
	int re = 0;
	if (IsEmpty(stack)) {
		printf("Stack Empty Error\n");
		return re;
	}
	re = stack->buf[stack->top];
	stack->top--;
	return re;
}