#include <stdio.h>
#include <stdlib.h>
#include "ds.h"


void swap(N *a, N *b)
{
	int temp = a->remain_time;
    a->remain_time = b->remain_time;
    b->remain_time = temp;

	temp = (a->addr)->pid;
    (a->addr)->pid = (b->addr)->pid;
    (b->addr)->pid = temp;
}

void sort(pq *ready_queue)
{
	int swapped;
	N *ptr1, *ptr2, *temp;
	ptr2 = NULL;

     if (ready_queue->front == NULL)
     {
         printf("Ready queue empty");
         return;
     }
     do
    {
        swapped = 0;
        ptr1 = ready_queue->front;
		temp = ready_queue->front;
  
        while (ptr1->next != ptr2)
        {
            if (ptr1->remain_time > ptr1->next->remain_time)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
			temp = ptr1;
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    }
    while (swapped);
}

void display(pq *ready_queue, int process_num)
{
	int avg_tut=0, avg_wt=0, tut=0, wt, i;
	N *ptr;
	ptr = ready_queue->front;
    printf("+---------------+---------------+-----------------------+----------------+");
	printf("\n| Process id\t|  Burst time\t|  Turnaround time\t|  Waiting time  |\n");
	printf("+---------------+---------------+-----------------------+----------------+\n");
    while(ptr!=NULL)
	{
		tut += ptr->remain_time;
		avg_tut += tut;
		wt = tut - ptr->remain_time;
		printf("|  p%d\t\t|  %d\t\t|  %d\t\t\t|  %d\t\t |\n", (ptr->addr)->pid, ptr->remain_time, tut, wt);
		
		avg_wt += wt;
		ptr = ptr->next;
		i++;
	}
	printf("+------------------------------------------------------------------------+\n");

	printf("\nAverage turnaround time: %d", avg_tut/process_num);
	printf("\nAverage waiting time: %d\n", avg_wt/process_num);
}

int main()
{
	//DECLARATIONS
	int choice, process_num, i, btime ;
	pq *ready_queue;
	pcb *p;
 
	//INITIALIZATION
	ready_queue = (pq *)malloc(sizeof(pq));
	ready_queue->front = NULL;
	ready_queue->rear = NULL;

	//INPUT
	printf("\nEnter number of process: ");
	scanf(" %d", &process_num);

	for(i=0;i<process_num;i++)
	{
		p = (pcb *)malloc(sizeof(pcb));
		printf("Enter expected burst time of process p%d: ", i+1);
		scanf("%d",&p->expt_btime);
		p->pid = i+1;
		p->arr_time = 0;      // arrival time taken as 0 for all process
		enqueue(ready_queue, p);
	}
	
	//PROCESSING
	sort(ready_queue);

	//OUTPUT
	display(ready_queue, process_num);
    
    return 0;
}