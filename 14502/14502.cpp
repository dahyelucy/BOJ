#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

typedef struct Node {
	int x;
	int y;
}Node;
int N, M;
int map[9][9];
int Copy[9][9];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
queue<Node> q;
int MAX;


void copyMap() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			Copy[i][j] = map[i][j];
		}
	}
}
void checkMax() {
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Copy[i][j] == 0)
				cnt++;
		}
	}
	if (MAX < cnt)
		MAX = cnt;
}

void bfs() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Copy[i][j] == 2) {
				Node temp = { i,j };
				q.push(temp);
			}
		}
	}

	while (!q.empty()) {
		Node temp = q.front();
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = temp.x + dx[k];
			int ny = temp.y + dy[k];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
				continue;
			}
			if (Copy[nx][ny] == 0) {
				Copy[nx][ny] = 2;
				Node temp2 = { nx, ny };
				q.push(temp2);
			}
		}
	}
}

void dfs(int depth) {
	if (depth == 3) {
		copyMap();
		bfs();
		checkMax();
		return;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0) {
				map[i][j] = 1;
				dfs(depth + 1);
				map[i][j] = 0;
			}
		}
	}
}

void solve() {
	dfs(0);
}

int main() {

	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);

		}
	}

	solve();
	printf("%d", MAX);
	return 0;
}