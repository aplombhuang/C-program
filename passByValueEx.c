#include <stdio.h>

void swapping (int c, int d) {
	int temp;
	temp = c;
	c = d;
	d = temp;
	printf("In function: %d %d\n", c, d);
}

int main(void)
{
	int a;
	int b;
	a = 5;
	b = 10;
	printf("input: %d %d\n", a, b);
	swapping(a, b);
	printf("input: %d %d\n", a, b);
	return 0;
}
