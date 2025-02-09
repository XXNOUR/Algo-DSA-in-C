#include <stdio.h>
#include <stdlib.h>

typedef struct ElementListe{
 int valeur;
 struct ElementListe *Prev;
 struct ElementListe *Next;
}Element;

typedef struct liste_DB_CH{
 Element *First;
 Element *Last;
}liste;

liste* Initialiser_Liste(){ 
 liste* L=malloc(sizeof(liste));
 L->First=NULL;
 L->Last=NULL;
return L;
}
Element* new_Node(int valeur){
 Element* new_Node = malloc(sizeof(Element));
  new_Node->valeur = valeur;
  
  new_Node->Prev = NULL;
  new_Node->Next = NULL;
  return new_Node;
}
int Liste_vide(liste* L){
  if (L->First==NULL) {
        return 1;}
  else{
        return 0;}
}

liste* Add_in_first(liste* L,int val){
  Element* new_node = new_Node(val);
  if (Liste_vide(L)) {
    new_node->Next = NULL;
    L->First = new_node;
    L->Last = new_node;
  }
  else {
    new_node->Next = L->First;
    L->First->Prev = new_node;
    L->First = new_node;
  }
  return L;
}

liste* Ajouter_Fin_Liste(liste* L,int valeur){
 Element* New_Element = new_Node(valeur);
 if (Liste_vide(L)){
    New_Element->Prev = NULL;
    L->First = New_Element;
    L->Last = New_Element;
 }
 else {
      New_Element->Prev = L->Last;
      L->Last->Next = New_Element;
      L->Last = New_Element;
 }
return L;
}

void show(liste* L){
  if (Liste_vide(L)) {

  }
 Element* tmp = L->First;
  while (tmp!=NULL) {
    printf("%d -> <- ",tmp->valeur);
    tmp = tmp->Next;
  }
  printf("NULL\n");
}
void show_the_other_way(liste* L){
 Element* tmp = L->Last;
  while (tmp!=NULL) {
    printf("%d <- ",tmp->valeur);
    tmp = tmp->Prev;
  }
printf("NULL \n");

}
liste* Delete_at_head(liste* L){
 Element* tmp = L->First;
 tmp->Next->Prev = NULL;
  L->First = tmp->Next;
  free(tmp);
return L;
}
liste* Delete_at_ASS(liste* L){
 Element* tmp = L->Last;
  tmp->Prev->Next = NULL;
  L->Last = tmp->Prev;
  free(tmp);
}
liste* Add_in_posi(liste* L,int val,int position){
  Element* new_node = new_Node(val);
  Element* node_befor_position = L->First;
  for (int i=0;i<position-1;i++) {
    node_befor_position = node_befor_position->Next;
  }
  Element* node_in_position = node_befor_position->Next;
  new_node->Next = node_in_position;
  node_befor_position->Next = new_node;
  node_in_position->Prev = new_node;
  new_node->Prev = node_befor_position;
}
int First_occ(liste* L,int E){
 Element* tmp = L->First;
  int i=0;
 while (tmp!=NULL) {
    
    if (tmp->valeur==E) {
      return i;
    }
    tmp = tmp->Next;
    i++;
 }
}
int Last_occ(liste* L,int E){
 Element* tmp = L->First;
  int i=0;
  int j=0;
 while (tmp!=NULL) {
    
    if (tmp->valeur==E) {
      j = i;
    }
    tmp = tmp->Next;
    i++;
 }
  return j;
}
liste* Delete_in_posi(liste* L,int position){
  Element* node_befor_position = L->First;
  for (int i=0;i<position-1;i++) {
    node_befor_position = node_befor_position->Next;
  }
  Element* node_in_position = node_befor_position->Next;
  if (node_in_position->Next==NULL) {
    Delete_at_ASS(L);
  }
  else {
   node_befor_position->Next = node_in_position->Next;
  node_befor_position->Next->Prev = node_befor_position;
  free(node_in_position);

  }
  }
void search_all_occ(liste* L,int E){
 Element* tmp = L->First;
  int i=0;
  int j=0;

    while (tmp!=NULL) {
    if (tmp->valeur==E) {
    j=i;
     printf("%d \n",j);
    } 
    tmp = tmp->Next;
    i++;
    }
 
}
int all_occ(liste* L,int E){
 Element* tmp = L->First;
  int j=0;
 while (tmp!=NULL) {
    if (tmp->valeur==E) {
      j++;
    }
   tmp = tmp->Next;
 }
  return j;
}
int length(liste* L){
 Element* tmp = L->First;
  int i=0;
 while (tmp!=NULL) {
    i++;
    tmp = tmp->Next;
 }
  return i;
}


liste* delete_all_occ(liste* L, int val) {
    if (Liste_vide(L)) {
        return L;
    }

    Element* current = L->First;
    while (current != NULL) {
        Element* next = current->Next;  // Store next before potential deletion
        
        if (current->valeur == val) {
            // If it's the first element
            if (current == L->First) {
                L->First = current->Next;
                if (L->First != NULL) {
                    L->First->Prev = NULL;
                }
            }
            // If it's the last element
            else if (current == L->Last) {
                L->Last = current->Prev;
                if (L->Last != NULL) {
                    L->Last->Next = NULL;
                }
            }
            // If it's in the middle
            else {
                current->Prev->Next = current->Next;
                current->Next->Prev = current->Prev;
            }
            
            free(current);
        }
        
        current = next;  // Move to next node (which we stored earlier)
    }
    
    // Handle case where list becomes empty
    if (L->First == NULL) {
        L->Last = NULL;
    }
    
    return L;
}

int main(){
 liste* my_list = Initialiser_Liste();
 Add_in_first(my_list,5);
 Add_in_first(my_list,3);
 Add_in_first(my_list,3);
 Add_in_first(my_list,2);
 Ajouter_Fin_Liste(my_list,11);
  Ajouter_Fin_Liste(my_list,15);
  Ajouter_Fin_Liste(my_list,3);
  // Element* tmp = my_list->Last;
   //printf("-------------------------------------------------------- ordre croisson --\n");
    ////show(my_list);
  //print//f("------------------////----------------------------------------ordre decroissson ---\n");
  //show_the_other_way(my_list)//;
////
  //p//rintf("deleting elemnt in the head \n");
  //De////lete_at_head(my_list);
  //show(//my_list);
  //printf////("deleting at the end \n");
  //printf("L//ast = %d \n",tmp->valeur);
////
  //D//elete_at_ASS(my_list);
//  show(my_list);
  int E=0;
 Add_in_posi(my_list,3,3);
  show(my_list);
  int i = First_occ(my_list,3);
  printf("the first of nulmber --3-- is in position %d \n",i);
  int j = Last_occ(my_list,3);
  printf("the last occ of the numbr --3-- is in position %d \n",j);
   printf("we will delete the elemnt in position 3\n");
  Delete_in_posi(my_list,3);
  show(my_list);
  search_all_occ(my_list,3);
   delete_all_occ(my_list,1);
  show(my_list);
  printf("-------------------------------------------------\n");
  int k = length(my_list);
  printf("number of elemnts is %d \n",k);
  printf("-------------------------------------------------\n");
  printf("entre the elment you want to search \n");
  scanf("%d",&E);
  printf("the elemnt %d occur %d time(s) in the list !!  \n",E,all_occ(my_list,E));
}
