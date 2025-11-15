#include <stdio.h>
#include <string.h>

#define MAX_QUEUE_SIZE 2000001

int queue[MAX_QUEUE_SIZE];
int front_index = 0;
int rear_index = 0;
int queue_size = 0;

void push(int x) {
    queue[rear_index] = x;
    rear_index = (rear_index + 1) % MAX_QUEUE_SIZE;
    queue_size++;
}

void pop() {
    if (queue_size == 0) {
        printf("-1\n");
    }
    else {
        printf("%d\n", queue[front_index]);
        front_index = (front_index + 1) % MAX_QUEUE_SIZE;
        queue_size--;
    }
}

void size() {
    printf("%d\n", queue_size);
}

void empty() {
    printf("%d\n", (queue_size == 0) ? 1 : 0);
}

void front() {
    if (queue_size == 0) {
        printf("-1\n");
    }
    else {
        printf("%d\n", queue[front_index]);
    }
}

void back() {
    if (queue_size == 0) {
        printf("-1\n");
    }
    else {
        int back_index = (rear_index - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
        printf("%d\n", queue[back_index]);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    char command[6];
    int X;

    for (int i = 0; i < N; i++) {
        scanf("%s", command);

        if (strcmp(command, "push") == 0) {
            scanf("%d", &X);
            push(X);
        }
        else if (strcmp(command, "pop") == 0) {
            pop();
        }
        else if (strcmp(command, "size") == 0) {
            size();
        }
        else if (strcmp(command, "empty") == 0) {
            empty();
        }
        else if (strcmp(command, "front") == 0) {
            front();
        }
        else if (strcmp(command, "back") == 0) {
            back();
        }
    }

    return 0;
}