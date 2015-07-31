#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "define.h"

// cordic implemted with fixed point arithmatic
#include "cordic_implementations/cordic.c"

// arm implementation
#include "cordic_implementations/cordic_assembly.c"

void comparison(char* optimization, int x, int y, int opt_x, int opt_y) {
	printf("\n");
	printf("%s\n", optimization);
	if (x!=opt_x)
		printf("\t\t/// ERROR ///\nx: %d, opt_x: %d\n", x, opt_x);
	else
		printf("x values match.\n");
	if (y!=opt_y)
		printf("\t\t/// ERROR ///\ny: %d, opt_y: %d", y, opt_y);
	else 
		printf("y values match.\n");
	printf("\n");
}

int main(void) {

	if( ! (!(0 & 0x80000000)
			&& !(1 & 0x80000000)
			&& !(100 & 0x80000000)
			&& !!(-1 & 0x80000000)
			&& !!(-100 & 0x80000000))) {
		printf("Your system doesn't use 32 bit integers. Please run on a 32 bit machine.\n");
		return 1;
	}

	printf("cos cordic: %15lf\n\n", cos_cordic(30));
	printf("sin cordic: %15lf\n\n", sin_cordic(45));
	printf("arctan xy cordic: %15lf\n\n", arctan_x_y_cordic(3,4));
	//printf("arctan cordic: %15lf\n\n", arctan_cordic(2));

	int x = 1;
	int y = 0;
	int z = 45;
	cordic(&x, &y, &z, ROTATIONAL);
	printf("normal cordic: %d, %d, %d\n", x, y, z);

	x = 1;
	y = 0;
	z = 45;
	cordic_assembly(&x, &y, &z, (int)ROTATIONAL);
	printf("assembly cordic: %d, %d, %d\n", x, y, z);

	x = 1;
	y = 0;
	z = 45;
	cordic_optimized(&x, &y, &z, ROTATIONAL);
	printf("optimized cordic: %d, %d, %d\n", x, y, z);

	printf("Inline computation Test, should be 5: %d\n", inline_test(1, 4));

	return 0;
}
