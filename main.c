#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void addnode(struct node **baslangic, int data) {  
    struct node *local = (struct node*)malloc(sizeof(struct node));
    local->data = data;  // 'dats' hatalı, 'data' olmalı
    local->next = *baslangic;
    *baslangic = local;
}

void group(struct node **baslangic, int max_tekrar) {
    struct node *gezer = *baslangic;
    struct node *previous = NULL;

    while (gezer != NULL) {
        int counter = 0;
        struct node *newNode = NULL;
        struct node *next = gezer;

        while (next != NULL && next->data == gezer->data && counter < max_tekrar) {
            if (counter == 0) {
                newNode = (struct node*)malloc(sizeof(struct node));
                newNode->data = gezer->data;
                newNode->next = NULL;

                if (previous == NULL) {
                    *baslangic = newNode;
                } else {
                    previous->next = newNode;
                }
                previous = newNode;
            }
            counter++;  // 'sayac' hatalı, 'counter' olmalı
            next = next->next;
        }
        gezer = next;
    }

    if (previous != NULL) {
        previous->next = NULL;
    }
}

void print(struct node *baslangic) {
    struct node *gezer = baslangic;
    printf("{");
    while (gezer != NULL) {
        printf("%d", gezer->data);  // '%d' yerine "%d" olmalı
        gezer = gezer->next;
        if (gezer != NULL) {
            printf(", ");  // Liste elemanları arasında virgül koymak için
        }
    }
    printf("}\n");
}

int main() {
    struct node *head = NULL;

    addnode(&head, 2);
    addnode(&head, 8);
    addnode(&head, 0);
    addnode(&head, 1);
    addnode(&head, 0);
    addnode(&head, 3);
    addnode(&head, 3);
    addnode(&head, 3);
    addnode(&head, 2);

    printf("Orijinal liste: ");
    print(head);
    
    group(&head, 2);
    printf("Gruplanmış hali: ");
    print(head);
    
    return 0;
}
