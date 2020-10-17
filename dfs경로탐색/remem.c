#include <stdio.h>
#include <time.h>

#define BUF_SIZE 5

struct Stack *sta;
int visit[BUF_SIZE];
int tbl[BUF_SIZE][BUF_SIZE];

typedef struct Stack {
	int buf[BUF_SIZE];
	int top;
};


void initStack(struct Stack *stack) {
	stack->top = -1;
}
int isFull(struct Stack *stack) {
	return stack->top == BUF_SIZE;
}

int isEmpty(struct Stack *stack) {
	return stack->top == -1;
}

void push(struct Stack *stack, int value) {
	if (isFull(stack)) {
		printf("Stack is Full!\n");
		return;
	}
	stack->top++;
	stack->buf[stack->top] = value;
	return;
}

int pop(struct Stack *stack) {
	if (isEmpty(stack)) {
		printf("Stack is empty!\n");
		return 0;
	}
	int re = stack->buf[stack->top];
	stack->top--;
	return re;
}

void dfs(int v, int goal) {
	visit[v] = 1;
	push(sta, v);
	int i;

	if (v == goal) {
		int count = sta->top + 1;
		for (i = 0; i < count; i++) {
			printf("%d ", sta->buf[i] + 1);
		}
		printf("스택 출력 완료\n");
		pop(sta);
		return;
	}

	for (i = 0; i < BUF_SIZE; i++) {
		if (tbl[v][i] > 0 && visit[i] != 1) {
			dfs(i, goal);
			visit[i] = 0;
		}
	}
	pop(sta);
	return;
}

int main() {

	sta = (struct Stack*)malloc(sizeof(struct Stack));
	initStack(sta);
	int a, b;
	int e;
	printf("a와 b입력(1<= a,b <=5) : "); scanf("%d %d", &a, &b);
	printf("edge입력\n"); scanf("%d", &e);
	int map[(BUF_SIZE * (BUF_SIZE - 1) / 2)][2];
	memset(map, 0, sizeof(map));
	printf("map입력(map의 갯수 = e)\n");
	for (int i = 0; i < e; i++) {
		scanf("%d %d", &map[i][0], &map[i][1]);
		tbl[map[i][0] - 1][map[i][1] - 1] = 1;
		tbl[map[i][1] - 1][map[i][0] - 1] = 1;
	}
	clock_t start = clock();

	printf("%d에서 %d까지 모든 경로 탐색\n", a, b);

	dfs(a - 1, b - 1);

	getch();
	return 0;
}