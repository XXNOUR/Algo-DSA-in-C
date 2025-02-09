#include <stdio.h>
#include <stdlib.h>

typedef struct elmentnliste{
  int value;
  struct elmentnliste* Prev;
  struct elmentnliste* Next;
}Element;
typedef struct liste_C{
  Element *First;
  Element *Last;
}liste;

liste* init(liste* L){
 L=malloc(sizeof(liste));
 L->First=NULL;
 L->Last=NULL;
  return L;
}

Element* new_node(int val){
 Element* New = malloc(sizeof(Element));
  New->value = val;
  New->Prev = NULL;
  New->Next = NULL;
  return New;
}

liste* insert_in_fisrt(liste* L,int val){


  if (L==NULL) return L;

  Element* new = new_node(val);

  if (new==NULL) return L;


  if (L->First == NULL) {
      L->First = new;
             L->Last = new;
                  new->Prev = new;
                          new->Next = new;
  }

  else {

       new->Next = L->First;
                    L->First->Prev = new;
                                 new->Prev = L->Last;
                                                     L->Last->Next = new;
                                            L->First = new;
  }
  return L;
  }

liste*  instert_at_the_ENd(liste* L,int val){
  if (L==NULL) return L;
  
 Element* new = new_node(val);

  if (new==NULL) return L;


  // if it is the firts node 
  if (L->First == NULL) {
      L->First = new;
             L->Last = new;
                  new->Prev = new;
                          new->Next = new;
  }
  else {
   new->Prev = L->Last;
   new->Next = L->First;
   L->Last->Next = new;
   L->Last = new;
  }


return L;

}

void display(liste* L){

 if (L==NULL || L->First == NULL) {
    printf("empty List \n");
 }
  Element* tmp = L->First;
 do {
    printf("%d -> ",tmp->value);
    tmp = tmp->Next;

 } while (tmp!=L->First);
  printf("%d \n",L->First->value);
}

void free_Liste(liste* L){
 Element* tmp = L->First;
 Element* tmp2 = tmp;
do {
    tmp2 = tmp2->Next;
    free(tmp);
    tmp = tmp2;
} while (tmp!=L->First);
  printf("meory free \n");
}

int main(){

  liste* M = init(M);

  insert_in_fisrt(M,10);
  insert_in_fisrt(M,11);
  insert_in_fisrt(M,12);
  instert_at_the_ENd(M,14);
  display(M);
  free_Liste(M);
  return 0;
}
