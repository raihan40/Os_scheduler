	#include<stdio.h>
	#include<stdlib.h>
	int counter = 0;
	void fcfs();
	void dispatch(int*,int,int*);
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
		int *process, p_num = 0 , i = 0 , *pid ;
		printf("\nPlease enter the  number of process!\n");
		scanf("%d",&p_num);
		process = (int*)malloc(p_num * sizeof(int));
		pid = (int*)malloc(p_num * sizeof(int));
		for(i = 1 ; i <= p_num ;i++){
			printf("\nEnter  Process id :\n");
			scanf("%d",&pid[i]);
			printf("\bEnter the burst time of process id = %d:\n",pid[i]);
			scanf("%d",&process[i]);
		}
		printf("\n.............TASK MANAGER............\n");
		for(i = 1 ; i <= p_num ;i++){
			printf("\nProcess id = %d => Burst time => %d\n",pid[i],process[i]);
		}
		printf("\n.....................Cpu Start Executing.................................\n");
		dispatch(process,p_num,pid);
	}
	
void dispatch(int *process,int p_num,int *pid){
   		int i = 0, j = 0 , time = 0 , flag = 0;
  		printf("\nEnter the time quantrum!\n");
  		scanf("%d",&time);
		for(i = 1 ; i <= p_num ;i++){
			printf("\nProcess id = %d => Burst time => %d  piority=> \n",pid[i],process[i]);
		}
		while(flag < p_num)
		{
		for(i = 1 ; i <= p_num ;i++){
			
			if(process[i] <= time && process[i] != -1){
					printf("\nAt %d unit time process id %d is assigned!\n",counter,pid[i]);
					counter = counter + process[i];
					printf("\nAt %d unit time process id %d is completed!\n",counter,pid[i]);
					flag ++;
					process[i] = -1;
			}
			else{ 
				if(process[i] > time && process[i] != -1)
				{
					printf("\nAt %d unit time process id %d is assigned!\n",counter,pid[i]);
					counter = counter + time;
					printf("\nAt %d unit time process id %d is prempted!\n",counter,pid[i]);
					process[i] =  process[i] - time;
				}
			}
			
		}
	}
	
}


