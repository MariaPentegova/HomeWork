#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* f; 
    Node* r; 
} Queue;

Node* create_node(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = val;
    node->next = NULL;
    return node;
}

void free_list(Node* list) {
    while (list != NULL) {
        Node* tmp = list;
        list = list->next;
        free(tmp);
    }
}

// если f пустой, собрать его из r
void refill_f_if_needed(Queue* q) {
    if (q->f == NULL) {
        Node* prev = NULL;
        Node* current = q->r;
        while (current != NULL) {
            Node* next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }
        q->f = prev;
        q->r = NULL;
    }
}

void enqueue(Queue* q, int val) {
    Node* new_node = create_node(val);
    new_node->next = q->r;
    q->r = new_node;
}


int dequeue(Queue* q, int* success) {
    refill_f_if_needed(q);
    if (q->f == NULL) {
        *success = 0;
        return -1;
    }
    // взять самый первый элемент
    Node* tmp = q->f;
    int val = tmp->value;
    q->f = q->f->next;
    free(tmp);
    *success = 1;
    return val;
}

// вывод очереди
void print_queue(Queue* q) {
    printf("f: ");
    Node* cur = q->f;
    while (cur != NULL) {
        printf("%d ", cur->value);
        cur = cur->next;
    }
    printf("\nr: ");
    cur = q->r;
    while (cur != NULL) {
        printf("%d ", cur->value);
        cur = cur->next;
    }
    printf("\n");
}

void free_queue(Queue* q) {
    free_list(q->f);
    free_list(q->r);
}

int main() {
    Queue q = {NULL, NULL};

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printf("Добавили 1,2,3:\n");
    print_queue(&q);

    int success;
    int v = dequeue(&q, &success);
    if (success) printf("Убрали: %d\n", v);
    print_queue(&q);

    enqueue(&q, 4);
    enqueue(&q, 5);
    printf("Добавили 4,5:\n");
    print_queue(&q);

    v = dequeue(&q, &success);
    if (success) printf("Убрали: %d\n", v);
    print_queue(&q);

    free_queue(&q);
    return 0;
}
