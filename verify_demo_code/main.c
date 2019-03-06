#include<stdio.h>
#define ADD_f(n1, n2) add_function(n1, n2)
#define SUB_f(n1, n2) sub_function(n1, n2)
#define FUNCTION(n1, n2, n3) n1##_f(n2,n3);\
                             printf("FUNCTION:"#n1#n2":%d" " "#n3":%d""\n",n2,n3);
                             
int add_function(int a, int b)
{
  int res = 0;
  printf("add_function\n");
  return res;
}

int sub_function(int a, int b) 
{
  int res = 0;
  printf("sub_function\n");
  return res;
}

int main(int argc, char *argv[])
{
  int res = 0;
  int a = 20;
  int b = 20;
  FUNCTION(ADD, a, b);
  FUNCTION(SUB, a, b);
  return res;
}
