#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define default_size 100

typedef struct linklist_s {
    int value;
    struct linklist_s *next;
} linklist_t;

typedef struct {
    linklist_t *front;
    linklist_t *rear;
    int size;
} MyCircularQueue;

bool linklistCreate(linklist_t **root) ;
MyCircularQueue* myCircularQueueCreate(int k) ;
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) ;
bool myCircularQueueDeQueue(MyCircularQueue* obj) ;
int myCircularQueueFront(MyCircularQueue* obj) ;
int myCircularQueueRear(MyCircularQueue* obj) ;
bool myCircularQueueIsEmpty(MyCircularQueue* obj) ;
bool myCircularQueueIsFull(MyCircularQueue* obj) ;
void myCircularQueueFree(MyCircularQueue* obj);

linklist_t* nodeCreate(){
    linklist_t *temp = (linklist_t*) malloc(sizeof (linklist_t));
    if (temp == NULL)
        return false; //error
    
    temp->value = 0;
    temp->next = NULL;
    return temp;
}

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* temp = (MyCircularQueue*) malloc (sizeof (MyCircularQueue));
    if (temp == NULL)
        return NULL; //error
    temp->size = k;
    
    temp->front = nodeCreate();
    if (temp->front == NULL){
	free(temp);
        return NULL;
    }
    temp->rear = temp->front;
    
    // create circular linklist size k
    linklist_t* temp1 = temp->front;
    for (int i = 0; i < k-1; i++){
	temp1->next = nodeCreate();
        if (temp1->next == NULL){
            myCircularQueueFree (temp);
            return NULL;
        }

        temp1= temp1->next;
    }
    temp1 = temp->front;

    return temp;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj == NULL) {
        obj = myCircularQueueCreate(default_size);
        if (obj == NULL)
            return false;
    }
    
    if (myCircularQueueIsFull(obj))
        return false;
    else {
	obj->rear = obj->rear->next;
        obj->rear->value = value;
    }
    
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj == NULL)
        return false;
    
    if (myCircularQueueIsEmpty(obj))
        return false;
    else {
	obj->front = obj->front->next;
        int ret = obj->front->value;
	fprintf(stdout, "dequeue:: %d\n", ret);
    }
    
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    else
        return obj->front->value;
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    else
        return obj->rear->value;
}


bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return ((obj->front) == (obj->rear));
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->rear->next == obj->front);
}

void myCircularQueueFree(MyCircularQueue* obj) {
    if (obj != NULL) {
        linklist_t *temp = obj->front;
        linklist_t *temp_next;
        
        while (temp != NULL) {
            temp_next = temp->next;
            free(temp);
            temp = temp_next;
        }
        
        free(obj);
    }
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/


void main(){
    MyCircularQueue* obj = myCircularQueueCreate(10);
    myCircularQueueEnQueue(obj, 1);
    myCircularQueueEnQueue(obj, 4);
    myCircularQueueEnQueue(obj, 7);
    myCircularQueueEnQueue(obj, 9);
    fprintf(stdout, "rear:: %d\n", myCircularQueueRear(obj));
    myCircularQueueDeQueue(obj);
    myCircularQueueEnQueue(obj, 34);
    fprintf(stdout, "rear:: %d\n", myCircularQueueRear(obj));

    myCircularQueueFree(obj);
}
