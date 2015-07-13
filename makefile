main:
	gcc -o Cordic_Float cordic_float.c -lm

clean:
	rm *.o
	rm Cordic_Float
