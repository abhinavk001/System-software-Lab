#include <stdio.h>
#include <stdlib.h>
#include "ds.h"

void display(pq *ready_queue, int process_num)
{
	N *ptr;
	int i=0, avg_tut=0, tut=0, avg_wt=0, wt;
	ptr = ready_queue->front;
	printf("+---------------+---------------+-----------------------+----------------+");
	printf("\n| Process id\t|  Burst time\t|  Turnaround time\t|  Waiting time  |\n");
	printf("+---------------+---------------+-----------------------+----------------+\n");

	while(ptr!=NULL)
	{
		tut += ptr->remain_time;
		avg_tut += tut;
		wt = avg_tut - ptr->remain_time;
		printf("|  p%d\t\t|  %d\t\t|  %d\t\t\t|  %d\t\t |\n", i, ptr->remain_time, tut, wt);
		
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
	int process_num, i, btime, avg_tut=0, avg_wt=0, wt ;
	pq *ready_queue;
	pcb *p;
	N *ptr;

	//INITIALIZATIONS
	avg_tut = 0;
	avg_wt = 0;
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
		p->pid = i;
		p->arr_time = 0;       // arrival time taken as 0 for all process
		enqueue(ready_queue, p);
	}
	
	//PROCESSING AND OUTPUT
	display(ready_queue, process_num);

	return 0;
}
