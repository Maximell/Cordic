#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define NUM_ELEMENTS 14

void iterationComputations(float* x_value, float* y_value, float* angle, float theta, float shift) {
	
	// Determine whether to add or subtract
	int mew = *angle >= 0.0 ? 1.0 : -1.0;

	// Compute
	float temp = *x_value;

	*x_value = *x_value - ((mew) * (*y_value) * (shift));
	*y_value = *y_value + ((mew) * (temp) * (shift));
	*angle = *angle - ((mew) * (theta));
}

int main(int argc, char* argv[]) {

	if (argc != 4 && argc != 3) {
		printf("Incorrect use. Proper use is: \n./Cordic 'X-value' 'Y-value' 'angle (degrees)'\n");
		return 0;
	}	

	float x_value = atoi(argv[1]);
	float y_value = atoi(argv[2]);
	float angle = atoi(argv[3]);

	printf("Cordic was called with the following values:\nX-Value: %f\nY-value: %f\nAngle: %f\n\n", x_value, y_value, angle);

	// Lookup tables
	float circularLookup[NUM_ELEMENTS] = {45, 26.56505, 14.03624, 7.12502, 3.57633, 1.78991, 0.89517, 0.44761, 0.22381, 0.11191, 0.055953, 0.027976, 0.0139882, 0.00699411};
	float powLookup[NUM_ELEMENTS] = {1, 0.5, 0.25, 0.125, 0.0625, 0.03125, 0.015625, 0.0078125, 0.003090625, 0.001953125, 0.0009765625, 0.00048828125, 0.00024414062, 0.00012207031};

	// Main loop - determines precision
	for (int i=0; i<NUM_ELEMENTS; i++) {
		iterationComputations(&x_value, &y_value, &angle, circularLookup[i], powLookup[i]);
	}

	x_value = x_value*0.607252;
	y_value = y_value*0.607252;

	printf("Final X-Value: %f\nFinal Y-Value: %f\nFinal Angle: %f\n", x_value, y_value, angle);

	return 0;
}
