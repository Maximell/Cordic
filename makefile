main:
	gcc -o Cordic cordic_float.c -lm

clean:
	rm *.o
	rm Cordic
