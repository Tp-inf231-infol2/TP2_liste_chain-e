#include<stdio.h>
#include<stdlib.h>
typedef struct list{
  int val;
  struct list* next;
} list;

list* creer_nouveau(int valeur){
  list* nouveau=malloc(sizeof(list));
  if(nouveau==NULL){
    printf("Erreur d'allocation");
    exit (1);
  }
  nouveau->val=valeur;
  nouveau->next=NULL;
  return nouveau;
}

void inserer_debut(list** head,int valeur){
   list* nouveau=creer_nouveau(valeur);
   if(*head==NULL){
   nouveau->next=nouveau;
   *head=nouveau;
   return;
   }
   list* last=*head;
   while(last->next!=*head){
   last=last->next;
   }
   nouveau->next=*head;
   last->next=nouveau;
   *head=nouveau;
   
}

void inserer_fin(list** head, int valeur){
    list* nouveau=creer_nouveau(valeur);
   if(*head==NULL){
   nouveau->next=nouveau;
   *head=nouveau;
    return;
   }
   
   list* temp=*head;
   while(temp->next!=*head){
       temp=temp->next;
   }
    nouveau->next=temp->next;
    temp->next=nouveau;
    nouveau->next=*head;
}

void affiche(list* head) {
    list* temp = head;
    do{
        printf("%d -> ", temp->val);
        temp = temp->next;
    }while (temp!= head);
    printf("%d",head->val);
}

int main (){
   int i,a,n,valeur;
   list* head=NULL;
   printf("Quelle est le nombre d'éléments de la liste initiale : ");
   scanf("%d",&n);
   printf("Entrer les %d éléments :\n",n);
   for(i=0;i<n;i++){
   scanf("%d",&a);
   inserer_fin(&head,a);
   }
   printf("Entrer l'élément que vous voulez insérer au début de la liste : ");
   scanf("%d",&a);
   inserer_debut(&head,a);
   affiche(head);
   printf("\n\nEntrer l'élément que vous voulez insérer a la fin de la liste : ");
   scanf("%d",&a);
   inserer_fin(&head,a);
   affiche(head);
   return 0;
}