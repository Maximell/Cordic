all: calc_validator profiler

calc_validator:
	gcc -Wall -std=c99 -o build/calc_validator calc_validator.c

profiler:
	gcc -Wall -std=c99 -o build/profiler profiler.c cordic_implementations/cordic_assembly.s

cordic_float:
	gcc -o Cordic_Float cordic_float.c -lm

clean:
	rm Cordic_Float
	rm build/calc_validator