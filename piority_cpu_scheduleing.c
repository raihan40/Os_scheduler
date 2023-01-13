	#include<stdio.h>
	#include<stdlib.h>
	int counter = 0;
	void fcfs();
	void dispatch(int*,int,int*,int*);
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
		int *process, p_num = 0 , i = 0 , *pid , *pio,  temp;
		printf("\nPlease enter the  number of process!\n");
		scanf("%d",&p_num);
		process = (int*)malloc(p_num * sizeof(int));
		pid = (int*)malloc(p_num * sizeof(int));
		pio = (int*)malloc(p_num * sizeof(int));
		for(i = 1 ; i <= p_num ;i++){
			printf("\nEnter  Process id :\n");
			scanf("%d",&pid[i]);
			printf("\bEnter the burst time of process id = %d:\n",pid[i]);
			scanf("%d",&process[i]);
			printf("\bEnter the piority of process id = %d:\n",pid[i]);
			scanf("%d",&pio[i]);
		}
		printf("\n.............TASK MANAGER............\n");
		for(i = 1 ; i <= p_num ;i++){
			printf("\nProcess id = %d => Burst time => %d piority => %d\n",pid[i],process[i],pio[i]);
		}
		printf("\n.....................Cpu Start Executing.................................\n");
		dispatch(process,p_num,pid,pio);
	}
	
void dispatch(int *process,int p_num,int *pid, int*pio){
   int i = 0, j = 0 , temp = 0;
   for (i = 1; i <= p_num; i++) 
   	{    
       for (j = 1; j <= p_num-i; j++)
       	{
           if (pio[j] > pio[j+1])
           	{
              temp = process[j];
              process[j] = process[j+1];
              process[j+1]= temp;
              temp = pio[j];
              pio[j] = pio[j+1];
              pio[j+1]= temp;
              temp = pid[j];
              pid[j] = pid[j+1];
              pid[j+1]= temp;
              
			}
   		}	
	}
		for(i = 1 ; i <= p_num ;i++){
			printf("\nProcess id = %d => Burst time => %d  piority=> \n",pid[i],process[i],pio[i]);
		}
	
		for(i = 1 ; i <= p_num ;i++){
			
			printf("\nAt %d unit time process id %d is assigned!\n",counter,pid[i]);
			counter = counter + process[i];
			printf("\nAt %d unit time process id %d is completed\n",counter,pid[i]);
			
		}
	
}


