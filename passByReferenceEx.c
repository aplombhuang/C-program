#include <stdio.h>

void swapping (int *ptr_c, int *ptr_d) {
	int temp;
	temp = *ptr_c;
	*ptr_c = *ptr_d;
	*ptr_d = temp;
	printf("In function: %d %d\n", *ptr_c, *ptr_d);
}

int main(void)
{
	int a;
	int b;
	a = 5;
	b = 10;
	printf("input: %d %d\n", a, b);
	swapping(&a, &b);
	printf("input: %d %d\n", a, b);
	return 0;
}
