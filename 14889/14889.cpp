#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int N;
int S[21][21];
int team1[11];
int team2[11];
int visited[21];
int min;

void init() {
	N = 0; min = 2123456789;
	for (int i = 0; i < 21; i++)
	{
		visited[i] = 0;
		for (int j = 0; j < 21; j++)
		{
			S[i][j] = 0;
		}
	}
	for (int i = 0; i < 11; i++)
	{
		team1[i] = 0;
		team2[i] = 0;
	}
}


void makeTeam2() {
	int cnt = 1;
	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == 0) {
			team2[cnt] = i;
			cnt++;
		}
	}
}

int abs(int a) {
	return (a > 0) ? a : -a;
}

void calcTeams() {
	int t1Sum = 0;
	int t2Sum = 0;
	for (int i = 1; i <= N/2; i++)
	{
		for (int j = i+1; j <= N/2; j++)
		{
			t1Sum += S[team1[i]-1][team1[j]-1] + S[team1[j]-1][team1[i]-1];
		}
	}

	for (int i = 1; i <= N/2; i++)
	{
		for (int j = i + 1; j <= N/2; j++)
		{
			t2Sum += S[team2[i]-1][team2[j]-1] + S[team2[j]-1][team2[i]-1];
		}
	}

	int sub = abs(t1Sum - t2Sum);
	if (sub < min) {
		min = sub;
	}

}
void dfs(int depth, int start) {
	if (depth == N / 2 + 1) {
		makeTeam2();
		calcTeams();
		return;
	}

	for (int i = start; i <= N; i++)
	{
		team1[depth] = i;
		visited[i] = 1;
		dfs(depth + 1, i + 1);
		visited[i] = 0;
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &S[i][j]);
		}
	}

	dfs(1, 1);
	printf("%d", min);
	
	return 0;
}