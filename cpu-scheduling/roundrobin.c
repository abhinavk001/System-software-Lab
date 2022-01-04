#include <stdio.h>
#include <stdlib.h>
#include "ds.h"

int main()
{
	int process_num, i, btime, avg_tut=0, avg_wt=0, wt, time_quantum=1, rem_process ;
	pq *ready_queue;
	pcb *p;

	avg_tut = 0;
	avg_wt = 0;
	ready_queue = (pq *)malloc(sizeof(pq));
	ready_queue->front = NULL;
	ready_queue->rear = NULL;

	
	

	printf("\nEnter number of process: ");
	scanf(" %d", &process_num);
    rem_process = process_num;

	for(i=0;i<process_num;i++)
	{
		p = (pcb *)malloc(sizeof(pcb));
		printf("Enter expected burst time of process p%d: ", i+1);
		scanf("%d",&p->expt_btime);
		p->pid = i+1;
		p->arr_time = 0;       // arrival time taken as 0 for all process
		enqueue(ready_queue, p);
	}
    N *ptr, *temp;
	ptr = ready_queue->front;
    temp = ptr;
	i=0;

	printf("\n+---------------+---------------+-----------------------+----------------+");
	printf("\n| Process id\t|  Burst time\t|  Turnaround time\t|  Waiting time  |\n");
	printf("+---------------+---------------+-----------------------+----------------+\n");
    while(rem_process > 0)
    {
        if(ptr == NULL)
            ptr = ready_queue->front;
        ptr->remain_time -= time_quantum;
		i += time_quantum;
        if(ptr->remain_time<=0)
        {
			wt = i - ptr->addr->expt_btime;
			avg_wt += wt;
			avg_tut += i;
			printf("|  p%d\t\t|  %d\t\t|  %d\t\t\t|  %d\t\t |\n", ptr->addr->pid, ptr->addr->expt_btime, i, wt);
			if(ptr == ready_queue->front)
			{
				temp = ready_queue->front->next;
				ptr = ready_queue->front->next;
				ready_queue->front = ready_queue->front->next;
			}
			else
			{
				temp->next = ptr->next;
				ptr = ptr->next;
			}
			rem_process--;   
        }
		else
		{
			temp = ptr;
        	ptr = ptr->next;
		}
        

    }
	printf("+------------------------------------------------------------------------+\n");

	printf("\nAverage turnaround time: %d", avg_tut/process_num);
	printf("\nAverage waiting time: %d\n", avg_wt/process_num);

}

