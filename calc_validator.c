#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "defines.h"

// cordic implemented with integers
#include "cordic_implementations/int_cordic.c"
// cordic implemented with memory disambiguation
#include "cordic_implementations/int_cordic_disambig.c"
// cordic implemented with local variables
#include "cordic_implementations/int_cordic_local.c"
// cordic implemented with memory disambiguation as well as local variables
#include "cordic_implementations/int_cordic_disambig_local.c"

void comparison(char* optimization, int x, int y, int opt_x, int opt_y) {
	if (x!=opt_x || y!=opt_y) {
		printf("%s\n:", optimization);
		if (x!=x_opt)
			printf("x: %d, opt_x: %d", x, opt_x);
		if (y!=y_opt)
			printf("y: %d, opt_y: %d", y, opt_y);
		printf("\n");
	}
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

	int x_rand = rand() % 10000;
	int y_rand = rand() % 10000;
	int angle_rand = rand() % HALFPI2;

	printf("x_rand: %d, y_rand: %d, angle_rand: %d\n", x_rand, y_rand, angle_rand);

	int x_basic = x_rand;
	int y_basic = y_rand;
	int angle_basic = angle_rand;

	// cordic implemented with integers - these values are assumed to be correct. 
	int_cordic(&x_basic, &y_basic, &angle_basic, LOOKUP2);
	check("just checking basic", 1,2,x_basic,y_basic);

	// cordic implemented with memory alias disambiguation
	int x = x_rand; int y = y_rand; int angle = angle_rand;
	int_cordic_disambig(&x, &y, &angle, LOOKUP2);
	check("int_cordic_disambig", x_basic, y_basic, x, y);

	// cordic implemented with local variables
	x = x_rand; y = y_rand; angle = angle_rand;
	int_cordic_local(&x, &y, &angle, LOOKUP2);
	check("int_cordic_local", x_basic, y_basic, x, y);

	// cordic implemented with local variables and memory alias disambiguation
	x = x_rand; y = y_rand; angle = angle_rand;
	int_cordic_disambig_local(&x, &y, &angle, LOOKUP2);
	check("int_cordic_disambig_local", x_basic, y_basic, x, y);	

	// hardcoded
	//
	// memory alias disambiguation
	//	more eff. calc of sign
	//
	// pipeline
	// 	more eff calc of sign + lookup
	//
	// unroll
	// 	can be done a varying number of times
	//
	// assembly optimizations

	return 0;
}
