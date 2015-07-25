extern inline void int_cordic_loop_unroll(int* restrict x, int* restrict y, int* restrict z, const int* restrict lookup) {

	int x_next, y_next, z_next;
	int x_local, y_local, z_local;
	int i, j;
	x_local = *x;
	y_local = *y;
	z_local = *z;

	i = 0;
	j = 1;

	for(; i < PRECISION; i+=) 




}