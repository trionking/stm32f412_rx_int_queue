#ifndef __RING_BUFFER_H__
#define __RING_BUFFER_H__

#include "stdint.h"

#define QUEUE_SIZE  2000		// 실제 큐 크기는 QUEUE_SIZE-1 이다.
#define NEXT(index)   ((index+1)%QUEUE_SIZE)  //원형 큐에서 인덱스를 변경하는 매크로 함수
 
typedef struct Queue //Queue 구조체 정의
{
    uint8_t buf[QUEUE_SIZE];//저장소
    uint16_t front; //꺼낼 인덱스(가장 오래전에 보관한 데이터가 있는 인덱스)
    uint16_t rear;//보관할 인덱스
}Queue;
 


#ifdef __cplusplus
 extern "C" {
#endif

void InitQueue(Queue *queue);//큐 초기화
int IsFull(Queue *queue); //큐가 꽉 찼는지 확인
int IsEmpty(Queue *queue); //큐가 비었는지 확인
void Enqueue(Queue *queue, uint8_t data); //큐에 보관
uint8_t Dequeue(Queue *queue); //큐에서 꺼냄
void print_queue (Queue *queue);
uint16_t Len_queue(Queue *queue);


#ifdef __cplusplus
}
#endif

#endif /* __RING_BUFFER_H__ */


