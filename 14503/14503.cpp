#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int N, M;
int map[51][51];
int visited[51][51];
int dx[4] = { -1, 0, 1, 0};
int dy[4] = { 0, 1, 0, -1 };
int rx, ry, rdir;
int bflag = 0;
int cnt = 0;

void dfs2(int x, int y, int dir) {

	if (bflag == 1) {
		return;
	}

	cnt++;
	visited[x][y] = 1;
	bool flag = false;

	for (int i = 1; i <= 4; i++)
	{
		dir = (dir - 1) < 0 ? 3 : dir - 1;
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (map[nx][ny] == 0 && visited[nx][ny] == 0) {
			flag = true;
			dfs2(nx, ny, dir);
		}
	}

	if (flag == false) {
		int nx = x - dx[dir];
		int ny = y - dy[dir];
		if (map[nx][ny] == 0) {
			for (int i = 1; i <= 4; i++)
			{
				dir = (dir - 1) < 0 ? 3 : dir - 1;
				int nx2 = nx + dx[dir];
				int ny2 = ny + dy[dir];
				if (map[nx2][ny2] == 0 && visited[nx2][ny2] == 0) {
					dfs2(nx2, ny2, dir);
				}
			}
		}
		else if(map[nx][ny]==1){
			bflag = 1;
		}
	}
}



int main() {

	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);

	scanf("%d %d %d", &rx, &ry, &rdir);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	dfs2(rx, ry, rdir);
	printf("%d", cnt);

	return 0;
}