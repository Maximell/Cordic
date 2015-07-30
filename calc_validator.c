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
	//printf("arctan cordic: %15lf\n\n", arctan_cordic(2));

	int x = 1;
	int y = 0;
	int z = 45;
	cordic(&x, &y, &z, ROTATIONAL);
	printf("normal cordic: %d, %d, %d\n", x, y, z);

	x = 1;
	y = 0;
	z = 45;
	cordic_assembly(&x, &y, &z, elem_angle);
	printf("assembly cordic: %d, %d, %d\n", x, y, z);



/*
	int x_test = 500;
	int y_test = 200;
	int z_test = 45;
	int_cordic(&x_test, &y_test, &z_test, LOOKUP2);
	printf("x: %d, y: %d\n\n", x_test, y_test);


	int x_rand = rand() % 10000;
	int y_rand = rand() % 10000;
	int angle_rand = rand() % HALFPI2;

	printf("x_rand: %d, y_rand: %d, angle_rand: %d\n", x_rand, y_rand, angle_rand);

	int x_basic = x_rand;
	int y_basic = y_rand;
	int angle_basic = angle_rand;

	// cordic implemented with integers - these values are assumed to be correct. 
	int_cordic(&x_basic, &y_basic, &angle_basic, LOOKUP2);


	// assembly optimizations

*/

	return 0;
}
