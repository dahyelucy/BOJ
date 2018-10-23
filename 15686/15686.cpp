#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Node {
	int x;
	int y;
}Node;

int N, M;
int map[51][51];
int visited[51][51];
Node pick[14];
vector<Node> chc;
int minDist=2123456789;
int chicken;

int abs(int a) {
	return (a > 0) ? a : -a;
}

int calcMin() {
	
	int sum = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			//집이면
			if (map[i][j] == 1) {
				int hmin = 213456789;
				for (int m = 1; m <= M; m++)
				{
					int dist = abs(pick[m].x - i) + abs(pick[m].y - j);
					if (dist < hmin) {
						hmin = dist;
					}
				}
				sum += hmin;
			}
		}
	}

	return sum;
}
void dfs(int x, int depth) {
	if (depth == M + 1) {
		int nSum = calcMin();
		if (minDist > nSum) {
			minDist = nSum;
		}
		return;
	}

	for (int i = x; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (map[i][j] == 2 && visited[i][j] == 0) {
				pick[depth] = { i,j };
				visited[i][j] = 1;
				dfs(i,depth + 1);
			}
		}
	}
}

void calc_permutation() {

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (map[i][j] == 2) {
				Node temp = { i,j };
				chc.push_back(temp);
			}
		}
	}

	vector<int> index;
	for (int i = 0; i < M; i++)
	{
		index.push_back(1);
	}
	for (int i = 0; i < chicken - M; i++)
	{
		index.push_back(0);
	}
	sort(index.begin(), index.end());

	do {
		int sum = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				//집이면
				if (map[i][j] == 1) {
					int hmin = 213456789;
					for (int m = 0; m <= index.size(); m++)
					{
						int dist = abs(chc[m].x - i) + abs(chc[m].y - j);
						if (dist < hmin) {
							hmin = dist;
						}
					}
					sum += hmin;
				}
			}
		}

		if (minDist > sum) {
			minDist = sum;
		}

	} while (next_permutation(index.begin(), index.end()));
}

void solve() {
	dfs(1,1);
	//calc_permutation();
}



int main() {

	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) {
				chicken++;
			}
		}
	}

	solve();
	printf("%d", minDist);
	return 0;
}