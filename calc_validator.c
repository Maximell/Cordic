#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

	// basic
	//
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
