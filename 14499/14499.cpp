#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int N, M;
int sx, sy;
int K;
int map[20][20];
int dice[7];
int dx[5] = { 0, 0,0,-1,1 };
int dy[5] = { 0, 1, -1,0,0 };


int main() {

	freopen("input.txt", "r", stdin);
	scanf("%d %d %d %d %d", &N, &M, &sx, &sy, &K);
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	int x = sx; int y = sy;
	for (int k = 0; k < K; k++)
	{
		int dir;
		scanf("%d", &dir);
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
			continue;
		}
		switch (dir)
		{
			int temp;
		case 1:
			temp = dice[1];
			dice[1] = dice[3];
			dice[3] = dice[6];
			dice[6] = dice[4];
			dice[4] = temp;
			dice[5] = dice[5];
			dice[2] = dice[2];
			break;
		case 2:
			temp = dice[1];
			dice[1] = dice[4];
			dice[4] = dice[6];
			dice[6] = dice[3];
			dice[3] = temp;
			dice[2] = dice[2];
			dice[5] = dice[5];
			break;
		case 3:
			temp = dice[1];
			dice[1] = dice[2];
			dice[2] = dice[6];
			dice[6] = dice[5];
			dice[5] = temp;
			dice[3] = dice[3];
			dice[4] = dice[4];
			break;
		case 4:
			temp = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[6];
			dice[6] = dice[2];
			dice[2] = temp;
			dice[3] = dice[3];
			dice[4] = dice[4];
			break;
		default:
			break;
		}
		x = nx;
		y = ny;
		if (map[x][y] == 0) {
			map[x][y] = dice[6];
		}
		else {
			dice[6] = map[x][y];
			map[x][y] = 0;
		}
		printf("%d\n", dice[1]);
	}

	return 0;
}