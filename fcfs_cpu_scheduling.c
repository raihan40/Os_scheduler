#include<stdio.h>
#include<stdlib.h>
int counter = 0;
void fcfs();
void dispatch(int*,int);
void executer(int);
int main(){
	fcfs();
	return 0;
}
void executer(int loop)
{
	int i = 0;
	for(i = 0; i < loop; i++) {
		printf("\nExecuting...\n");
	}
}

void fcfs(){
	int *process, p_num = 0 , i = 0;
	printf("\nPlease enter the  number of process!\n");
	scanf("%d",&p_num);
	process = (int*)malloc(p_num * sizeof(int));
	for(i = 0 ; i < p_num ;i++){
		printf("\nPlease enter burst time of process id = %d:\n",i+1);
		scanf("%d",&process[i]);
	}
	printf("\n.............TASK MANAGER............\n");
	for(i = 0 ; i < p_num ;i++){
		printf("\nProcess id = %d => Burst time => %d\n",i+1,process[i]);
	}
	printf("\n.....................Cpu Start Executing.................................\n");
	dispatch(process,p_num);
}

void dispatch(int *process,int p_num){
		int i = 0 ,temp = 0;
		for(i = 0 ; i < p_num ;i++){
		printf("\n...At %d unit time Process id = %d is assigned...\n",counter,i+1);
		temp = i + 1;5
		executer(process[i]);
		counter = counter + process[i];
		printf("\n...At %d unit time Process id %d is ended...\n",counter,temp);	
	}	
}
