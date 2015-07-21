#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// imports for time
#include <sys/times.h>
#include <unistd.h>

#include "defines.h"

clock_t get_time() {
	struct tms time_stuct;
	times(&time_struct);
	return time_struct.tms_utime;
}

int main() {


	return 0;
}
