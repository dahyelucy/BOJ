#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


int input[16][2];
int N;
int max;
int dp[16];

int Max(int a, int b) {
	return (a > b) ? a : b;
}
int main() {

	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		int t, p;
		scanf("%d %d", &t, &p);
		input[i][0] = t; input[i][1] = p;
		dp[i] = p;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (i - j >= input[j][0]) {
				dp[i] = Max(dp[j] + input[i][1], dp[i]);
			}
		}
	}

	for (int i = 1; i <=N; i++)
	{
		if (i + input[i][0] <= N + 1) {
			if (max < dp[i]) {
				max = dp[i];
			}
		}
	}

	printf("%d", max);
	return 0;
}