#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

typedef struct Node{
	int x;
	int y;
	bool isbreak;
}Node;

int map[1001][1001];
int dist[1001][1001][2];
int N, M, hx, hy, ex, ey;
queue<Node> q;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void solve() {
	Node start = { hx, hy, false };
	q.push(start);
	dist[hx][hy][0] = 0;

	while (!q.empty()) {
		Node temp = q.front();
		q.pop();

		int x = temp.x; int y = temp.y; bool isbreak = temp.isbreak;
		if (x == ex && y == ey) {
			printf("%d", dist[x][y][isbreak]);
			return;
		}

		for (int k = 0; k < 4; k++)
		{
			int nx = temp.x + dx[k];
			int ny = temp.y + dy[k];
			if (nx <= 0 || ny <= 0 || nx > N || ny > M) {
				continue;
			}
			if (map[nx][ny] == 0 && dist[nx][ny][isbreak]==0) {
				dist[nx][ny][isbreak] = dist[x][y][isbreak] + 1;
				Node temp2 = { nx, ny, isbreak };
				q.push(temp2);
			}
			else {
				if (isbreak == 0) {
					dist[nx][ny][1] = dist[x][y][isbreak] + 1;
					Node temp2 = { nx, ny, 1 };
					q.push(temp2);
				}
			}
		}
	}

	printf("-1");
}
int main() {

	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	scanf("%d %d", &hx, &hy);
	scanf("%d %d", &ex, &ey);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <=M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	solve();

	return 0;
}