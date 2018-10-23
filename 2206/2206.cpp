#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <queue>

using namespace std;

typedef struct Node {
	int x;
	int y;
	bool flag;
}Node;

queue<Node> q;
int N, M;
int map[1001][1001];
int dist[1001][1001][2];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int cnt;


void solve2() {
	Node start = { 1,1,false };
	dist[1][1][0] = 1;
	q.push(start);

	while (!q.empty()) {
		Node temp = q.front();
		q.pop();

		int x = temp.x; int y = temp.y; bool isbreak = temp.flag;

		if (x == N && y == M) {
			printf("%d", dist[N][M][1]);
			return;
		}
		
		for (int d = 0; d < 4; d++)
		{
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx <= 0 || ny <= 0 || nx > N || ny > M) {
				continue;
			}
			//현재 상태를 계속 유지하면서 가져옴
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
	for (int i = 1; i <= N; i++)
	{
		char temp[1001] = "";
		scanf("%s", &temp);
		for (int j = 1; j <= M; j++)
		{
			map[i][j] = temp[j-1] - '0';
		}
	}

	solve2();

	
	return 0;
}