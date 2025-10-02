#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int data;
    struct element* next;
    struct element* prev;
} element;

 element* tete = NULL;

 // Créer un nouvel élément
 element* creerElement(int valeur) {
    element* p = (element*)malloc(sizeof(element));
    p->data = valeur;
    p->next = NULL;
    p->prev = NULL;
    return p;
 }

 // Ajouter au début
 void ajoutDebut(int valeur) {
    element* p = creerElement(valeur);

    if (tete == NULL) {
        tete = p;
        p->next = p;
        p->prev = p;
    } else {
        element* dernier = tete->prev;
        
        p->next = tete;
        p->prev = dernier;
        tete->prev = p;
        dernier->next = p;
        tete = p;
    }
 }

 // Ajouter à la fin
 void ajoutFin(int valeur) {
    element* p = creerElement(valeur);

    if (tete == NULL) {
        tete = p;
        p->next = p;
        p->prev = p;
    } else {
        element* dernier = tete->prev;
        
        dernier->next = p;
        p->prev = dernier;
        p->next = tete;
        tete->prev = p;
    }
 }

 // Afficher la liste
 void afficherListe() {
    if (tete == NULL) {
        printf("Liste vide\n");
        return;
    }
    
    element* temp = tete;
    printf("Liste : ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tete);
    printf("\n");
 }

 // Afficher le menu
 void afficherMenu() {
    printf("\n=== MENU LISTE DOUBLEMENT CHAÎNÉE CIRCULAIRE ===\n");
    printf("1. Ajouter au début\n");
    printf("2. Ajouter à la fin\n");
    printf("3. Afficher la liste\n");
    printf("4.Quitter\n");
 }

 // Fonction principale
 int main() {
    int choix, valeur;
    printf("=== PROGRAMME LISTE DOUBLEMENT CHAÎNÉE CIRCULAIRE ===\n");
    
    do {
        afficherMenu();
        scanf("%d", &choix);
        
        switch(choix) {
            case 1:
                printf("Entrez la valeur à ajouter au début : ");
                scanf("%d", &valeur);
                ajoutDebut(valeur);
                printf("Élément %d ajouté au début\n", valeur);
                break;
                
            case 2:
                printf("Entrez la valeur à ajouter à la fin : ");
                scanf("%d", &valeur);
                ajoutFin(valeur);
                printf("Élément %d ajouté à la fin\n", valeur);
                break;
                
            case 3:
                afficherListe();
                break;
            case4:
               printf ("fin du programme.\n");
               break;
             
            default:
              printf("choix invalide.\n");
                 
        } 
    }while(choix!=4);       
    return 0;
 }