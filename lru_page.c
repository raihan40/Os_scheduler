#include<stdio.h>
#include<stdlib.h>
int* input_frame(int*,int);
int* input_ref(int*, int);
void initializer(int,int);
void lru(int*,int* ,int* ,int* ,int ,int);
void input_page();
int main(){
	printf("\n.........LRU PAGE REPLACEMENT.........\n");
	input_page();
	return 0;
}

void input_page(){
	int frame_size = 0 , ref_size = 0  ;
	printf("\nENTER THE SIZE OF PAGE FRAME!\n");
	scanf("%d",&frame_size);
	printf("\nENTER THE SIZE OF REFERENCE!\n");
	scanf("%d",&ref_size);
	initializer(frame_size,ref_size);
}

void initializer(int frame_size,int ref_size){
	 int *frame, *ref , *ref_pos , *frame_pos ,i = 0;
	 frame = (int*)malloc(frame_size*sizeof(int));
	 frame_pos = (int*)malloc(frame_size*sizeof(int));
	 ref = (int*)malloc(ref_size*sizeof(int));
	 ref_pos = (int*)malloc(ref_size*sizeof(int));
	 frame = input_frame(frame, frame_size);
	 ref = input_ref(ref, ref_size);
	 for( i = 0 ; i < ref_size ; i++){
	 	ref_pos[i] = i;
	 }
	 lru(frame, ref, frame_pos, ref_pos, frame_size, ref_size);
}


int* input_frame(int *frame , int frame_size){
	int	i = 0;
	for(i = 0 ; i < frame_size ; i++){
		frame[i] = -1;
	}
	return frame;
}


int*input_ref(int* ref, int ref_size){
	int i = 0;
		for(i = 0 ; i < ref_size ; i++){
		printf("\nENTER THE AT  %d NO. REFERENCE IN STRING:\n",i+1);
		scanf("%d",&ref[i]);
	}
	return ref;
}

 void lru(int *frame ,int *ref ,int *frame_pos ,int *ref_pos ,int frame_size ,int ref_size){
 	 int flag = 0 , flag1 = 0 , i = 0 , j = 0 ,flag2 = 0 , min = 0;
 	 for(i = 0; i < ref_size ; i++){
	 	printf("\n%d : ",ref[i]);
	 	for( j = 0 ; j < frame_size ;j++){
	 		flag = 0;
	 		if( ref[i] == frame[j] ){
	 			printf("HIT");
	 			frame_pos[j] = i;
	 			flag = 1;
				break;
			}
	 		
		 }
		 if(flag == 0){
		 		printf("MISS");
		 		if(flag1 < frame_size){
				frame[flag1] = ref[i];
	 			frame_pos[flag1] = i ;
		 		flag1++;
		 	}
		 		else{
		 					j = 0;
							min = j;	
		 					for( j = 0 ; j < frame_size ;j++){
	 								if (frame_pos[min] > frame_pos[j]){
	 									min = j;
									 }
							 }
							 
							 frame[min] = ref[i];
							 frame_pos[min] = i;
		 				
				 }
			
				for( j = 0 ; j < frame_size ;j++){
	 				printf(" %d ",frame[j]);
		 		}
		 }
	}
	 	
	 }




