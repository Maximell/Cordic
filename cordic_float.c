#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[]) {

	if (argc != 4 && argc != 3) {
		printf("Incorrect use. Proper use is: \nFor Rotation mode: ./Cordic x y angle\nFor Vectoring mode: ./Cordic x y\n");
		return 0;
	}	

	int x_value = atoi(argv[1]);
	int y_value = atoi(argv[2]);
	int Vectoring = 0;
	int Rotation = 0;
	int angle = 0;

	if (argc == 4) {
		Rotation = 1;
		angle = atoi(argv[3]);
		printf("The program was called in Rotational mode with the following parameters:\nX-Value: %d\nY-Value: %d\nAngle: %d\n", x_value, y_value, angle);
	}
	if (argc == 3) {
		Vectoring = 1;
		printf("The program was called in Vectoring mode with the following parameters:\nX-Value: %d\nY-Value: %d\n", x_value, y_value);
	}

	if (Rotation == 1) {
		double x_new, y_new;

		x_new = (double)x_value*cos(angle*M_PI/180) + (double)y_value*sin(angle*M_PI/180);
		y_new = (double)y_value*cos(angle*M_PI/180) - (double)x_value*sin(angle*M_PI/180);

		printf("The final rotated point is: [%f,%f]\n", x_new, y_new);
		return 0;
	}

	if (Vectoring == 1) {
		double new_angle, length;

		length = sqrt(x_value*x_value + y_value*y_value);
		new_angle = atan((double)y_value/(double)x_value)*180/M_PI;

		printf("The vector was %f long, and needed ot be rotated %f degrees.\n", length, new_angle);
		return 0;
	}

	return 0;
}
