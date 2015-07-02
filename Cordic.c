#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
			
	return 0;
}
