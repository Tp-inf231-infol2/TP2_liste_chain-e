#include <stdio.h>
#include <stdlib.h>

// Définition d'un nœud pour liste doublement chaînée
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Création d'un nouveau nœud
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Procédure : insertion en tête
void insertAtHead(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head != NULL) {
        newNode->next = *head;
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// Procédure : insertion en fin
void insertAtTail(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Procédure : insertion à une position donnée (1 = tête)
void insertAtPosition(Node** head, int data, int pos) {
    if (pos <= 0) {
        printf("Position invalide\n");
        return;
    }
    if (pos == 1) {
        insertAtHead(head, data);
        return;
    }
    Node* temp = *head;
    int i;
    for (i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position invalide\n");
        return;
    }
    Node* newNode = createNode(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

// Procédure : affichage de la liste
void displayList(Node* head) {
    Node* temp = head;
    printf("Liste: ");
    while (temp != NULL) {
        printf("[%d] ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Programme principal
int main() {
    Node* head = NULL;

    // Test des insertions
    insertAtHead(&head, 10);  // Insertion en tête
    insertAtHead(&head, 5);
    displayList(head);        // [5] [10]

    insertAtTail(&head, 20);  // Insertion en fin
    insertAtTail(&head, 30);
    displayList(head);        // [5] [10] [20] [30]

    insertAtPosition(&head, 15, 3); // Insertion à position 3
    displayList(head);               // [5] [10] [15] [20] [30]

    return 0;
}
