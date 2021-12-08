#include <stdio.h>
#include <stdlib.h>
#include "ds.h"

int main()
{
	pq *ready_queue;
	ready_queue = (pq *)malloc(sizeof(pq));
	ready_queue->front = NULL;
	ready_queue->rear = NULL;

	int process_num, i, btime;

	pcb *p;
	p = (pcb *)malloc(sizeof(pcb));

	printf("Enter number of process: ");
	scanf(" %d", &process_num);

	for(i=0;i<process_num;i++)
	{
		printf("Enter expected burst time:");
		scanf("%d",&p->expt_btime);
		p->pid = i;
		p->arr_time = 0;
		enqueue(ready_queue, p);
	}
	N *ptr;
	ptr = ready_queue->front;
	while(ptr!=NULL)
	{
	printf("%d",ptr->remain_time);
	ptr = ptr->next;
	}

	
	return 0;
}
