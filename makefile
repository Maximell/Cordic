all: calc_validator

calc_validator:
	gcc -Wall -srd=c99 -o build/calc_validator calc_validator.c

cordic_float:
	gcc -o Cordic_Float cordic_float.c -lm

clean:
	rm Cordic_Float
	rm build/calc_validator