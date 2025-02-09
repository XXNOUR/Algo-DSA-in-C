#include <stdlib.h>
#include <stdio.h>

struct Node {
  int val;
  struct Node* link;
};

typedef struct Node Node ;
// FOR SAVING THE ADRESS OF THE fuck OF THE NODE 
typedef Node* List;

List New_Node(int value){
    List New_fucking_Node = (List)malloc(sizeof(Node));
    if (New_fucking_Node == NULL) {
        return NULL;
    }
    New_fucking_Node->val = value;
    New_fucking_Node->link = NULL;  // Initialize this!
    return New_fucking_Node;
}
 
int  how_many_elemnts_it(List fuck){
 List tmp = fuck;
  int i=0;
  while (tmp != NULL) {
    i++;
    tmp = tmp->link;
  }
  return i;
}
void Delte_in_posi(List fuck,int P){
  List tmp = fuck;
  List tmp2 = fuck;
  if (P==0) {
    fuck = tmp->link;
    free(tmp);
  }
  for (int i=0;i<P;i++) {
    if (i<P-1) {
    tmp  = tmp->link;
      tmp2 = tmp2->link;
    }
    tmp2 = tmp2->link;
  }
  tmp->link = tmp2->link;
  free(tmp2);
}



void insertAtPosition(List fuck, int value, int position) {
    if (position < 0) {
        return;
    }
    
    if (position == 0 || fuck == NULL) {
        List newNode = New_Node(value);
        newNode->link = fuck;
        fuck = newNode;
        return;
    }
    
    List current = fuck;
    int currentPos = 0;
    
    while (current != NULL && currentPos < position - 1) {
        current = current->link;
        currentPos++;
    }
    
    if (current != NULL) {
        List newNode = New_Node(value);
        newNode->link = current->link;
        current->link = newNode;
    }
}

  
int how_many_elemnts_recur(List fuck){
  if (fuck == NULL) {
   return 0;
  } 
   return 1+how_many_elemnts_recur(fuck->link);
  }
// this function will try to calculate how many accurnaces and elemnt hs in a list 
int Acc(List fuck,int value){
  List tmp = fuck;
  int i=0;
  while (tmp != NULL) {
    if (tmp->val == value) {
     i++;
    }
    tmp = tmp->link;
  }
  return i;
}

int Acc_recur(List fuck,int value){
 if (fuck == NULL) {
    return 0;
 }
  if (fuck->val == value) {
    return 1+Acc_recur(fuck->link,value);
  }
  return Acc_recur(fuck->link,value);
}
// this function will find the position of an given elemnt 
 int find(List fuck,int value){
  List tmp = fuck;
  int i =0;
  while (tmp != NULL) {
    if (tmp->val == value) {
      return i;
    }
    i++;
    tmp = tmp->link;
  }
  return -1;
}


List ins(List fuck){

  fuck = NULL;
  return fuck;
}
//this function will not link the node that is bring crate it will just create a 8 bit memory for the new node 


 

 
// this function will create a new node and assing it to the first of the list 
List in_the_B(List fuck,int value){
  List New_fucking_Node = New_Node(value);
  New_fucking_Node->link = fuck;
  return New_fucking_Node;
}
// we create a tmp variable to walk throuh the liste and prntint values 
void show_List(List fuck){
 List tmp = fuck;
  while (tmp != NULL) {

    printf("%d -> ",tmp->val);
    tmp = tmp->link;
  }
  printf("Null\n");
}
int Posisi(List fuck,int pos){
  int i=0;
  List tmp = fuck;
  while (tmp != NULL) {
    if (i==pos) {
      int u = tmp->val;
      return u;
    }
    i++;
    tmp = tmp->link;
  }
return 0;
}
void free_it_the_fuck_out(List fuck){
 List tmp = fuck;
  while (tmp != NULL) {
    List link = tmp->link;
    free(tmp);
    tmp = link;
  }
  printf("ohhh yah memory is free now not like your algerian asss \n");
}

 int main(int argc, char *argv[])
{
  int value;
  int pause;
  List my_fucking_list = ins(my_fucking_list);
  printf("-----------------------------------------------------------\n");
  printf("i will create a liste with 4 element from 5 to 8 \n");
  my_fucking_list = in_the_B(my_fucking_list,8);
  my_fucking_list = in_the_B(my_fucking_list,5);
  my_fucking_list = in_the_B(my_fucking_list,5);
  my_fucking_list = in_the_B(my_fucking_list,5);
  show_List(my_fucking_list);

  printf("-----------------------------------------------------------\n");
  printf("-----------------------------------------------------------\n");
  printf("using iterative vertion there is %d elemnts in your list \n",how_many_elemnts_it(my_fucking_list));

  printf("-----------------------------------------------------------\n");
  printf("using recurtion there are %d elemnts in your list \n",how_many_elemnts_recur(my_fucking_list));
  
  printf("-----------------------------------------------------------\n");
  printf("entre the element you want to know \n");
  scanf("%d",&value);

  printf("-----------------------------------------------------------\n");
  printf("USIND DUMB V there is %d of the elemnt %d \n",Acc(my_fucking_list,value),value);

  printf("-----------------------------------------------------------\n");
  printf("using the cool v there is %d of the elemnt %d \n",Acc_recur(my_fucking_list,value),value);

  printf("-----------------------------------------------------------\n");
  printf("-----------------------------------------------------------\n");
   printf("entre the position u want to search \n");
   scanf("%d",&pause);

  printf("-----------------------------------------------------------\n");
  printf("-----------------------------------------------------------\n");
   printf("the calue in pos %d is %d \n",pause,Posisi(my_fucking_list,pause));


  printf("-----------------------------------------------------------\n");
  printf("-----------------------------------------------------------\n");


  printf("lets find a value of your choise the function will retunr the position of u'r elemnt and if the element doent existe it will reurn -1\n");
    scanf("%d",&value);

  printf("-----------------------------------------------------------\n");
  printf("the position of %d is %d \n",value,find(my_fucking_list,value));

  printf("-----------------------------------------------------------\n");
  printf("-----------------------------------------------------------\n");

  printf("Lest instert some nodes : \n");
  insertAtPosition(my_fucking_list,1,1);

  insertAtPosition(my_fucking_list,2,2);
  insertAtPosition(my_fucking_list,3,3);
  insertAtPosition(my_fucking_list,4,4);
  show_List(my_fucking_list);

  Delte_in_posi(my_fucking_list,2);
  show_List(my_fucking_list);

  free_it_the_fuck_out(my_fucking_list);

  return EXIT_SUCCESS;
}


