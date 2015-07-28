#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// imports for time
#include <sys/times.h>
#include <unistd.h>

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

clock_t get_time() {
	struct tms time_struct;
	times(&time_struct);
	return time_struct.tms_utime;
}

void check_32_bit() {
	if( ! (!(0 & 0x80000000)
            && !(1 & 0x80000000)
            && !(100 & 0x80000000)
            && !!(-1 & 0x80000000)
            && !!(-100 & 0x80000000))) {
        printf("Your platform doesn't support 32 bit integers. You must use a platform that supports 32 bit integers.\n");
        exit(EXIT_FAILURE);
    }
}

int main(void) {

	clock_t before_time;
	int ticks_per_second = sysconf(_SC_CLK_TCK);

	int repetitions = 1000000;

	volatile int i;
	int values[repetitions];
	int angles[repetitions];
	for (i = 0; i < repetitions; i++) {
		values[i] = rand() % 10000;
		angles[i] = rand() % HALFPI2;
	}

	int x, y, z;

	check_32_bit();

	// int_cordic
	before_time = get_time();
	for (i=0; i<repetitions; i++) {
		x = values[i];
		y = angles[repetitions-1-i];
		z = angles[i];
		int_cordic(&x, &y, &z, LOOKUP2);
	}
	printf("\tint_cordic\ntime: %f\n\n", (double)(get_time() - before_time) / ticks_per_second);

	// int_cordic_simp_flow
	before_time = get_time();
	for (i=0; i<repetitions; i++) {
		x = values[i];
		y = angles[repetitions-1-i];
		z = angles[i];
		int_cordic_simp_flow(&x, &y, &z, LOOKUP2);
	}
	printf("\tint_cordic_simp_flow\ntime: %f\n\n", (double)(get_time() - before_time) / ticks_per_second);

	// int_cordic_disambig
	before_time = get_time();
	for (i=0; i<repetitions; i++) {
		x = values[i];
		y = angles[repetitions-1-i];
		z = angles[i];
		int_cordic_disambig(&x, &y, &z, LOOKUP2);
	}
	printf("\tint_cordic_disambig\ntime: %f\n\n", (double)(get_time() - before_time) / ticks_per_second);

	// int_cordic_local
	before_time = get_time();
	for (i=0; i<repetitions; i++) {
		x = values[i];
		y = angles[repetitions-1-i];
		z = angles[i];
		int_cordic_local(&x, &y, &z, LOOKUP2);
	}
	printf("\tint_cordic_local\ntime: %f\n\n", (double)(get_time() - before_time) / ticks_per_second);

	// int_cordic_disambig_local
	before_time = get_time();
	for (i=0; i<repetitions; i++) {
		x = values[i];
		y = angles[repetitions-1-i];
		z = angles[i];
		int_cordic_disambig_local(&x, &y, &z, LOOKUP2);
	}
	printf("\tint_cordic_disambig_local\ntime: %f\n\n", (double)(get_time() - before_time) / ticks_per_second);

	// int_hardcoded
	before_time = get_time();
	for (i=0; i<repetitions; i++) {
		x = values[i];
		y = angles[repetitions-1-i];
		z = angles[i];
		int_hardcoded(&x, &y, &z, LOOKUP2);
	}
	printf("\tint_hardcoded\ntime: %f\n\n", (double)(get_time() - before_time) / ticks_per_second);

	// int_cordic_pipeline
	before_time = get_time();
	for (i=0; i<repetitions; i++) {
		x = values[i];
		y = angles[repetitions-1-i];
		z = angles[i];
		int_cordic_pipeline(&x, &y, &z, LOOKUP2);
	}
	printf("\tint_cordic_pipeline\ntime: %f\n\n", (double)(get_time() - before_time) / ticks_per_second);

	// int_cordic_loop_unroll
	before_time = get_time();
	for (i=0; i<repetitions; i++) {
		x = values[i];
		y = angles[repetitions-1-i];
		z = angles[i];
		int_cordic_loop_unroll(&x, &y, &z, LOOKUP2);
	}
	printf("\tint_cordic_loop_unroll\ntime: %f\n\n", (double)(get_time() - before_time) / ticks_per_second);

	// int_cordic_loop_unroll_7
	before_time = get_time();
	for (i=0; i<repetitions; i++) {
		x = values[i];
		y = angles[repetitions-1-i];
		z = angles[i];
		int_cordic_loop_unroll_7(&x, &y, &z, LOOKUP2);
	}
	printf("\tint_cordic_loop_unroll_7\ntime: %f\n\n", (double)(get_time() - before_time) / ticks_per_second);

	return 0;
}
