#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct CCTV {
	int x;
	int y;
	int num;
}CCTV;

typedef struct INFO {
	int num;
	int dir;
}INFO;

int N, M;
int map[9][9];
int copy[9][9];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int cctv1[4] = { 0,1,2,3 };
int cctv2[2][2] = { {0,2},{1,3} };
int cctv3[4][2] = { {0,1}, {0,3}, {2,3}, {2,1} };
int cctv4[4][3] = { {0,1,3}, {0,2,3}, {1,2,3}, {0,1,2} };
int cctv5[1][4] = { {0,1,2,3} };
CCTV cctv[9];
INFO check[9];
int visited[9];
int cnt;
int min=213456789;

void maptoOrigin() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			map[i][j] = copy[i][j];
		}
	}
}
void checkZeroCnt() {
	int zeroCnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0) {
				zeroCnt++;
			}
		}
	}

	if (zeroCnt < min) {
		min = zeroCnt;
	}
}
void makeCCTV() {
	for (int i = 1; i < cnt; i++)
	{
		int nx; int ny;
		switch(check[i].num) {
			case 1:
				nx = cctv[i].x; ny = cctv[i].y;
				while (map[nx][ny] != 6) {
					nx = nx + dx[check[i].dir];
					ny = ny + dy[check[i].dir];
					if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
						break;
					}
					if (map[nx][ny] == 0) {
						map[nx][ny] = 99;
					}
				}
				break;
			case 2:
				for (int j = 0; j < 2; j++)
				{
					nx = cctv[i].x; ny = cctv[i].y;
					while (map[nx][ny] != 6) {
						nx = nx + dx[cctv2[check[i].dir][j]];
						ny = ny + dy[cctv2[check[i].dir][j]];
						if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
							break;
						}
						if (map[nx][ny] == 0) {
							map[nx][ny] = 99;
						}
					}
				}
				break;
			case 3:
				for (int j = 0; j < 2; j++)
				{
					nx = cctv[i].x; ny = cctv[i].y;
					while (map[nx][ny] != 6) {
						nx = nx + dx[cctv3[check[i].dir][j]];
						ny = ny + dy[cctv3[check[i].dir][j]];
						if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
							break;
						}
						if (map[nx][ny] == 0) {
							map[nx][ny] = 99;
						}
					}
				}
				break;
			case 4:
				for (int j = 0; j < 3; j++)
				{
					nx = cctv[i].x; ny = cctv[i].y;
					while (map[nx][ny] != 6) {
						nx = nx + dx[cctv4[check[i].dir][j]];
						ny = ny + dy[cctv4[check[i].dir][j]];
						if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
							break;
						}
						if (map[nx][ny] == 0) {
							map[nx][ny] = 99;
						}
					}
				}
				break;
			case 5:
				for (int j = 0; j < 4; j++)
				{
					nx = cctv[i].x; ny = cctv[i].y;
					while (map[nx][ny] != 6) {
						nx = nx + dx[cctv5[check[i].dir][j]];
						ny = ny + dy[cctv5[check[i].dir][j]];
						if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
							break;
						}
						if (map[nx][ny] == 0) {
							map[nx][ny] = 99;
						}
					}
				}
				break;
		}
	}
}
void dfs(int depth) {
	if (depth == cnt) {
		makeCCTV();
		checkZeroCnt();
		maptoOrigin();
		return;
	}

	switch (cctv[depth].num) {
	case 1:
		for (int j = 0; j < 4; j++)
		{
			check[depth] = { 1, j };
			dfs(depth + 1);
			check[depth] = { 0, 0 };
		}
		break;
	case 2:
		for (int j = 0; j < 2; j++)
		{
			check[depth] = { 2, j };
			dfs(depth + 1);
			check[depth] = { 0,0 };
		}
		break;
	case 3:
		for (int j = 0; j < 4; j++)
		{
			check[depth] = { 3, j };
			dfs(depth + 1);
			check[depth] = { 0, 0 };
		}
		break;
	case 4:
		for (int j = 0; j < 4; j++)
		{
			check[depth] = { 4, j };
			dfs(depth + 1);
			check[depth] = { 0, 0 };
		}
		break;
	case 5:
		check[depth] = { 5,0 };
		dfs(depth + 1);
		check[depth] = { 0,0 };
		break;
	default:
		break;
	}

}


int main() {

	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	
	cnt = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
			copy[i][j] = map[i][j];
			if (1 <= map[i][j] && map[i][j] <= 5) {
				cctv[cnt] = { i,j,map[i][j] };
				cnt++;
			}
		}
	}

	dfs(1);
	printf("%d", min);
	return 0;
}