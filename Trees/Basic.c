#include <stdio.h>
#include <stdlib.h>

struct Node{
  int val;
  struct Node* left;
  struct Node* right;
};
typedef struct Node Node;
typedef Node* tree;



tree New_node(int val){
  tree new_N = (tree)malloc(sizeof(Node));
  if (new_N==NULL) {
    return NULL;
  }
  new_N->val = val;
  new_N->left = NULL;
  new_N->right = NULL;
  return new_N;
}
int isEmpty(tree R){
 if (R == NULL) {
    return 1;
 }
  else {
    return 0;
  }
}
tree get_root(tree R){

  return R;
}
void In_order(tree R){

 if (R==NULL) {
    return ;
 }
  In_order(R->left);
  printf("%d - ",R->val);
  In_order(R->right);
}

void Pre_Order(tree R){
 if (R==NULL) {
   return ;
 }
 
 printf("%d - ",R->val),
 Pre_Order(R->left);
 Pre_Order(R->right);
}
void Post_order(tree R){
 if (R==NULL) {
    return ;
 }
  Post_order(R->left);
  Post_order(R->right);
  printf("%d - ",R->val);
}


tree insert(tree R,int val){
  // IN case the list is empty 
  if (R==NULL) {
    tree New_n = New_node(val);
    return New_n;
  }
  // creating a new node 
 tree new_N = New_node(val);
  // If the tree isn't empty, we need to find where our new value belongs
  // We'll start at the root and keep making decisions:
   while (R->right!=NULL && R->left!=NULL) {
  
   if ((new_N->val) > R->val) {
    R = R->right;
   }
    if ((new_N->val) < R->val)  {
      R = R->left;
    }
}
  if ((new_N->val) > R->val) {
    new_N = R->right;
   }
    if ((new_N->val) < R->val)  {
      new_N = R->left;
    }
  return R;
}
tree find(tree R,int val){
 
  if (R==NULL) {
    return R ;
  }
 if (val==(R->val)) {
    printf("value found \n");
    return R;
 }
  if (val < R->val) {
   return find(R->left,val);
  }
  else if (val > R->val) {
    return find(R->right,val);
  }
}
int Max(int i,int j){
 if (i<j) {
    return j;
 }
 else if (i>j) {
    return i;
 }
 else {
    return i;
 }
}
int hight(tree R){
  if (R==NULL) {
    return -1;
  }
 int left =  hight(R->left);
 int right =  hight(R->right);
 return 1 + Max(left,right);
}



// the right virtion were i used recurtion unstead of intirative vertion 
tree insert_gpt(tree R,int val){
 if (R==NULL) {
    return New_node(val);
 }
  if (val < (R->val) ) {
    R->left = insert_gpt(R->left,val);
  }
  else if (val > (R->val)) {
    R->right = insert_gpt(R->right,val);
  }
  return R;
}
int count_nods(tree R){
 if (R==NULL) {
    return 0;
 }
  int  l = count_nods(R->left);
  int r = count_nods(R->right);
  return 1 + r + l;

}


int main(){
 tree root = New_node(10);
 printf("is this list emptty ?? %d \n",isEmpty(root));
  tree rooty = get_root(root);
  printf("the root value is %d \n",root->val);
 tree Left  = New_node(5);
 tree Right   = New_node(15);
 root->left = Left;
 root->right = Right;
 printf("Left is %d \n",Left->val);
 printf("Right is %d \n",Right->val);
  printf("----------------------\n");
  printf("Pre order   ( Root - Left - Right  ) \n");
  Pre_Order(root);
  printf("-------------------------\n");
  printf("----------------------\n");
  printf("In order   ( left - Root  - Right  ) \n");
   In_order(root);
  printf("-------------------------\n");
 printf("---------------------------------\n");
  printf("Post order (Left - Right - Root) \n");
  Post_order(root);
  printf("-----------------------------\n");
  printf(" after  insering the  3 \n");
  root = insert_gpt(root,3);
  root = insert_gpt(root,16);
  root = insert_gpt(root,77);
  root = insert_gpt(root,78);
  root = insert_gpt(root,68);
  root = insert_gpt(root,8);
  root = insert_gpt(root,100);

  In_order(root);
  find(root,77);
 int h = hight(root);
  printf("hight is %d \n",h);
  int i = count_nods(root);
  printf("number of nods is %d \n",i);
  return 0; }
