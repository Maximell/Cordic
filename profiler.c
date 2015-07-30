#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// imports for time
#include <sys/times.h>
#include <unistd.h>

#include "define.h"

#include "cordic_implementations/cordic.c"

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
		angles[i] = rand() % HALF_PI;
	}

	int x, y, z;

	check_32_bit();

	// int_cordic
	before_time = get_time();
	for (i=0; i<repetitions; i++) {
		x = values[i];
		y = angles[repetitions-1-i];
		z = angles[i];
		cordic(&x, &y, &z, ROTATIONAL);
	}
	printf("\tcordic\ntime: %f\n\n", (double)(get_time() - before_time) / ticks_per_second);

	return 0;
}
