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


void insert_first(liste* L, int val) {
    Element* new = new_node(val);
    
    // Let's print the state at each step!
    printf("\nInserting value: %d\n", val);
    
    if (L->First == NULL) {  // Empty list
        printf("Empty list case:\n");
        L->First = new;      // First points to new node
        printf("L->First now points to node with value: %d\n", L->First->value);
        
        L->Last = new;       // Last points to same node
        printf("L->Last now points to node with value: %d\n", L->Last->value);
        
        new->Next = new;     // Node points to itself
        new->Prev = new;
        printf("Node points to itself in both directions\n");
    } else {
        printf("Non-empty case:\n");
        printf("Current first node has value: %d\n", L->First->value);
        printf("Current last node has value: %d\n", L->Last->value);
        
        new->Next = L->First;  // New node points to old first
        printf("New node's Next points to: %d\n", new->Next->value);
        
        new->Prev = L->Last;   // New node points to last
        printf("New node's Prev points to: %d\n", new->Prev->value);
        
        L->First->Prev = new;  // Old first points back to new
        L->Last->Next = new;   // Last points to new
        
        L->First = new;        // Update First to point to new node
        printf("L->First now points to: %d\n", L->First->value);
    }
}

int main() {
    liste* L = init(L);
    
    // Let's insert 4, 5, 6 and see what happens
    printf("\n=== Inserting 4 ===\n");
    insert_first(L, 4);
    
    printf("\n=== Inserting 5 ===\n");
    insert_first(L, 5);
    
    printf("\n=== Inserting 6 ===\n");
    insert_first(L, 6);
    
    return 0;
}
