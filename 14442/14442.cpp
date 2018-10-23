#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

typedef struct Node {
	int x;
	int y;
	int breaks;
}Node;
int N, M, K;
int map[1001][1001];
int dist[1001][1001][11];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
queue<Node> q;

void solve() {
	Node start = { 1,1,0 };
	dist[1][1][0] = 1;
	q.push(start);

	while (!q.empty()) {
		Node temp = q.front();
		q.pop();

		int x = temp.x; int y = temp.y; 
		int breaks = temp.breaks;

		if (x == N && y == M) {
			printf("%d", dist[x][y][breaks]);
			return;
		}

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx <= 0 || ny <= 0 || nx > N || ny > M) {
				continue;
			}
			if (map[nx][ny] == 0 && dist[nx][ny][breaks] == 0) {
				dist[nx][ny][breaks] = dist[x][y][breaks] + 1;
				Node temp2 = { nx, ny, breaks };
				q.push(temp2);
			}
			else if(map[nx][ny]==1) {
				if (breaks < K && dist[nx][ny][breaks+1]==0) {
					dist[nx][ny][breaks+1] = dist[x][y][breaks] + 1;
					Node temp2 = { nx, ny, breaks+1 };
					q.push(temp2);
				}
			}
		}
	}

	printf("-1");
}

int main() {

	freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++)
	{
		char temp[1001] = "";
		scanf("%s", temp);
		for (int j = 1; j <= M; j++)
		{
			map[i][j] = temp[j-1] - '0';
		}
	}

	solve();

	return 0;
}