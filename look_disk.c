#include <stdio.h>
#include <stdlib.h>

void sstf();
int main()
{
    printf("\n.........SCAN DISK SCHEDULING.........\n");
    sstf();
    return 0;
}

void sstf(){
	
	int ref_size = 0 ,*ref, i = 0 , head = 0 , save = 0 , j = 0 , l = 0 , k = 0 , high , low , flag = 0 ;
	char direction;
	printf("\nENTER THE SIZE OF REFERENCE!\n");
	scanf("%d",&ref_size);
	ref = (int*)malloc(ref_size*sizeof(int));
	for( i = 0 ; i < ref_size ;i++){
	 	 printf("\nENTER THE %d NUMBER REFERENCE :",i+1);
		 scanf("%d",&ref[i]);	
		}
	printf("\nENTER THE HEAD!\n");
	scanf("%d",&head);
	fflush(stdin);
	printf("\nENTER THE DIRECTION!\n");
	scanf("%c",&direction);
	printf("\nENTER THE UPPER LIMIT!\n");
	scanf("%d",&high);
	printf("\nENTER THE LOWER LIMIT!\n");
	scanf("%d",&low);
	printf("\n..........Executing...........\n");
	if(direction == 'r'){
		for( i = 0 ; i < ref_size ;i++){
	 	//	printf("\nstart head value: %d\n",head);
	 		k = 0;
	 		save = INT_MAX;
	 		flag = 0;
	 		for(j = 0 ; j < ref_size; j++){
	 			
	 			if(save > abs(head -ref[j]) && ref[j]!= -1 && head < ref[j]){
	 				save = abs(head-ref[j]);
	 				k = j;
	 				flag = 1;
				 }
	 		}
			 
			 if(ref[k] != -1 && flag == 1){
			 printf ("\n%d: %d moves\n",ref[k],save);
			 head = ref[k];
			 ref[k]= -1;
			}
			/* printf("\noutput\n");
	 		for( l = 0 ; l < ref_size ;l++ ){
	 			printf("\n%d\n",ref[l]);
			 }*/
	 		
	 		
		}
		/*save = abs(high - head);
		printf ("\n%d: %d moves\n",high,save);
		head = high;*/
			for( i = 0 ; i < ref_size ;i++){
	 	//	printf("\nstart head value: %d\n",head);
	 		k = 0;
	 		save = INT_MAX;
	 		flag = 0;
	 		for(j = 0 ; j < ref_size; j++){
	 			
	 			if(save > abs(head -ref[j]) && ref[j]!= -1 && head > ref[j]){
	 				save = abs(head-ref[j]);
	 				k = j;
	 				flag = 1;
				 }
	 		}
	 		 if(ref[k]!= -1 && flag == 1){
			 printf ("\n%d: %d moves\n",ref[k],save);
			 head = ref[k];
			 ref[k]= -1;
			}
			/* printf("\noutput\n");
	 		for( l = 0 ; l < ref_size ;l++ ){
	 			printf("\n%d\n",ref[l]);
			 }*/
	 		
	 		
		}
}

	if(direction == 'l'){
		for( i = 0 ; i < ref_size ;i++){
	 		//printf("\nstart head value: %d\n",head);
	 		k = 0;
	 		save = INT_MAX;
	 		flag = 0;
	 		for(j = 0 ; j < ref_size; j++){
	 			
	 			if(save > abs(head -ref[j]) && ref[j]!= -1 && head > ref[j]){
	 				save = abs(head-ref[j]);
	 				k = j;
	 				flag = 1;
				 }
	 		}
			 
			 if(ref[k] != -1 && flag == 1 ){
			 printf ("\n%d: %d moves\n",ref[k],save);
			 head = ref[k];
			 ref[k]= -1;
			}
			/* printf("\noutput\n");
	 		for( l = 0 ; l < ref_size ;l++ ){
	 			printf("\n%d\n",ref[l]);
			 }*/
	 		
	 		
		}
	/*	save = abs(low - head);
		printf ("\n%d: %d moves\n",low,save);
		head = low;*/
		for( i = 0 ; i < ref_size ;i++){
	 	//	printf("\nstart head value: %d\n",head);
	 		k = 0;
	 		save = INT_MAX;
	 		flag = 0;
	 		for(j = 0 ; j < ref_size; j++){
	 			
	 			if(save > abs(head -ref[j]) && ref[j]!= -1 && head < ref[j]){
	 				save = abs(head-ref[j]);
	 				k = j;
	 				flag = 1;
				 }
	 		}
	 		 if(ref[k]!= -1 && flag == 1){
			 printf ("\n%d: %d moves\n",ref[k],save);
			 head = ref[k];
			 ref[k]= -1;
			}
			/* printf("\noutput\n");
	 		for( l = 0 ; l < ref_size ;l++ ){
	 			printf("\n%d\n",ref[l]);
			 }*/
	 		
	 		
		}
}
	
	
}

