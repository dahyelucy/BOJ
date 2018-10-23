#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

typedef struct node{
	int x;
	int y;
	int depth;
}node;

int M, N;
int map[1001][1001];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
queue<node> q;

bool checkMap() {
	bool result = true;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0) {
				result = false;
				break;
			}
		}
		if (result == false)
			break;
	}
	return result;
}

void solve() {
	//토마토 모두가 익어있는 상황
	if (checkMap()==true) {
		printf("0");
		return;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 1) {
				node temp = { i, j ,0 };
				q.push(temp);
			}
		}
	}


	while(!q.empty()) {
		//며칠이 지나서 다 익으면
		if (checkMap() == true) {
			//printf("%d\n", depth);
			node temp3 = q.back();
			printf("%d", temp3.depth);
			break;
		}

		node temp = q.front();
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = temp.x + dx[k];
			int ny = temp.y + dy[k];
			int depth = temp.depth;
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
				continue;
			}
			if (map[nx][ny] == 0) {
				map[nx][ny] = 1;
				node temp2 = { nx, ny, depth+1 };
				q.push(temp2);
			}
		}

	}

	if (checkMap() == false) {
		printf("-1");
		return;
	}
}

int main() {

	freopen("input.txt", "r", stdin);
	scanf("%d %d", &M, &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	solve();
	return 0;
}