#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "define.h"

// cordic implemented with integers
#include "cordic_implementations/int_cordic.c"
// cordic implemented with a simplified sign check
#include "cordic_implementations/int_cordic_simp_flow.c"
// cordic implemented with memory disambiguation
#include "cordic_implementations/int_cordic_disambig.c"
// cordic implemented with local variables
#include "cordic_implementations/int_cordic_local.c"
// cordic implemented with memory disambiguation as well as local variables
#include "cordic_implementations/int_cordic_disambig_local.c"
// cordic implemented with hard-coded values
#include "cordic_implementations/int_hardcoded.c"
// cordic implemented with pipelining optimizations
#include "cordic_implementations/int_cordic_pipeline.c"
// cordic implemented with one round of loop unrolling
#include "cordic_implementations/int_cordic_loop_unroll.c"
// cordic implemented with seven rounds of loop unrolling
#include "cordic_implementations/int_cordic_loop_unroll_7.c"

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

	int x_rand = rand() % 10000;
	int y_rand = rand() % 10000;
	int angle_rand = rand() % HALFPI2;

	printf("x_rand: %d, y_rand: %d, angle_rand: %d\n", x_rand, y_rand, angle_rand);

	int x_basic = x_rand;
	int y_basic = y_rand;
	int angle_basic = angle_rand;

	// cordic implemented with integers - these values are assumed to be correct. 
	int_cordic(&x_basic, &y_basic, &angle_basic, LOOKUP2);

	// cordic implemented with simplified sign checking
	int x = x_rand; int y = y_rand; int angle = angle_rand;
	int_cordic_simp_flow(&x, &y, &angle, LOOKUP2);
	comparison("int_cordic_simp_flow", x_basic, y_basic, x, y);

	// cordic implemented with memory alias disambiguation
	x = x_rand; y = y_rand; angle = angle_rand;
	int_cordic_disambig(&x, &y, &angle, LOOKUP2);
	comparison("int_cordic_disambig", x_basic, y_basic, x, y);

	// cordic implemented with local variables
	x = x_rand; y = y_rand; angle = angle_rand;
	int_cordic_local(&x, &y, &angle, LOOKUP2);
	comparison("int_cordic_local", x_basic, y_basic, x, y);

	// cordic implemented with local variables and memory alias disambiguation
	x = x_rand; y = y_rand; angle = angle_rand;
	int_cordic_disambig_local(&x, &y, &angle, LOOKUP2);
	comparison("int_cordic_disambig_local", x_basic, y_basic, x, y);	

	// cordic implemented with hardcoded values
	x = x_rand; y = y_rand; angle = angle_rand;
	int_hardcoded(&x, &y, &angle, LOOKUP2);
	comparison("int_hardcoded", x_basic, y_basic, x, y);	

	// cordic implemented with pipelining optimizations
	x = x_rand; y = y_rand; angle = angle_rand;
	int_cordic_pipeline(&x, &y, &angle, LOOKUP2);
	comparison("int_cordic_pipeline", x_basic, y_basic, x, y);	

	// cordic implemented with one round of loop unrolling
	x = x_rand; y = y_rand; angle = angle_rand;
	int_cordic_loop_unroll(&x, &y, &angle, LOOKUP2);
	comparison("int_cordic_loop_unroll", x_basic, y_basic, x, y);

	// cordic implemented with six rounds of loop unrolling
	x = x_rand; y = y_rand; angle = angle_rand;
	int_cordic_loop_unroll_7(&x, &y, &angle, LOOKUP2);
	comparison("int_cordic_loop_unroll_7", x_basic, y_basic, x, y);


	// assembly optimizations

	return 0;
}
