#include<stdio.h>
#include<stdlib.h>
float m_a , p_f, m_c = 0;
int* input_frame(int*,int);
int* input_ref(int*, int);
void initializer(int,int);
void fcfs(int*, int*, int, int);
int* insert(int*, int*, int* ,int , int);
int* del(int*, int* ,int *,int);
void input_page();

int main(){
	printf("\n.........FCFS PAGE REPLACEMENT.........\n");
	input_page();
	return 0;
}


void input_page(){
	int frame_size = 0 , ref_size = 0;
	printf("\nEnter the memory access time :\n");
	scanf("%f",&m_a);
	printf("\nEnter the page fault time :\n");
	scanf("%f",&p_f);
	printf("\nENTER THE SIZE OF PAGE FRAME!\n");
	scanf("%d",&frame_size);
	printf("\nENTER THE SIZE OF REFERENCE!\n");
	scanf("%d",&ref_size);
	initializer(frame_size,ref_size);
}

int * del(int* frame, int *f , int *r , int size){
 	if(( *f == -1) && ( *r == -1)) 
    {  
      //  printf("\nQueue is underflow..");  
    }  
 	else if(*f== *r)  
	{  
   //	 printf("\nThe dequeued element is %d", frame[*f]);  
   	 *f = -1;  
   	 *r = -1;
	}   
	else  
	{  
    //	printf("\nThe dequeued element is %d", frame[*f]);  
    	*f =((*f)+1) % size;  
	} 
	return frame; 
}

void initializer(int frame_size,int ref_size){
	 int *frame, *ref;
	 frame = (int*)malloc(frame_size*sizeof(int));
	 ref = (int*)malloc(ref_size*sizeof(int));
	 frame = input_frame(frame, frame_size);
	 ref = input_ref(ref, ref_size);
	 fcfs(frame, ref, frame_size, ref_size);
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

void fcfs(int *frame ,int *ref, int frame_size , int ref_size){
	 int i = 0 , j = 0 , front = -1 , rear = -1 , *f , *r , flag = 0;
	 f = &front;
	 r = &rear;
	 for(i = 0; i < ref_size ; i++){
	 	
	 	printf("\n%d : ",ref[i]);
	 	for( j = 0 ; j < frame_size ;j++){
	 		flag = 0;
	 		if( ref[i] == frame[j] ){
	 			printf("HIT");
	 			flag = 1;
				break;
			}
	 		
		 }
		 if(flag == 0){
		 		printf("MISS");
		 		m_c++;
				frame = insert(frame, f, r, ref[i] ,frame_size);
				for( j = 0 ; j < frame_size ;j++){
	 				printf(" %d ",frame[j]);
		 		}
		 }
	 }
		printf("\nEffective access time = %.3f \n", (((1- (m_c / ref_size))*m_a) +((m_c / ref_size) * p_f)) );
	
}

int* insert(int *frame, int *f , int *r , int key , int size ){
	 if(*f == -1 && *r == -1) 
    {  
        *f = 0;  
        *r = 0;  
        frame[*r] = key;  
    }  
    else if( ( (*r) + 1) % size == *f) 
    {  
       // printf("Queue is overflow..");  
        frame = del(frame,f,r,size);
        frame = insert(frame, f, r, key ,size);
    }  
    else  
    {  
        *r = ((*r)+1) % size;      
        frame[*r] = key;     
    }  
 	return frame;
	
}

