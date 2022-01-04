#include <stdio.h>
#include <stdlib.h>
#include "ds_priority.h"

void swap(N *a, N *b)
{
    int temp = a->remain_time;
    a->remain_time = b->remain_time;
    b->remain_time = temp;

    temp = (a->addr)->pid;
    (a->addr)->pid = (b->addr)->pid;
    (b->addr)->pid = temp;

    temp = a->addr->priority;
    a->addr->priority = b->addr->priority;
    b->addr->priority = temp;
}

void sort(pq *ready_queue)
{
    int swapped;
    N *ptr1, *ptr2;
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
  
        while (ptr1->next != ptr2)
        {
            if (ptr1->addr->priority > ptr1->next->addr->priority)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    }
    while (swapped);
}

void display(pq *ready_queue, int process_num)
{
    int avg_tut=0, avg_wt=0, wt, tut=0;
    N *ptr;

    ptr = ready_queue->front;
    printf("+---------------+---------------+-----------------------+----------------+-----------+");
	printf("\n| Process id\t|  Burst time\t|  Turnaround time\t|  Waiting time  |  Priority |\n");
	printf("+---------------+---------------+-----------------------+----------------+-----------|\n");
    while(ptr!=NULL)
	{
		tut += ptr->remain_time;
        avg_tut += tut;
		wt = avg_tut - ptr->remain_time;
		printf("|  p%d\t\t|  %d\t\t|  %d\t\t\t|  %d\t\t |  %d\t     |\n", ptr->addr->pid, ptr->remain_time, tut, wt, ptr->addr->priority);
		
		avg_wt += wt;
		ptr = ptr->next;
	}
	printf("+------------------------------------------------------------------------+-----------+\n");

    printf("\nAverage turnaround time: %d", avg_tut/process_num);
	printf("\nAverage waiting time: %d\n", avg_wt/process_num);
}

int main()
{
    //DECLARATION
	int choice, process_num, i, btime ;
	pq *ready_queue;
    pcb *p;

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
        printf("Enter priority of process p%d: ", i+1);
		scanf(" %d",&p->priority);
		p->pid = i+1;
		p->arr_time = 0;      // arrival time taken as 0 for all process
		enqueue(ready_queue, p);
	}
    
    //PROCESSSING
    sort(ready_queue);

    //OUTPUT
    display(ready_queue, process_num);
    
    return 0;
}