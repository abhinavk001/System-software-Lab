typedef struct process_control_block
{
	unsigned int pid;
	int expt_btime;
	unsigned int arr_time;
    int priority;
} pcb;

typedef struct node {
	pcb * addr;
	int remain_time;
	struct node * next;
} N;

typedef struct Queue {
	N *front;
	N *rear;
} pq;

pq ready_queue;

void enqueue(pq * ready, pcb *p)
{
	N *S;
	S = (N *)malloc(sizeof(N));
	S->addr = p;
	S->remain_time = p->expt_btime;

	if(ready->front==NULL && ready->rear==NULL)
	{
		ready->front = S;
		ready->rear = S;
	}
	else
	{
		(ready->rear)->next = S;
		ready->rear = S;
	}
}

N * dequeue(pq * ready)
{
	N *P = ready->front;
	if(ready->front == ready->rear)
	{
		ready->front = NULL;
		ready->rear = NULL;
	}
	else
	{
		ready->front = (ready->front)->next;
	}
	return P;
}
