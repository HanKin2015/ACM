#include<stdio.h>
#include<string.h>

int prime[21] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0};
int visited[21];  
int value[21];
int n;

void DFS(int step){
	int i;
	if(step == n+1){
		if(prime[value[step - 1] + 1]){
			for(i = 1;i <= n;i++){
				printf("%d%c",value[i],i==n?'\n':' ');
			}
		}
	}
	else{
		for(i = 2;i <= n;i++){
			if(!visited[i] && prime[i + value[step-1]]){
				visited[i] = 1;
				value[step] = i;
				DFS(step+1);
				visited[i] = 0;
			}
		}
	}
}

int main(){
	int caseNum = 1;
    while(scanf("%d",&n) != EOF){
		memset(visited,0,n);
		printf("Case %d:\n",caseNum);
		value[1] = 1;
		DFS(2);
		printf("\n");
		caseNum ++;
	}
	return 0;
}