#define PRECISION 14
#define SHIFT 16
#define FLOAT_SHIFT 65536.0
#define BASE_SHIFT 65536
#define HALF_PI 90
#define SCALE_CONSTANT 1.64676

#define ELEM_SIZE 14

typedef enum {ROTATIONAL, VECTORING} cordic_mode;

/*
 * The values represent arctan(2^-i) and then shifted left by 8 bits in an integer format
 */
const int elem_angle[] = {
	2949120,
	1740967,
	919789,
	466945,

	234379,
	117304,
	58666,
	29335,
	
	14668,
	7334,
	3667,
	1833,
	
	917,
	458
};
