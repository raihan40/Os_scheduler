#include<stdio.h>
#include<stdlib.h>
void fcfs_page();

int main(){
	printf("\n.........FCFS DISK SCHEDULE.........\n");
	fcfs_page();
	return 0;
}

void fcfs_page(){
	int ref_size = 0 ,*ref, i = 0 , head = 0 , mov ;
	printf("\nENTER THE SIZE OF REFERENCE!\n");
	scanf("%d",&ref_size);
	ref = (int*)malloc(ref_size*sizeof(int));
	for( i = 0 ; i < ref_size ;i++){
	 	 printf("\nENTER THE %d NUMBER REFERENCE :",i+1);
		 scanf("%d",&ref[i]);	
		}
	printf("\nENTER THE HEAD!\n");
	scanf("%d",&head);
	printf("\n..........Executing...........\n");
	for( i = 0 ; i < ref_size ;i++){
		 printf("%d : ",ref[i]);
		 mov = abs(ref[i] - head);
		 printf("%d moves\n", mov);
		 head = ref[i];	
		}
	
}
