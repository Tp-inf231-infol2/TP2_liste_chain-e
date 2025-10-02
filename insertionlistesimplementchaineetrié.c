#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud {
    int donnee ;
    struct Noeud* suiv;
} Noeud;

Noeud* insererTrie(Noeud* tete, int val) {
    Noeud* nouveau =   (Noeud*)malloc(sizeof(Noeud));
    nouveau->donnee = val;
    nouveau->suiv = NULL;

    if (tete == NULL || val < tete->donnee) {
        nouveau->suiv = tete;
        return nouveau;
}

    Noeud* courant = tete;
    while (courant->suiv != NULL && courant->suiv->donnee < val) {
        courant = courant->suiv;
    }

    nouveau->suiv = courant->suiv;
    courant->suiv = nouveau;

    return tete;
}

void afficherListe(Noeud* tete) {
    Noeud* temp = tete;
    while (temp != NULL) {
        printf("%d -> ", temp->donnee);
        temp = temp->suiv;
    }
    printf("NULL\n");
}

int main() {
    Noeud* liste = NULL;
    int n, val;

    printf("entrer le nombre d'element de la liste : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Entrez la valeur %d : ", i + 1);
        scanf("%d", &val);
        liste = insererTrie(liste, val);
    }

    printf("Entrez un element à inserer : ");
    scanf("%d", &val);
    liste = insererTrie(liste, val);

    printf("Liste triee apres insertion  :\n");
    afficherListe(liste);

    return 0;
}