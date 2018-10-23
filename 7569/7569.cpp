#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

typedef struct Node {
	int z;
	int x;
	int y;
	int day;
}Node;

int M, N, H;
int map[101][101][101];
int visited[101][101][101];
queue<Node> q;
int dz[6] = { 0,0,0,0,-1,1 };
int dx[6] = { -1,1,0,0,0,0 };
int dy[6] = { 0,0,-1,1,0,0 };
int MAX;

int check() {

	for (int k = 0; k < H; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[k][i][j] == 0) {
					return -1;
				}
			}
		}
	}

	return 1;
}

void solve() {

	if (check() == 1) {
		printf("0");
		return;
	}

	for (int k = 0; k < H; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[k][i][j] == 1) {
					Node temp = { k,i,j,0};
					q.push(temp);
				}
			}
		}
	}

	while (!q.empty()) {
		Node temp2 = q.front();
		q.pop();

		if (MAX < temp2.day) {
			MAX = temp2.day;
		}

		for (int d = 0; d < 6; d++)
		{
			int nx = temp2.x + dx[d];
			int ny = temp2.y + dy[d];
			int nz = temp2.z + dz[d];
			if (nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= H) {
				continue;
			}
			if (map[nz][nx][ny] == 0) {
				map[nz][nx][ny] = 1;
				Node temp3 = { nz, nx, ny, temp2.day+1 };
				q.push(temp3);
			}
		}
	}

	if (check() == -1) {
		printf("-1");
	}
	else {
		printf("%d", MAX);
	}

}
int main() {

	freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &M, &N, &H);
	for (int k = 0; k < H; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				scanf("%d", &map[k][i][j]);
			}
		}
	}

	solve();

	return 0;
}