main:
	gcc -o Cordic Cordic.c -lm

clean:
	rm *.o
	rm Cordic
