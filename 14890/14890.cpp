#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int N, L;
int map[101][101];
int check[101];
int visited[101];
int cnt;

void clearVisited() {
	for (int i = 0; i < N; i++)
	{
		visited[i] = 0;
	}
}

void checkVisited() {
	bool flag = true;
	for (int i = 0; i < N; i++)
	{
		if (visited[i] == 0) {
			flag = false;
			break;
		}
	}
	if (flag == true)
		cnt++;
}
void moveArray(int line, char rc) {
	if (rc == 'R') {
		for (int j = 0; j < N; j++)
		{
			check[j] = map[line][j];
		}
	}
	else {
		for (int j = 0; j < N; j++)
		{
			check[j] = map[j][line];
		}
	}
	
}

void solve(char rc) {
	for (int i = 0; i < N; i++)
	{
		moveArray(i, rc);
		clearVisited();
		visited[0] = 1;
		for (int j = 1; j < N; j++)
		{
			//증가하는 경우
			if (check[j - 1] +1 == check[j] || check[j-1] == check[j]) {
				bool canVisit = true;
				for (int k = j-1; k > j-1-L; k--)
				{
					if (check[j - 1] != check[k]) {
						canVisit = false;
						break;
					}
					if (visited[k] == 0) {
						canVisit = false;
						break;
					}
					if (k < 0) {
						break;
					}
				}
				if (canVisit == true) {
					visited[j] = 1;
				}
			}
			else if(check[j-1] == check[j] + 1){
				bool canVisit = true;
				for (int k = j; k > j - 1 + L; k++)
				{
					if (check[j - 1] != check[k]) {
						canVisit = false;
						break;
					}
					if (visited[k] == 0) {
						canVisit = false;
						break;
					}
					if (k < 0) {
						break;
					}
				}
				if (canVisit == true) {
					visited[j] = 1;
				}
			}
			else {
				visited[j] = 0;
			}
		}
		checkVisited();

	}

}
int main() {

	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &L);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	solve('R');
	solve('C');
	printf("%d", cnt);
	return 0;
}