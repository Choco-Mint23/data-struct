#include <stdio.h>

#define MAX 10
#define NAME_LEN 30

typedef struct {
    char name[NAME_LEN];
    float gwa;
} Student;

typedef struct {
    Student data[MAX];
    int count;
} PriorityQueue;

void initialize(PriorityQueue *pq) {
    pq->count = 0;
}

void enqueue(PriorityQueue *pq, Student s) {
    int i = pq->count - 1;

    while (i >= 0 && pq->data[i].gwa > s.gwa) {
        pq->data[i + 1] = pq->data[i];
        i--;
    }

    pq->data[i + 1] = s;
    pq->count++;
}

void display(PriorityQueue pq) {
    int i;
    for (i = 0; i < pq.count; i++) {
        printf("%s | %.2f\n", pq.data[i].name, pq.data[i].gwa);
    }
}

int main() {
    PriorityQueue pq;
    Student s;
    int n, i;

    initialize(&pq);

    printf("Number of applicants: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter name of applicant #%d: ",i+1);
        scanf(" %[^\n]", s.name);

        printf("Enter GWA: ");
        scanf("%f", &s.gwa);

        enqueue(&pq, s);
    }

    printf("\nEnrollment Priority List (Information Technology):\n");
    display(pq);

    return 0;
}
