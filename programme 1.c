#include <stdio.h>
#include <stdlib.h>
typedef struct Cellule {
    int valeur;
    struct Cellule *suivant;
} Cellule;
typedef Cellule* Liste;
Cellule* creerCellule(int v) {
    Cellule* nouv = (Cellule*)malloc(sizeof(Cellule));
    nouv->valeur = v;
    nouv->suivant = NULL;
    return nouv;
}
void insererFin(Liste *L, int v) {
    Cellule *nouv = creerCellule(v);
    if (*L == NULL) {
        *L = nouv;
    } else {
        Cellule *p = *L;
        while (p->suivant != NULL) {
            p = p->suivant;
        }
        p->suivant = nouv;
    }
}
void supprimerOccurrences(Liste *L, int v) {
    Cellule *p = *L, *t = NULL, *temp;

    while (p != NULL) {
        if (p->valeur == v) {
            if (t == NULL) {
                
                *L = p->suivant;
                temp = p;
                p = p->suivant;
                free(temp);
            } else{
                t->suivant = p->suivant;
                temp = p;
                p = p->suivant;
                free(temp);
            }
        } else {
            t = p;
            p = p->suivant;
        }
    }
}
void afficherListe(Liste L) {
    Cellule *p = L;
    while (p != NULL) {
        printf("%d->", p->valeur);
        p = p->suivant;
    }
    printf("NULL\n");
}

int main() {
    Liste L = NULL;
    int n, v, i, x;

    printf("Combien d'elements comporte votre liste? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Entrez une valeur de la cellule %d : ",i+1);
        scanf("%d", &x);
        insererFin(&L, x);
    }

    printf("Liste initiale : ");
    afficherListe(L);

    printf("entrez la Valeur a supprimer : ");
    scanf("%d", &v);

    supprimerOccurrences(&L, v);

    printf("Liste apres suppression : ");
    afficherListe(L);

    return 0;
}