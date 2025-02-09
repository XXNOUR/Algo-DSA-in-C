#include <stdio.h>
#include <stdlib.h>
void lire(int T[],int N){
  for (int i=0;i<N;i++) {
     printf("T[%d]\n",i);
      scanf("%d",&T[i]);
  }
    }
void show(int T[],int N){
  for (int i=0;i<N;i++) {
   printf("T[%d]=%d\n",i,T[i]);
  }
}
int max(int T[],int N){
  int max=T[0];
 for (int i=1;i<N;i++) {
 if (T[i]>max)
    max=T[i];
 }
return max;
}
int reverse(int T[],int N){
int j=N-1;
for (int i=0;i<N/2;i++){
    int temp=T[i]; 
    T[i]=T[j];
    T[j]=temp;
j--;
}
  show(T,N);
  return 0;
}

int main()
{
 int N;
     printf("entre the size of the array \n");
        scanf("%d",&N);
      int T[N];
        lire(T,N);
        show(T,N);
  printf("--------------------------------------------------------------------\n");
      printf("the largest element is %d\n",max(T,N));
  printf("----------------------------------------------------------------------\n");
      reverse(T,N);
   

  return EXIT_SUCCESS;
}

