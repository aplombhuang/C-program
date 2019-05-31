#include <stdio.h>

void getGcd(int *num1, int *num2)
{
 int  a = *num1;
 int  b = *num2;

 int n = b;

 while(r!=0)
 {
  b = r;
  r = a%b;
  a = b
 }

}

int main(void)
{
 FILE *ptr_file;
 ptr_file = fopen("chap6_7File.txt","r");
 if(!ptr_file){printf("cant open file"), exit(1);}
  

 int a; int b;
 int *num1 ; int *num2;

 while( fscanf(ptr_file, " %d %d", &a, &b)!=EOF)
 {
 num1 = &a; num2 = &b;

 printf("gcd(%d, %d) = ",a,b);
 getGcd(num1, num2);
 printf("%d\n", b);
 }

 fclose(ptr_file);

 return 0;
}
