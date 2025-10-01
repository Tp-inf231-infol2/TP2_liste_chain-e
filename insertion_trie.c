#include <stdio.h>
#include <stdlib.h>

// Définition d'un nœud
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

// Insertion triée
void insertSorted(Node** head, int data) {
    Node* newNode = createNode(data);

    if (*head == NULL) { // cas liste vide
        *head = newNode;
        return;
    }

    Node* temp = *head;

    // Cas : insertion en tête
    if (data <= temp->data) {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    // Sinon : chercher la bonne place
    while (temp->next != NULL && temp->next->data < data) {
        temp = temp->next;
    }

    // Insertion après temp
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

// Affichage de la liste
void displayList(Node* head) {
    Node* temp = head;
    printf("Liste triée: ");
    while (temp != NULL) {
        printf("[%d] ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    insertSorted(&head, 20);
    insertSorted(&head, 5);
    insertSorted(&head, 30);
    insertSorted(&head, 15);
    insertSorted(&head, 10);

    displayList(head); // Résultat attendu : [5] [10] [15] [20] [30]

    return 0;
}
