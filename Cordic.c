#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[]) {

	if (argc != 5) {
		printf("Incorrect use. Proper use is: ./Cordic Rotation/Vectoring x,y angle.\n");
		return 0;
	}	
	
	int x_value = atoi(argv[2]);
	int y_value = atoi(argv[3]);
	int angle = atoi(argv[4]);
	int Vectoring = 0;
	int Rotation = 0;

	if (strcmp("Vectoring", argv[1]) == 0) {
		Vectoring = 1;
	} else if(strcmp("Rotation", argv[1]) == 0) {
		Rotation = 1;
	}

	if (Vectoring == 0 && Rotation == 0){
		printf("Need to select either Vectoring or Rotational Mode.\n");
	}

	printf("The program was called with the following parameters:\nX-Value: %d\nY-Value: %d\nAngle: %d\nVectoring Mode: %d\nRotation Mode: %d\n", x_value, y_value, angle, Vectoring, Rotation); 


	if (Rotation == 1) {
		double x_new, y_new;

		x_new = (double)x_value*cos(angle*3.14/180) + (double)y_value*sin(angle*3.14/180);
		y_new = (double)y_value*cos(angle*3.14/180) - (double)x_value*sin(angle*3.14/180);

		printf("The final rotated point is: [%f,%f]\n", x_new, y_new);
		return 0;
	}


	return 0;
}
