	#include<stdio.h>
	#include<stdlib.h>
	int counter = 0;
	void sjrf();
	void dispatch(int,int*,int*,int*);
	int main(){
		sjrf();
		return 0;
	}
	
	void sjrf(){
		int *arrival, p_num = 0 , i = 0 , *pid , *brust,  temp , flag = 0 , flag1 = 0;
		printf("\nPlease enter the  number of process!\n");
		scanf("%d",&p_num);
		arrival = (int*)malloc(p_num * sizeof(int));
		pid = (int*)malloc(p_num * sizeof(int));
		brust = (int*)malloc(p_num * sizeof(int));
		for(i = 0 ; i < p_num ;i++){
			printf("\nEnter  Process id :\n");
			scanf("%d",&pid[i]);
			printf("\bEnter the arrival time of process id = %d:\n",pid[i]);
			scanf("%d",&arrival[i]);
			printf("\bEnter the burst time of process id = %d:\n",pid[i]);
			scanf("%d",&brust[i]);
			
		}
		printf("\n.............TASK MANAGER............\n");
		for(i = 0 ; i < p_num ;i++){
			printf("\nProcess id = %d => Arrival time => %d Burst time => %d\n",pid[i],arrival[i],brust[i]);
		}
		printf("\n.....................Cpu Start Executing.................................\n");
		dispatch(p_num,pid,arrival,brust);
	}
	
void dispatch(int p_num,int *pid, int *arrival, int *brust){
   int i = 0, j = 0 , temp = 0 , min = 0 , save = 0 , flag = 0 , flag1 = 0, prev = 0;
   for (i = 0; i < p_num - 1; i++) 
   	{    
       for (j = 0; j < p_num-i-1; j++)
       	{
           if (arrival[j] > arrival[j+1])
           	{
              temp = arrival[j];
              arrival[j] = arrival[j+1];
              arrival[j+1]= temp;
              flag = 1;
              
			}
   		}
		   if(flag == 0){
		   	break;
		   }	
	}
/*	for(i = 0 ; i < p_num ;i++){
			
			printf("\nProcess id = %d => Arrival time => %d Burst time => %d\n",pid[i],arrival[i],brust[i]);
	
		}*/
		
	for( i = 0 ; i < p_num; i++ ){
		min = INT_MAX;
		save = -1;
		if(i == 0){
			save = 0;
			prev = save;
		}
		else{
		for( j = 0 ; j <= i ; j++){
			if(min > brust[j] && brust[j] != -1){
				min = brust[j];
				save = j;
			}	
			
		
		}
	}
		
		if(save != -1){
		brust[save] = brust[save] - 1;
			
				printf("\n %d unit time process %d is executing!\n",counter,pid[save]);
			counter++;
		prev = save;
		}
		if(brust[save] == 0){
			arrival[save] = -1;
			brust[save] = -1;
			flag1++;
		}
			
		}
		
		while(flag1 < p_num){
			min = INT_MAX;
			save = -1;
			for( i = 0 ; i < p_num; i++ ){
			
					if(min > brust[i] && brust[i] != -1){
						min = brust[i];
						save = i;
					}	
				}
				
				if(save != -1){
				brust[save] = brust[save] - 1;
			
					
						printf("\n %d unit time process %d is executing!\n",counter,pid[save]);
			
				counter++;
				prev = pid[save];
			
				}
				if(brust[save] == 0){
					arrival[save] = -1;
					brust[save] = -1;
					printf("\n %d unit time process %d is completed!\n",counter,pid[save]);
					flag1++;
				}
			
			}
		
		
		
		/*	for(i = 0 ; i < p_num ;i++){
			printf("\nProcess id = %d => Arrival time => %d Burst time => %d\n",pid[i],arrival[i],brust[i]);
		}*/
		
	}
		
		
	
	

