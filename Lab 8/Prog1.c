\\ WAP to implement Deque

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct Deque {
    int arr[MAX_SIZE];
    int front, rear;
};

void initializeDeque(struct Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
}

int isFull(struct Deque *dq) {
    return ((dq->front == 0 && dq->rear == MAX_SIZE - 1) || (dq->front == dq->rear + 1));
}

int isEmpty(struct Deque *dq) {
    return (dq->front == -1);
}

void enqueueFront(struct Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full. Cannot enqueue.\n");
    }
    else {
        if (isEmpty(dq)) {
            dq->front = 0;
            dq->rear = 0;
        } else if (dq->front == 0) {
            dq->front = MAX_SIZE - 1;
        } else {
            dq->front = dq->front - 1;
        }

        dq->arr[dq->front] = value;
        printf("%d enqueued at front.\n", value);
    }
}

void enqueueRear(struct Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full. Cannot enqueue.\n");
    } else {
        if (isEmpty(dq)) {
            dq->front = 0;
            dq->rear = 0;
        } else if (dq->rear == MAX_SIZE - 1) {
            dq->rear = 0;
        } else {
            dq->rear = dq->rear + 1;
        }

        dq->arr[dq->rear] = value;
        printf("%d enqueued at rear.\n", value);
    }
}

int dequeueFront(struct Deque *dq) {
    int value;
    if (isEmpty(dq)) {
        printf("Deque is empty. Cannot dequeue.\n");
        return -1;
    } else {
        value = dq->arr[dq->front];

        if (dq->front == dq->rear) {
            initializeDeque(dq);
        } else if (dq->front == MAX_SIZE - 1) {
            dq->front = 0;
        } else {
            dq->front = dq->front + 1;
        }

        printf("%d dequeued from front.\n", value);
        return value;
    }
}

int dequeueRear(struct Deque *dq) {
    int value;
    if (isEmpty(dq)) {
        printf("Deque is empty. Cannot dequeue.\n");
        return -1;
    } else {
        value = dq->arr[dq->rear];

        if (dq->front == dq->rear) {
            initializeDeque(dq);
        } else if (dq->rear == 0) {
            dq->rear = MAX_SIZE - 1;
        } else {
            dq->rear = dq->rear - 1;
        }

        printf("%d dequeued from rear.\n", value);
        return value;
    }
}

int peekFront(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return -1;
    } else {
        return dq->arr[dq->front];
    }
}

int peekRear(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return -1;
    } else {
        return dq->arr[dq->rear];
    }
}

void display(struct Deque *dq) {
    int i = dq->front;
    printf("Deque: ");
    while (i != dq->rear) {
        printf("%d ", dq->arr[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", dq->arr[dq->rear]);
}

int main() {
    struct Deque dq;
    initializeDeque(&dq);

    int choice, value;

    printf("\nINPUT restricted Dequeue Menu\n");
        printf("1. Enqueue Front\n");
        printf("2. Enqueue Rear\n");
        printf("3. Dequeue Front\n");
        printf("4. Dequeue Rear\n");
        printf("5. Peek Front\n");
        printf("6. Peek Rear\n");
        printf("7. Is Empty\n");
        printf("8. Is Full\n");
        printf("9. Display\n");
        printf("0. Exit\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue at front: ");
                scanf("%d", &value);
                enqueueFront(&dq, value);
                break;
            case 2:
                printf("Enter value to enqueue at rear: ");
                scanf("%d", &value);
                enqueueRear(&dq, value);
                break;
            case 3:
                dequeueFront(&dq);
                break;
            case 4:
                dequeueRear(&dq);
                break;
            case 5:
                value = peekFront(&dq);
                if (value != -1) {
                    printf("Peek Front: %d\n", value);
                }
                break;
            case 6:
                value = peekRear(&dq);
                if (value != -1) {
                    printf("Peek Rear: %d\n", value);
                }
                break;
            case 7:
                printf("Is Empty? %s\n", isEmpty(&dq) ? "Yes" : "No");
                break;
            case 8:
                printf("Is Full? %s\n", isFull(&dq) ? "Yes" : "No");
                break;
            case 9:
                display(&dq);
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 0);

}