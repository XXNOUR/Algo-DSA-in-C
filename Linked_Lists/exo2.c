#include <stdio.h>
#include <stdlib.h>

struct Node {
  int val;
  struct Node* link;
};
List head;
typedef struct Node Node;
typedef Node* List;

List Revers_it(List head){
 List curr,prev,nxt;
 curr = head;
  prev = NULL;
  while (curr != NULL) {
    nxt = curr->link
    curr->link = prev;
    prev = curr;
    curr = nxt;
  }
  head = prev;
  return head;
  }
 


int main(int argc, char *argv[])
{

 insert(5);
 insert(4);
 insert(8);
 insert(2);
 insert(1);

  return EXIT_SUCCESS;
}

