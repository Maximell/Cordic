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
cmp 1

+replace x,y,x with assembly inlining 

CORDIC:
35 + 14x(63)+1
= 918

CORDIC OPT:
191

Output:

		Cordic Profiler: Seng 440

	cordic

time: 0.850000

	optimized cordic

time: 0.320000

	arm cordic

time: 0.330000

	optimized arm cordic

time: 0.330000





