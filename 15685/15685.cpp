#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
	int x=-1;
	int y=-1;
}Node;

typedef struct INFO{
	Node nodes[10001];
	int length;
}INFO;

int N; 
int map[101][101];
INFO curves[10];
int dx[4] = { 1, 0, -1, 0};
int dy[4] = { 0, -1, 0, 1};
int cnt;

int abs(int a) {
	return (a > 0) ? a : -a;
}

Node returnGenStartPoint(int sx, int sy, INFO curves) {
	int tmpcnt = 0;
	int max = -1;
	int xIdx = 0;
	int yIdx = 0;
	
	while ( curves.nodes[tmpcnt].x!=-1 && curves.nodes[tmpcnt].y!=-1) {
		if (abs(sx - curves.nodes[tmpcnt].x) + abs(sy - curves.nodes[tmpcnt].y) > max) {
			max = abs(sx - curves.nodes[tmpcnt].x) + abs(sy - curves.nodes[tmpcnt].y);
			xIdx = curves.nodes[tmpcnt].x; yIdx = curves.nodes[tmpcnt].y;
		}
		tmpcnt++;
	}
	Node temp = { xIdx, yIdx };
	return temp;
}

Node retn90Node(int x, int y) {
	Node temp;
	if (x >= 0) {
		temp.y = x;
	}
	else {
		temp.y = x;
	}

	if (y >= 0) {
		temp.x = -y;
	}
	else {
		temp.x = -y;
	}

	return temp;
}

void makeDragonCurve(int sx, int sy, int dir, int gen) {

	//세대만큼 반복
	curves[0].nodes[0] = { sx, sy };
	curves[0].nodes[1] = { sx + dx[dir], sy + dy[dir] };
	curves[0].length = 2;
	map[sx][sy] = 1;
	map[sx + dx[dir]][sy + dy[dir]] = 1;


	for (int g = 1; g <= gen; g++)
	{
		int cnt = 0;
		Node gsp = returnGenStartPoint(sx, sy, curves[g-1]);
		for (int i = 0; i < curves[g-1].length; i++)
		{
			if ((curves[g - 1].nodes[i].x != gsp.x) || (curves[g - 1].nodes[i].y != gsp.y)) {
				int x = curves[g - 1].nodes[i].x - gsp.x;
				int y = curves[g - 1].nodes[i].y - gsp.y;
				Node newDir = retn90Node(x, y);
				if (gsp.x + newDir.x < 0 || gsp.x + newDir.x >= 101 || gsp.y + newDir.y < 0 || gsp.y + newDir.y >= 101) {
					continue;
				}
				else {
					curves[g].nodes[cnt] = { gsp.x + newDir.x, gsp.y + newDir.y };
					map[gsp.x + newDir.x][gsp.y + newDir.y] = 1;
					cnt++;
				}
			}
		}
		for (int i = 0; i < curves[g - 1].length; i++)
		{
			curves[g].nodes[cnt] = curves[g - 1].nodes[i];
			cnt++;
		}
		curves[g].length = cnt;
	}
}

void printMap() {
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}
void cntSquare() {
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			if (map[i][j] == 1) {
				if (i + 1 >= 100 || j + 1 >= 100) {
					continue;
				}
				if (map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1) {
					cnt++;
				}
			}
		}
	}
}
int main() {

	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		int x, y, dir, gen;
		scanf("%d %d %d %d", &x, &y, &dir, &gen);
		makeDragonCurve(x, y, dir, gen);
	}
	cntSquare();
	printMap();
	printf("%d", cnt);
	return 0;
}#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
	int x=-1;
	int y=-1;
}Node;

typedef struct INFO{
	Node nodes[10001];
	int length;
}INFO;

int N; 
int map[101][101];
INFO curves[10];
int dx[4] = { 1, 0, -1, 0};
int dy[4] = { 0, -1, 0, 1};
int cnt;

int abs(int a) {
	return (a > 0) ? a : -a;
}

Node returnGenStartPoint(int sx, int sy, INFO curves) {
	int tmpcnt = 0;
	int max = -1;
	int xIdx = 0;
	int yIdx = 0;
	
	while ( curves.nodes[tmpcnt].x!=-1 && curves.nodes[tmpcnt].y!=-1) {
		if (abs(sx - curves.nodes[tmpcnt].x) + abs(sy - curves.nodes[tmpcnt].y) > max) {
			max = abs(sx - curves.nodes[tmpcnt].x) + abs(sy - curves.nodes[tmpcnt].y);
			xIdx = curves.nodes[tmpcnt].x; yIdx = curves.nodes[tmpcnt].y;
		}
		tmpcnt++;
	}
	Node temp = { xIdx, yIdx };
	return temp;
}

Node retn90Node(int x, int y) {
	Node temp;
	if (x >= 0) {
		temp.y = x;
	}
	else {
		temp.y = x;
	}

	if (y >= 0) {
		temp.x = -y;
	}
	else {
		temp.x = -y;
	}

	return temp;
}

void makeDragonCurve(int sx, int sy, int dir, int gen) {

	//세대만큼 반복
	curves[0].nodes[0] = { sx, sy };
	curves[0].nodes[1] = { sx + dx[dir], sy + dy[dir] };
	curves[0].length = 2;
	map[sx][sy] = 1;
	map[sx + dx[dir]][sy + dy[dir]] = 1;


	for (int g = 1; g <= gen; g++)
	{
		int cnt = 0;
		Node gsp = returnGenStartPoint(sx, sy, curves[g-1]);
		for (int i = 0; i < curves[g-1].length; i++)
		{
			if ((curves[g - 1].nodes[i].x != gsp.x) || (curves[g - 1].nodes[i].y != gsp.y)) {
				int x = curves[g - 1].nodes[i].x - gsp.x;
				int y = curves[g - 1].nodes[i].y - gsp.y;
				Node newDir = retn90Node(x, y);
				if (gsp.x + newDir.x < 0 || gsp.x + newDir.x >= 101 || gsp.y + newDir.y < 0 || gsp.y + newDir.y >= 101) {
					continue;
				}
				else {
					curves[g].nodes[cnt] = { gsp.x + newDir.x, gsp.y + newDir.y };
					map[gsp.x + newDir.x][gsp.y + newDir.y] = 1;
					cnt++;
				}
			}
		}
		for (int i = 0; i < curves[g - 1].length; i++)
		{
			curves[g].nodes[cnt] = curves[g - 1].nodes[i];
			cnt++;
		}
		curves[g].length = cnt;
	}
}

void printMap() {
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}
void cntSquare() {
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			if (map[i][j] == 1) {
				if (i + 1 >= 100 || j + 1 >= 100) {
					continue;
				}
				if (map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1) {
					cnt++;
				}
			}
		}
	}
}
int main() {

	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		int x, y, dir, gen;
		scanf("%d %d %d %d", &x, &y, &dir, &gen);
		makeDragonCurve(x, y, dir, gen);
	}
	cntSquare();
	printMap();
	printf("%d", cnt);
	return 0;
}