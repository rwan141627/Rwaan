
#include <stdio.h>
#include <string.h>

#define CAPACITY 20   // 

typedef struct {
    char data[CAPACITY];
    int front;
    int rear;
    int size;
} RingBuffer;

// تهيئة
void setup(RingBuffer *rb) {
    rb->front = 0;
    rb->rear = 0;
    rb->size = 0;
}

// هل ممتلئ؟
int full(RingBuffer *rb) {
    return rb->size == CAPACITY;
}

// هل فارغ؟
int empty(RingBuffer *rb) {
    return rb->size == 0;
}

// إدخال عنصر
void push(RingBuffer *rb, char ch) {
    if (full(rb)) {
        printf("Buffer is Full!\n");
        return;
    }

    rb->data[rb->rear] = ch;
    rb->rear = (rb->rear + 1) % CAPACITY;
    rb->size++;
}

// إخراج عنصر
char pop(RingBuffer *rb) {
    if (empty(rb)) {
        printf("Buffer is Empty!\n");
        return '\0';
    }

    char ch = rb->data[rb->front];
    rb->front = (rb->front + 1) % CAPACITY;
    rb->size--;
    return ch;
}

int main() {
    RingBuffer rb;
    setup(&rb);

    char input[50];
    printf("Type your text: ");
    fgets(input, sizeof(input), stdin);

    // حذف newline
    input[strcspn(input, "\n")] = '\0';

    // إضافة نص مختلف
    strcat(input, "_SYS");

    // إدخال البيانات
    for (int i = 0; i < strlen(input); i++) {
        push(&rb, input[i]);
    }

    // إخراج البيانات
    printf("Result: ");
    while (!empty(&rb)) {
        printf("%c", pop(&rb));
    }

    printf("\nIs buffer empty? %s\n", empty(&rb) ? "Yes" : "No");

    return 0;
}
