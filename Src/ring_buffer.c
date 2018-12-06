#include "main.h"
#include "ring_buffer.h"


void InitQueue(Queue *queue)
{
    queue->front = queue->rear = 0; //front와 rear를 0으로 설정
}

int IsFull(Queue *queue)
{
    //원형 큐에서 꽉 찼는지 비었는지 체크할 수 있게 rear 다음 공간은 빈 상태를 유지합니다.
    return NEXT(queue->rear) == queue->front;//다음 rear가 front와 같으면 꽉 찬 상태
}

int IsEmpty(Queue *queue)
{
    return queue->front == queue->rear;    //front와 rear가 같으면 빈 상태
}

void Enqueue(Queue *queue, uint8_t data)
{
	uint8_t dummy;
    if (IsFull(queue))//큐가 꽉 찼을 때
    {
        //printf("queue full\r\n");
				dummy = Dequeue(queue);
        //return;
    }
    queue->buf[queue->rear] = data;//rear 인덱스에 데이터 보관
    queue->rear = NEXT(queue->rear); //rear를 다음 위치로 설정
}

uint8_t Dequeue(Queue *queue)
{
    uint8_t re = 0;
    if (IsEmpty(queue))//큐가 비었을 때
    {
        //printf("queue empty\r\n");
        return re;
    }
    re = queue->buf[queue->front];//front 인덱스에 보관한 값을 re에 설정
    queue->front = NEXT(queue->front);//front를 다음 위치로 설정
    return re;
}



uint16_t Len_queue(Queue *queue)
{
	return ((QUEUE_SIZE - queue->front + queue->rear)%QUEUE_SIZE);
}

// queue Test
void print_queue (Queue *queue) 
{
	uint16_t i;
	//printf ("Queue From Front------> To Rear \r\n");
	printf("f:%1d,r:%1d ",queue->front,queue->rear);
	for (i = queue->front; i != queue->rear; i = ((i+1)%QUEUE_SIZE))
	{
		printf("[%d]%2d :", i, queue->buf[i]);
	}
	printf (" L[%2d]\r\n",Len_queue(queue));
}


