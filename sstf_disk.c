#include <stdio.h>
#include <stdlib.h>

void sstf();
int main()
{
    printf("\n.........Shortest Seek Time First.........\n");
    sstf();
    return 0;
}

void sstf(){
	
	int ref_size = 0 ,*ref, i = 0 , head = 0 , save = 0 , j = 0 , l = 0 , k = 0;
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
	 	//	printf("\nstart head value: %d\n",head);
	 		k = 0;
	 		save = INT_MAX;
	 		for(j = 0 ; j < ref_size; j++){
	 			
	 			if(save > abs(head -ref[j]) && ref[j]!= -1){
	 				save = abs(head-ref[j]);
	 				k = j;
				 }
	 			
	 			
	 			
			 }
			 printf ("\n%d: %d moves\n",ref[k],save);
			 head = ref[k];
			 ref[k]= -1;
			/* printf("\noutput\n");
	 		for( l = 0 ; l < ref_size ;l++ ){
	 			printf("\n%d\n",ref[l]);
			 }*/
	 		
	 		
	 		
		}
	
	
	
}

