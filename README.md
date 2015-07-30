 Cordic
Implementation of the Cordic algorithm 

Versions of the code to be implemented and tested
	-float
	-int
	-int hardcoded
	-int memory alias disambiguation
		-more efficient calc of sign
	-int pipe
		-again, more efficient calc of sign+lookup
	-int unroll
		-can be done once or twice
	-assembly optimizationsi

To create assembly from generate_assembly.c:
	arm-linux-gcc -Wall -std=c99 -S -c generate_assembly.c
	
mul 5
add 1
shift 1
div 15
mem 5
jump 1

+replace x,y,x with assembly inlining 