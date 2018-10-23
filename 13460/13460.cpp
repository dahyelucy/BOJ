
/**********************
ªÔº∫ ±‚√‚ : ±∏ΩΩ ≈ª√‚ 2
***********************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

typedef struct node {
	int x;
	int y;
	char color;
	int moveCnt;
}node;

int N, M;
char map[11][11];
char Copy[4][11][11];
int rx, ry;
int bx, by;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
queue<node> q;

void solve() {
	node startR = { rx, ry, 'R', 0 };
	q.push(startR);
	node startB = { bx, by, 'B',0 };
	q.push(startB);

	while(!q.empty()) {
		node temp = q.front();
		q.pop();

		if (temp.moveCnt > 10) {
			printf("-1");
			return;
		}

		for (int k = 0; k < 4; k++)
		{

			Copy[k][temp.x][temp.y] = '.';

			int nx = temp.x + dx[k];
			int ny = temp.y + dy[k];
			int tmpCnt = temp.moveCnt;
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
				continue;
			}
			else if (Copy[k][nx][ny] == '#') {
				continue;
			}
			tmpCnt++;
			while (Copy[k][nx][ny] == '.') {
				nx = nx + dx[k];
				ny = ny + dy[k];
			}
			if (Copy[k][nx + dx[k]][ny + dy[k]] == '0' && temp.color == 'R') {
				if (Copy[k][nx + dx[k]*2][ny + dy[k]*2] == '.' &&
					Copy[k][nx + dx[k] * 3][ny + dy[k] * 3] == '#' &&
					Copy[k][temp.x - dx[k]][temp.y - dy[k]] == 'B') {
					printf("-1");
					return;
				}
				else {
					printf("%d", tmpCnt);
					return;
				}
			}
			else if (Copy[k][nx][ny] == 'O' && temp.color == 'B') {
				printf("-1");
				return;
			}
			node temp2 = { nx-dx[k], ny-dy[k], temp.color, tmpCnt };
			q.push(temp2);
			Copy[k][temp2.x][temp2.y] = temp.color;
		}
	}
}

int main() {

	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		char temp[11];
		scanf("%s", temp);
		for (int j = 0; j < M; j++)
		{
			map[i][j] = temp[j];
			if (temp[j] == 'R') {
				rx = i; ry = j;
			}
			else if (temp[j] == 'B') {
				bx = i; by = j;
			}
		}
	}

	for (int k = 0; k < 4; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				Copy[k][i][j] = map[i][j];
			}
		}
	}
	solve();
	return 0;
}