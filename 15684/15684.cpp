#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int left;
	int right;
}Node;
int N, M, H;
Node ladder[31][11];
Node visited[31][11];

void visitedClear() {
	for (int i = 0; i < 31; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			visited[i][j] = { 0,0 };
		}
	}
}

bool checkLadder(int x, int y, int goal, int depth) {

	if (depth == M+1) {
		if (y == goal) {
			return true;
		}
		else {
			return false;
		}
	}

	if (ladder[x][y].right != 0 && ladder[x][y].left == 0) {
		if (visited[x][y].right == 0) {
			visited[x][y].right = 1;
			visited[x][y + 1].left = 1;
			checkLadder(x, y + 1, goal, depth);
		}
		else {
			checkLadder(x + 1, y, goal, depth + 1);
		}
	}
	else if (ladder[x][y].right == 0 && ladder[x][y].left != 0) {
		if (visited[x][y].left == 0) {
			visited[x][y].left = 1;
			visited[x][y - 1].right = 1;
			checkLadder(x, y - 1, goal, depth);
		}
		else {
			checkLadder(x + 1, y, goal, depth + 1);
		}
	}
	else if (ladder[x][y].right != 0 && ladder[x][y].left != 0) {
		for (int i = 0; i < 2; i++)
		{
			//0일 때는 오른쪽
			if (i == 0) {
				if (visited[x][y].right == 0) {
					visited[x][y].right = 1;
					visited[x][y + 1].left = 1;
					checkLadder(x, y + 1, goal, depth);
					visited[x][y].right = 0;
					visited[x][y + 1].left = 0;
				}
				else {
					checkLadder(x + 1, y, goal, depth + 1);
				}
			}
			//1일 때는 왼쪽
			else {
				if (visited[x][y].left == 0) {
					visited[x][y].left = 1;
					visited[x][y - 1].right = 1;
					checkLadder(x, y - 1, goal, depth);
					visited[x][y].left = 0;
					visited[x][y - 1].right = 0;
				}
				else {
					checkLadder(x + 1, y, goal, depth + 1);
				}
			}
		}
	}
	else {
		checkLadder(x + 1, y, goal, depth + 1);
	}
}

int dfs(int depth, int n) {
	if (depth == n) {
		int flag = 0;
		for (int j = 1; j <= N; j++)
		{
			if (checkLadder(1, j, j, 1)) {
				continue;
			}
			else {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			return depth;
		}
		visitedClear();
		return -1;
	}

	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (ladder[i][j].right == 0 && ladder[i][j + 1].left == 0) {
				if (j + 1 <= N) {
					ladder[i][j].right = j + 1;
					ladder[i][j + 1].left = j;
					dfs(depth + 1, n);
					ladder[i][j].right = 0;
					ladder[i][j].left = 0;
				}
			}
		}
	}
}



int main() {

	freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &N, &M, &H);

	for (int i = 0; i < M; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		if (y + 1 <= N) {
			ladder[x][y].right = y + 1;
			ladder[x][y + 1].left = y;
		}
	}
	

	for (int i = 0; i <= 3; i++)
	{
		if (dfs(0, i) != -1) {
			printf("%d", i);
			return 0;
		}
		else {
			continue;
		}
	}
	
	printf("-1");
	return 0;
}