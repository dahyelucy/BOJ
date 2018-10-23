#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R, C, N;
char map[101][101];
int cluster[101][101];
int shoots[101];
int dx[4] = {-1,0,1,0};
int dy[4] = { 0,1,0,-1 };
int clusterNum;
int checkCluster[10001];

void printMap() {
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void checkFloatingCluster(){

	//바닥에 떨어진 클러스터 찾기
	for (int j = 0; j < C; j++)
	{
		if (cluster[R - 1][j] != 0) {
			checkCluster[cluster[R - 1][j]] = 1;
		}
	}

	for (int c = 1; c <= clusterNum; c++)
	{
		int max = -1;
		int xMax = 0;
		int yMax = 0;
		//떠있는 클러스터
		if (checkCluster[c] == 0) {
			for (int j = 0; j < C; j++)
			{
				for (int i = 0; i < R; i++)
				{
					if (cluster[i][j] == c && max < i) {
						max = i;
						xMax = i;
						yMax = j;
					}
				}
			}

			int moveLength = 0;
			for (int i = xMax + 1; i <= R; i++)
			{
				//바닥이거나 가장 가까운 x를 만나면
				if (i == R || map[i][yMax] == 'x') {
					break;
				}
				moveLength++;
			}

			for (int j = 0; j < C; j++)
			{
				for (int i = R-1; i >= 0; i--)
				{
					if (map[i][j] == 'x' && cluster[i][j] == c) {
						map[i + moveLength][j] = 'x';
						cluster[i + moveLength][j] = c;
						map[i][j] = '.';
						cluster[i][j] = 0;
					}
				}
			}
		}
		
	}


}

void initCluster() {
	for (int c = 1; c <= clusterNum; c++)
	{
		checkCluster[c] = 0;
	}
	clusterNum = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cluster[i][j] = 0;
		}
	}
}
void dfs(int x, int y) {
	cluster[x][y] = clusterNum;
	for (int k = 0; k < 4; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || ny < 0 || nx >= R || ny >= C) {
			continue;
		}
		if (map[nx][ny] == 'x' && cluster[nx][ny] == 0) {
			cluster[nx][ny] = clusterNum;
			dfs(nx, ny);
		}
	}
}

void makeCluster() {
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] == 'x' && cluster[i][j]==0) {
				clusterNum++;
				dfs(i, j);
			}
		}
	}
}
void solve() {
	for (int n = 0; n < N; n++)
	{
		//왼
		if (n % 2 == 0) {
			for (int j = 0; j < C; j++)
			{
				if (map[R - shoots[n]][j] == 'x') {
					map[R - shoots[n]][j] = '.';
					makeCluster();
					checkFloatingCluster();
					initCluster();
					break;
				}
			}
			
		}
		//오
		else {
			for (int j = C-1; j >= 0; j--)
			{
				if (map[R - shoots[n]][j] == 'x') {
					map[R - shoots[n]][j] = '.';
					makeCluster();
					checkFloatingCluster();
					initCluster();
					break;
				}
			}
		}
	}
}

int main() {

	freopen("input.txt", "r", stdin);
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
		}
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> shoots[i];
	}

	solve();
	printMap();

	return 0;
}