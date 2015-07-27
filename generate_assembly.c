#include "define.h"
#include "stdio.h"

#include "cordic_implementations/int_cordic.c"

int main(int argc, char *argv[])
{
	int x = 600;
	int y = 600;
	int z = 712;

	int_cordic(&x, &y, &z, LOOKUP2);

	printf("value: %d",z);

	return 0;
}
