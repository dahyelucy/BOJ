#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int x;
	int y;
	
}Node;

int N, M;
int map[1001][1001];
int visited[1001][1001];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int min = 2123456789;
int cnt;

void checkMin(int depth) {
	if (min > depth) {
		min = depth;
	}
}

void solve(int x, int y, int depth, bool flag) {

	visited[x][y] = 1;
	if (x == N && y == M) {
		checkMin(depth);
		return;
	}

	cnt = 0;
	for (int d = 0; d < 4; d++)
	{
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (nx <= 0 || ny <= 0 || nx > N || ny > M) {
			continue;
		}
		if (map[nx][ny] == 0 && visited[nx][ny] == 0 && flag == false) {
			solve(nx, ny, depth + 1, false);
		}
		else if (map[nx][ny] == 1 && flag == false) {
			map[nx][ny] = 0;
			solve(nx, ny, depth + 1, true);
			map[nx][ny] = 1;
		}
		else if (map[nx][ny] == 0 && visited[nx][ny] == 0 && flag == true) {
			solve(nx, ny, depth + 1, true);
		}
		else if (map[nx][ny] == 1 && flag == true) {
			cnt++;
			continue;
		}
	}

	if (cnt == 4) {
		return;
	}
}

int main() {

	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		char temp[1001] = "";
		scanf("%s", &temp);
		for (int j = 1; j <= M; j++)
		{
			map[i][j] = temp[j - 1] - '0';
		}
	}

	solve(1, 1, 0, false);
	if (cnt != 4) {
		printf("-1");
	}
	else {
		printf("%d", min - 1);
	}

	return 0;
}