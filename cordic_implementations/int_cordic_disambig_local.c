extern inline void int_cordic_disambig_local(int* restrict x, int* restrict y, int* restrict z, const int* restrict lookup) {
	
	int sign, temp;

	int local_x = *x;
	int local_y = *y;
	int local_z = *z;

	for (int i=0; i < PRECISION; i++) {
		
		if (local_z >= 0) {
			sign = 1;
		} else {
			sign = 0;
		}
	
		if (sign) {
			temp = local_x - (local_y >> i);
			local_y = local_y + (local_x >> i);
			local_x = temp;
			local_z = local_z - lookup[i];
		} else {
			temp = local_x + (local_y >> i);
			local_y = local_y - (local_x >> i);
			local_x = temp;
			local_z = local_z + lookup[i];
		}
	}

	*x = local_x;
	*y = local_y;
	*z = local_z;
}

