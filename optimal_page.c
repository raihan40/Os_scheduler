#include <stdio.h>
#include <stdlib.h>
int *input_frame(int *, int);
int *input_ref(int *, int);
void initializer(int, int);
void lru(int *, int *, int *, int *, int, int);
void input_page();
int blocker(int *, int, int);
int check(int*, int* ,int);
int main()
{
    printf("\n.........OPTIMAL PAGE REPLACEMENT.........\n");
    input_page();
    return 0;
}

void input_page()
{
    int frame_size = 0, ref_size = 0;
    printf("\nENTER THE SIZE OF PAGE FRAME!\n");
    scanf("%d", &frame_size);
    printf("\nENTER THE SIZE OF REFERENCE!\n");
    scanf("%d", &ref_size);
    initializer(frame_size, ref_size);
}

void initializer(int frame_size, int ref_size)
{
    int *frame, *ref, *ref_pos, *frame_pos, i = 0;
    frame = (int *)malloc(frame_size * sizeof(int));
    frame_pos = (int *)malloc(frame_size * sizeof(int));
    for (i = 0; i < frame_size; i++)
    {
        frame_pos[i] = -1;
    }
    ref = (int *)malloc(ref_size * sizeof(int));
    ref_pos = (int *)malloc(ref_size * sizeof(int));
    frame = input_frame(frame, frame_size);
    ref = input_ref(ref, ref_size);
    for (i = 0; i < ref_size; i++)
    {
        ref_pos[i] = i;
    }
    lru(frame, ref, frame_pos, ref_pos, frame_size, ref_size);
}

int *input_frame(int *frame, int frame_size)
{
    int i = 0;
    for (i = 0; i < frame_size; i++)
    {
        frame[i] = -1;
    }
    return frame;
}

int *input_ref(int *ref, int ref_size)
{
    int i = 0;
    for (i = 0; i < ref_size; i++)
    {
        printf("\nENTER THE AT  %d NO. REFERENCE IN STRING:\n", i + 1);
        scanf("%d", &ref[i]);
    }
    return ref;
}

void lru(int *frame, int *ref, int *frame_pos, int *ref_pos, int frame_size, int ref_size)
{
    int flag = 0, flag1 = 0, i = 0, j = 0, flag2 = 0, min = 0, k = 0, temp = 0, prev = -1, l = 0 , m= 0;
    for (i = 0; i < ref_size; i++)
    {
       printf("\n%d : ", ref[i]);
        for (j = 0; j < frame_size; j++)
        {
            flag = 0;
            if (ref[i] == frame[j])
            {
                printf("HIT");
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            printf("MISS");
            if (flag1 < frame_size)
            {
                frame[flag1] = ref[i];
                flag1++;
            }
            else
            {
                flag2 = 0;
                l = 0;
                for (j = i; j < ref_size; j++)
                {
                    //printf("\n j = %d at start\n", j);
                    for (k = 0; k < frame_size; k++)
                    {	prev = k;
                        if (ref[j] == frame[k] && flag2 <= frame_size && blocker(frame_pos, frame_size, ref[j]))
                        {
                          // printf("\n enter when  j = %d at start\n", j);
                            temp = k;
                            frame_pos[l] = ref[j];
                            l++;
                          //  printf("\n%d is found!\n", frame[k]);
                            flag2++;
                        }
                    }
                }
				if(flag2 == frame_size){
                frame[temp] = ref[i];
            	}
            	if(flag2 < frame_size){
            		frame[check(frame,frame_pos,frame_size)] = ref[i];
				}
			}
            for (j = 0; j < frame_size; j++)
            {
                printf(" %d ", frame[j]);
            }
               for (m = 0; m < frame_size; m++)
    			{
        		frame_pos[m] = -1;
    			}
    }
}
}
int blocker(int *arr, int size, int key)
{
    int i = 0;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return 0;
        }
    }
    return 1;
}

int check(int *frame , int* frame_pos ,int size){
	int i = 0 , j = 0 , flag = 0;
	for(i = 0 ; i < size ;i++ ){
		flag = 0;
		for( j = 0 ; j < size ; j++ ){
			if(frame[i] == frame_pos[j]){
				flag = 1;
				break;
			}
		}
		if(flag == 0){
			return i;
		}
	}
	
	
}
