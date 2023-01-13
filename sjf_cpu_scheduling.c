	#include<stdio.h>
	#include<stdlib.h>
	int counter = 0;
	void fcfs();
	void dispatch(int*,int,int*,int*);
	void executer(int);
	int p_found(int*, int, int);
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
		int *process, p_num = 0 , i = 0 , *pid , *mid,  temp;
		printf("\nPlease enter the  number of process!\n");
		scanf("%d",&p_num);
		process = (int*)malloc(p_num * sizeof(int));
		pid = (int*)malloc(p_num * sizeof(int));
		mid = (int*)malloc(p_num * sizeof(int));
		for(i = 1 ; i <= p_num ;i++){
			printf("\nEnter  Process id :\n");
			scanf("%d",&pid[i]);
			printf("\bEnter the burst time of process id = %d:\n",pid[i]);
			temp = pid[i];
			scanf("%d",&process[temp]);
			mid[pid[i]] = process[pid[i]]; 
		}
		printf("\n.............TASK MANAGER............\n");
		for(i = 1 ; i <= p_num ;i++){
			printf("\nProcess id = %d => Burst time => %d mid => %d\n",pid[i],process[i],mid[i]);
		}
		printf("\n.....................Cpu Start Executing.................................\n");
		dispatch(process,p_num,pid,mid);
	}
	
void dispatch(int *process,int p_num,int *pid, int*mid){
   int i = 0, j = 0 , temp = 0;
   for (i = 1; i <= p_num; i++) 
   	{    
       for (j = 1; j <= p_num-i; j++)
       	{
           if (process[j] > process[j+1])
           	{
              temp = process[j];
              process[j] = process[j+1];
              process[j+1]= temp;
              
			}
   		}	
	}
		for(i = 1 ; i <= p_num ;i++){
			printf("\nProcess id = %d => Burst time => %d\n",pid[i],process[i]);
		}
	
		for(i = 1 ; i <= p_num ;i++){
			
			temp = p_found(mid,process[i],p_num);
			printf("\nAt %d unit time process id %d is assigned!\n",counter,temp);
			counter = counter + process[i];
			printf("\nAt %d unit time process id %d is completed\n",counter,temp);
			
		}
	
}

int p_found(int * mid , int key , int size){
		int i = 0;
	
		for(i = 1 ; i <= size ;i++){
			if(mid[i] == key){
				return i;
			}
		
		}
		
}
	
