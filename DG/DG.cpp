#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

typedef struct node{
	int next;
	int depth;
}node;
int N; int M;
bool graph[101][101];
queue<node> q;

bool findCycle(int m) {

	int depth = 0;
	node temp = { 0,depth };
	q.push(temp);


	while (!q.empty()) {
		node temp2 = q.front();
		q.pop();

		if (temp2.next == 0 && temp2.depth ==m) {
			return true;
		}
		if(temp2.next!=0 && temp2.depth==m){
			continue;
		}

		for (int i = 0; i < N; i++)
		{
			if (i != temp2.next) {
				if (graph[temp2.next][i] == true) {
					node temp3 = {i, temp2.depth+1};
					q.push(temp3);
				}
			}
		}
	}
	
	return false;
}


int main() {

	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	char temp[101] = "";

	for (int i = 0; i < N; i++)
	{
		scanf("%s", temp);
		for (int j = 0; j < N; j++)
		{
			graph[i][j] = temp[j] - '0';
		}
	}
	scanf("%d", &M);
	if (findCycle(M))
		printf("1");
	else {
		printf("0");
	}
	return 0;
}