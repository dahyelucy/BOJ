#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int N, M;
int map[51][51];
int visited[51][51];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int rx, ry, rdir;
int bflag = 0;
int cnt = 0;

void solve() {

	int x = rx; int y = ry; int dir = rdir;

	while (true) {
		if (map[x][y] == 0 && visited[x][y] == 0) {
			visited[x][y] = 1;
			cnt++;
		}
		bool result = false;
		int nx; int ny;
		for (int i = 1; i <= 4; i++)
		{
			dir = (dir - 1) < 0 ? 3 : dir - 1;
			nx = x + dx[dir];
			ny = y + dy[dir];
			if (map[nx][ny] == 0 && visited[nx][ny]==0) {
				result = true;
				break;
			}
		}

		if (result == false) {
			x = x - dx[dir];
			y = y - dy[dir];
			if (map[x][y] == 1) {
				break;
			}
			continue;
		}
		x = nx;
		y = ny;
	
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

	solve();
	printf("%d", cnt);

	return 0;
}